/**
 * Edge Filters
 * provides magnitude and direction filters that can be used for more advanced filters like canny edge detector
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#include "edgeFilter.h"

/* function prototypes */
static inline double radToAngle(double rad);
static inline double magnitude(const double x, const double y);

/**
 * calculate edge strength (magnitude)
 */
pgm_t *edgeMagnitudeFilter(const pgm_t *gx, const pgm_t *gy) {

    if(gx->width != gy->width || gx->height != gy->height) {
        fprintf(stderr, "gx and gy need to be the same size\n");
        return NULL;
    }

    const unsigned int width = gx->width;
    const unsigned int height = gx->height;

    pgm_t *mag = createPGM(width, height, 255);
    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            double gxVal = (gx->data)[y * width + x];
            double gyVal = (gy->data)[y * width + x];
            double *elem = &(mag->data)[y * width + x];
            *elem = magnitude(gxVal, gyVal);
        }
    }

    return mag;
}

/**
 * calculate edge direction in angles between [-90, 90]
 */
pgm_t *edgeDirectionFilter(const pgm_t *gx, const pgm_t *gy) {

    if(gx->width != gy->width || gx->height != gy->height) {
        fprintf(stderr, "gx and gy need to be the same size\n");
        return NULL;
    }

    const unsigned int width = gx->width;
    const unsigned int height = gx->height;

    pgm_t *dir = createPGM(width, height, 255);
    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            double gxVal = (gx->data)[y * gx->width + x];
            double gyVal = (gy->data)[y * gy->width + x];
            double *elem = &(dir->data)[y * dir->width + x];
            double rad = gxVal == 0 ? (gyVal > 0 ? M_PI_2 : gyVal == 0 ? 0 : -M_PI_2) : atan(gyVal / gxVal);
            *elem = radToAngle(rad);
        }
    }

    return dir;
}

static inline double radToAngle(double rad) {
    return rad * 180 / M_PI;
}

static inline double magnitude(const double x, const double y) {
    return sqrt(x * x + y * y);
    // return fabs(x) + fabs(y); /* fast approximation */
}