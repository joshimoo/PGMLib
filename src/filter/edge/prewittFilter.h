/**
 * Prewitt Filter
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#ifndef PREWITTFILTER_H
#define PREWITTFILTER_H

#include "../filter.h"
#include "../../pgm/pgm.h"

/* default sobel kernels */
extern const pgm_t defaultPrewittXKernel;
extern const pgm_t defaultPrewittYKernel;

/* function prototypes */
pgm_t *prewittXFilter(const pgm_t *pgm);
pgm_t *prewittYFilter(const pgm_t *pgm);


#endif
