/**
 * Normalization Filter
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#include "normalizeFilter.h"

/**
 * threshold needs to be between [0,1] and is applied to the max value of the pgm
 */
pgm_t *normalizeFilter(const pgm_t *pgm, const double toMin, const double toMax) {

    /* find the current image range */
    double min = LONG_MAX;
    double max = LONG_MIN;
    for (unsigned int y = 0; y < pgm->height; ++y) {
        for (unsigned int x = 0; x < pgm->width; ++x) {
            double value = (pgm->data)[y * pgm->width + x];
            if (value > max) { max = value; }
            else if (value < min) { min = value; }
        }
    }

    /* create a normalized copy */
    pgm_t *normalized = createPGM(pgm->width, pgm->height, toMax);
    for (unsigned int y = 0; y < pgm->height; ++y) {
        for (unsigned int x = 0; x < pgm->width; ++x) {
            double value = (pgm->data)[y * pgm->width + x];
            double *elem = &(normalized->data)[y * normalized->width + x];
            *elem = mapRange(value, min, max, 0, 255);
        }
    }

    return normalized;
}

double mapRange(double value, double fromMin, double fromMax, double toMin, double toMax) {
    return (value - fromMin) * (toMax - toMin) / (fromMax - fromMin) + toMin;
}

double normalize(double value, double min, double max) {
    return (value - min) / (max - min);
}
