/**
 * Quantization Filter
 * that creates a discrete copy of the passed pgm
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#include "quantizeFilter.h"

pgm_t *quantizeFilter(const pgm_t *pgm, const quantization_t mode) {

    /* create a discrete copy */
    pgm_t *res = createPGM(pgm->width, pgm->height, pgm->max);
    for (unsigned int y = 0; y < pgm->height; ++y) {
        for (unsigned int x = 0; x < pgm->width; ++x) {
            double value = (pgm->data)[y * pgm->width + x];
            double *elem = &(res->data)[y * res->width + x];

            switch(mode) {
                case FLOOR:
                    *elem = floor(value);
                    break;
                case ROUND:
                    *elem = round(value);
                    break;
                case CEIL:
                    *elem = ceil(value);
                    break;
                case TRUNCATE:
                    *elem = trunc(value);
                    break;
            }
        }
    }

    return res;
}