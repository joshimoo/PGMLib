/**
 * Edge Filters
 * provides magnitude and direction filters that can be used for more advanced filters like canny edge detector
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#ifndef EDGEFILTER_H
#define EDGEFILTER_H

#include "../filter.h"
#include "../../pgm/pgm.h"
#include <math.h>

/* define PI if the math.h header does not support it */
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#ifndef M_PI_2
#define M_PI_2		1.57079632679489661923
#endif

#ifndef M_PI_4
#define M_PI_4		0.78539816339744830962
#endif


/* function prototypes */
pgm_t *edgeMagnitudeFilter(const pgm_t *gx, const pgm_t *gy);
pgm_t *edgeDirectionFilter(const pgm_t *gx, const pgm_t *gy);


#endif
