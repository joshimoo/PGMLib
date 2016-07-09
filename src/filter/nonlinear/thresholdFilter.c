/**
 * Threshold Filter
 * that limits the pgm data into the paassed range
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#include "thresholdFilter.h"

/**
 * threshold needs to be between [0,1] and is applied to the max value of the pgm
 */
pgm_t *thresholdFilter(const pgm_t *pgm, const double threshold) {

    pgm_t *filtered = createPGM(pgm->width, pgm->height, pgm->max);
    for (unsigned int y = 0; y < pgm->height; ++y) {
        for (unsigned int x = 0; x < pgm->width; ++x) {
            double value = (pgm->data)[y * pgm->width + x];
            double *elem = &(filtered->data)[y * pgm->width + x];
            *elem = value < threshold * pgm->max ? 0 : value;
        }
    }

    return filtered;
}


/**
 * limits the values to the range [min,max] inclusive
 */
pgm_t *limitFilter(const pgm_t *pgm, const double min, const double max) {

    pgm_t *filtered = createPGM(pgm->width, pgm->height, pgm->max);
    for (unsigned int y = 0; y < pgm->height; ++y) {
        for (unsigned int x = 0; x < pgm->width; ++x) {
            double value = (pgm->data)[y * pgm->width + x];
            double *elem = &(filtered->data)[y * pgm->width + x];
            *elem = value < min ? min : value > max ? max : value;
        }
    }

    return filtered;
}



/**
 * everything < 0 becomes 0 everything bigger > 1 becomes 1
 */
pgm_t *binaryFilter(const pgm_t *pgm) {
    pgm_t *bin = createPGM(pgm->width, pgm->height, 1);
    for (unsigned int y = 0; y < pgm->height; ++y) {
        for (unsigned int x = 0; x < pgm->width; ++x) {
            double value = (pgm->data)[y * pgm->width + x];
            double *elem = &(bin->data)[y * bin->width + x];
            *elem = value > 0 ? 1 : 0;
        }
    }

    return bin;
}