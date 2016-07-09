/**
 * Normalization Filter
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#ifndef NORMALIZEFILTER_H
#define NORMALIZEFILTER_H

#include <math.h>
#include "../filter.h"
#include "../../pgm/pgm.h"

/* function prototypes */
pgm_t *normalizeFilter(const pgm_t *pgm, const double toMin, const double toMax);
double mapRange(double value, double fromMin, double fromMax, double toMin, double toMax);
double normalize(double value, double min, double max);

#endif
