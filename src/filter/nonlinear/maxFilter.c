/**
 * Non Linear Max Filter
 * @author Joshua Moody (joshimoo@hotmail.de)
 */
#include "maxFilter.h"

/**
 * maximum filter, size defines the search area
 */
pgm_t *maxFilter(const pgm_t *pgm, const unsigned int size) {
    return applyRankOrderFilter(pgm, max, size);
}

/**
 * returns the maximum in an array of size count
 */
double max(double* buf, const unsigned int count) {
    double max = LONG_MIN;
    for (int i = 0; i < count; ++i) {
        if(buf[i] > max) { max = buf[i]; }
    }
    return max;
}