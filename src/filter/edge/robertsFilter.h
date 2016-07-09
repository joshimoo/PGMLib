/**
 * Roberts Filter
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#ifndef ROBERTSFILTER_H
#define ROBERTSFILTER_H

#include "../filter.h"
#include "../../pgm/pgm.h"

/* default sobel kernels */
extern const pgm_t defaultRobertsXKernel;
extern const pgm_t defaultRobertsYKernel;

/* function prototypes */
pgm_t *robertsXFilter(const pgm_t *pgm);
pgm_t *robertsYFilter(const pgm_t *pgm);

#endif
