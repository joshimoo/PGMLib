/**
 * Non Linear Median Filter
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#ifndef MEDIANFILTER_H
#define MEDIANFILTER_H

#include "../../pgm/pgm.h"
#include "../filter.h"
#include <limits.h>

/* function prototypes */
pgm_t *medianFilter(const pgm_t *pgm, const unsigned int size);
double median(double* buf, const unsigned int count); /* TODO: consider moving selection function into a separate space */

#endif
