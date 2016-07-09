/**
 * Non Linear Median Filter
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#include "medianFilter.h"

/**
 * median filter, size defines the search area
 */
pgm_t *medianFilter(const pgm_t *pgm, const unsigned int size) {
    return applyRankOrderFilter(pgm, median, size);
}

/**
 * TODO: median could be found in O(n) via quick select
 * returns the median in an array of size count
 */
double median(double* buf, const unsigned int count) {
    double median = 0;
    qsort(buf, count, sizeof(double), comparePixels);
    if (count & 0x01) { median = buf[count / 2]; }
    else { median = (buf[(count / 2) - 1] + buf[(count / 2)]) / 2.0; }
    return median;
}

