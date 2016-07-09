/**
 * Non Linear Max Filter
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#ifndef MAXFILTER_H
#define MAXFILTER_H

#include "../../pgm/pgm.h"
#include "../filter.h"
#include <limits.h>

/* function prototypes */
pgm_t *maxFilter(const pgm_t *pgm, const unsigned int size);
double max(double* buf, const unsigned int count); /* TODO: consider moving selection function into a separate space */

#endif
