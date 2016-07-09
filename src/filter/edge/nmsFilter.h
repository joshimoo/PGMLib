/**
 * Non maximum Suppression Filter
 * The filter keeps only maximum, along the gradients direction
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#ifndef NMSFILTER_H
#define NMSFILTER_H

#include "../filter.h"
#include "../../pgm/pgm.h"
#include <math.h>

/* function prototypes */
pgm_t *nonMaximumSuppressionFilter(pgm_t *mag, pgm_t *dir);

#endif
