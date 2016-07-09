/**
 * Canny Edge detection Filter
 * The canny filter, is a combination of different filters
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#ifndef CANNY_H
#define CANNY_H

#include "../filter.h"
#include "../../pgm/pgm.h"
#include "sobelFilter.h"
#include "../linear/blurFilter.h"
#include "../linear/normalizeFilter.h"
#include "../nonlinear/thresholdFilter.h"
#include "nmsFilter.h"
#include "edgeFilter.h"
#include <math.h>

/* function prototype */
pgm_t *cannyFilter(const pgm_t *pgm);
pgm_t *cannyFilterTest(const pgm_t *pgm);





#endif
