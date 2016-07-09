/**
 * Contains Common Filter Functionality
 * TODO: normalize all filter outputs
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#include "filter.h"

/* function prototypes */
double getPixel(const pgm_t *pgm, int x, int y);
double applyConvolution(const pgm_t *pgm, const pgm_t *kernel, const unsigned int x, const unsigned int y);
double applyCorrelation(const pgm_t *pgm, const pgm_t *kernel, const unsigned int x, const unsigned int y);
double applyRankOrder(const pgm_t *pgm, selection_func select, double *window, const unsigned int size, const unsigned int x, const unsigned int y);

/**
 * applys a rankorder filter
 * with a user passed selection function
 */
pgm_t *applyRankOrderFilter(const pgm_t *pgm, selection_func select, const unsigned int size) {

    /* create output */
    pgm_t *dst = createPGM(pgm->width, pgm->height, pgm->max);
    double *window = malloc(size * size * sizeof(*(pgm->data)));

    /* write pgm data */
    for (unsigned int y = 0; y < pgm->height; ++y) {
        for (unsigned int x = 0; x < pgm->width; ++x) {

            /* apply kernel to output pixel */
            double *elem = &(dst->data)[y * dst->width + x];
            *elem = applyRankOrder(pgm, select, window, size, x, y);
        }
    }

    free(window);
    return dst;
}

/**
 * window needs to be at least size^2
 * x, y need to be valid pixel coordinates
 */
double applyRankOrder(const pgm_t *pgm, selection_func select, double *window, const unsigned int size, const unsigned int x, const unsigned int y) {
    unsigned int validCount = 0;
    int origin = size / 2;
    for (int ky = -origin; ky < origin + 1; ++ky) {
        for (int kx = -origin; kx < origin + 1; ++kx) {
            if(isValidPixel(pgm, x + kx, y + ky)) {
                double pixel = (pgm->data)[(y + ky) * pgm->width + (x + kx)];
                window[validCount++] = pixel;
            }
        }
    }

    // apply the selection fucntion to all valid pixels
    double selection = select(window, validCount);
    return selection;
}


/**
 * returns a pgm of the kernel applied via a 2d convolution on the source pgm
 */
pgm_t *applyLinearFilter(const pgm_t *pgm, const pgm_t *kernel) {

    /* create output */
    pgm_t *dst = createPGM(pgm->width, pgm->height, pgm->max);

    /* write pgm data */
    for (unsigned int y = 0; y < pgm->height; ++y) {
        for (unsigned int x = 0; x < pgm->width; ++x) {

            /* apply kernel to output pixel */
            double *elem = &(dst->data)[y * dst->width + x];
            *elem = applyConvolution(pgm, kernel, x, y);
        }
    }

    return dst;
}

/**
 * TODO: we currently only support square kernels
 * calculate the output value of the kernel applied to this pixel
 * x, y need to be valid pixel coordinates
 *
 * The difference between a correlation and convolution are:
 * - convolution rotates the kernel 180 degrees
 * - convolution is commutative
 * - convolution is associative
 * - correlation is neither of these
 * - for symmetric kernels, the output is the same
 */
double applyConvolution(const pgm_t *pgm, const pgm_t *kernel, const unsigned int x, const unsigned int y) {

    int origin = kernel->width / 2;
    double sum = 0;
    for (int ky = -origin; ky < origin + 1; ++ky) {
        for (int kx = -origin; kx < origin + 1; ++kx) {
            // convolution requires us to flip the kernel 180 degrees
            // but we can do this in place by calculating the flipped indexes
            // origin - ky: 2,1,0 origin - kx: 2,1,0
            // y + ky: 0,1,2      x + kx: 0,1,2
            // we apply our kernel forward, while reading it's values in reverse
            double pixelWeight = (kernel->data)[(origin - ky) * kernel->width + (origin - kx)];
            double pixel = getPixel(pgm, x + kx, y + ky);
            sum += pixel * pixelWeight;
        }
    }

    return sum / kernel->max;
}


/**
 * TODO: we currently only support square kernels
 * calculate the output value of the kernel applied to this pixel
 * x, y need to be valid pixel coordinates
 *
 * The difference between a correlation and convolution are:
 * - convolution rotates the kernel 180 degrees
 * - convolution is commutative
 * - convolution is associative
 * - correlation is neither of these
 * - for symmetric kernels, the output is the same
 */
double applyCorrelation(const pgm_t *pgm, const pgm_t *kernel, const unsigned int x, const unsigned int y) {

    int origin = kernel->width / 2;
    double sum = 0;
    for (int ky = -origin; ky < origin + 1; ++ky) {
        for (int kx = -origin; kx < origin + 1; ++kx) {
            double pixelWeight = (kernel->data)[(ky + origin) * kernel->width + (kx + origin)];
            double pixel = getPixel(pgm, x + kx, y + ky);
            sum += pixel * pixelWeight;
        }
    }

    return sum / kernel->max;
}


/**
 * TODO: provide overrides that don't do bounds checking, so I don't need todo pointer arithmetic all the time :)
 * TODO: consider adding different Edge Handling method
 * TODO: consider using an enum to use desired Edge Handling method
 * for pixels outside the image, we use the nearest neighbour pixel value
 */
double getPixel(const pgm_t *pgm, int x, int y) {
    if (x < 0) { x = 0; }
    else if(x >= pgm->width) { x = pgm->width - 1; }

    if (y < 0) { y = 0; }
    else if(y >= pgm->height) { y = pgm->height - 1; }

    return (pgm->data)[y * pgm->width + x];
}

/**
 * for non linear filters, we need to make sure that the coordinate is valid
 * since no edge case handling was specified.
 */
bool isValidPixel(const pgm_t *pgm, const int x, const int y) {
    return (x >= 0 && x < pgm->width) && (y >= 0 && y < pgm->height);
}


/**
 * compares two pixels against each other
 * p1 <  p2 => -1
 * p1 >  p2 =>  1
 * p1 == p2 =>  0
 */
int comparePixels(const void *p1, const void *p2) {
    if ((*(double *)p1) < (*(double *)p2)) { return -1; }
    else if ((*(double *)p1) > (*(double *)p2)) { return 1; }
    return 0;
}