/**
 * Non Linear Min Filter
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#ifndef MINFILTER_H
#define MINFILTER_H

#include "../../pgm/pgm.h"
#include "../filter.h"
#include <limits.h>

/* function prototypes */
pgm_t *minFilter(const pgm_t *pgm, const unsigned int size);
double min(double* buf, const unsigned int count); /* TODO: consider moving selection function into a separate space */

#endif
