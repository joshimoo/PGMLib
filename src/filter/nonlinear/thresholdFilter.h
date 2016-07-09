/**
 * Threshold Filter
 * that limits the pgm data into the paassed range
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#ifndef THRESHOLDFILTER_H
#define THRESHOLDFILTER_H

#include "../filter.h"
#include "../../pgm/pgm.h"

/* function prototypes */
pgm_t *thresholdFilter(const pgm_t *pgm, const double threshold);
pgm_t *limitFilter(const pgm_t *pgm, const double min, const double max);
pgm_t *binaryFilter(const pgm_t *pgm);

#endif
