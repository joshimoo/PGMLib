/**
 * Non Linear Min Filter
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#include "minFilter.h"

/**
 * minimum filter, size defines the search area
 */
pgm_t *minFilter(const pgm_t *pgm, const unsigned int size) {
    return applyRankOrderFilter(pgm, min, size);
}

/**
 * returns the minimum in an array of size count
 */
double min(double* buf, const unsigned int count) {
    double min = LONG_MAX;
    for (int i = 0; i < count; ++i) {
        if(buf[i] < min) { min = buf[i]; }
    }
    return min;
}