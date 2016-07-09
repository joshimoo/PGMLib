/**
 * Sobel Filter
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#ifndef SOBEL_H
#define SOBEL_H

#include "../filter.h"
#include "../../pgm/pgm.h"

/* default sobel kernels */
extern const pgm_t defaultSobelXKernel;
extern const pgm_t defaultSobelYKernel;

/* function prototypes */
pgm_t *sobelXFilter(const pgm_t *pgm);
pgm_t *sobelYFilter(const pgm_t *pgm);


#endif
