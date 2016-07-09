/**
 * Non maximum Suppression Filter
 * The filter keeps only maximum, along the gradients direction
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#include "nmsFilter.h"

/* local typedef */
typedef enum dir { NS, WE, NWSE, NESW } dir_t;

/* function prototypes */
static dir_t direction(double angle);


pgm_t *nonMaximumSuppressionFilter(pgm_t *mag, pgm_t *dir) {

    pgm_t *nms = createPGM(mag->width, mag->height, mag->max);
    for (unsigned int y = 0; y < mag->height; ++y) {
        for (unsigned int x = 0; x < mag->width; ++x) {
            double angle = getPixel(dir, x, y);
            double n1 = 0;
            double n2 = 0;

            switch (direction(angle)) {
                case NS:
                    n1 = getPixel(mag, x, y - 1);
                    n2 = getPixel(mag, x, y + 1);
                    break;
                case WE:
                    n1 = getPixel(mag, x - 1, y);
                    n2 = getPixel(mag, x + 1, y);
                    break;
                case NWSE:
                    n1 = getPixel(mag, x - 1, y - 1);
                    n2 = getPixel(mag, x + 1, y + 1);
                    break;
                case NESW:
                    n1 = getPixel(mag, x + 1, y - 1);
                    n2 = getPixel(mag, x - 1, y + 1);
                    break;
                default:
                    fprintf(stderr, "direction is non existent\n");
                    break;
            }

            // do we need to suppress this pixel?
            double value = getPixel(mag, x, y);
            double *elem = &(nms->data)[y * nms->width + x];
            if (n1 > value || n2 > value) { *elem = 0; }
            else { *elem = value; }
        }
    }

    return nms;
}

static dir_t direction(double angle) {
    dir_t dir = 0;
    if( (angle > 67.5 && angle <= 90) || (angle >= -90 && angle <= -67.5)) {
        dir = NS;
    } else if (angle > -22.5 && angle <= 22.5) {
        dir = WE;
    } else if (angle > 22.5 && angle <= 67.5 ) {
        dir = NWSE;
    } else if (angle > -67.5 && angle <= -22.5) {
        dir = NESW;
    } else {
        fprintf(stderr, "angle: %f is broken\n", angle);
    }

    return dir;
}