/**
 * Gausian Blur Filter
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#ifndef BLUR_H
#define BLUR_H

#include "../filter.h"
#include "../../pgm/pgm.h"

/** default 3x3 gausain blur kernel */
extern const pgm_t default3X3BlurKernel;
extern const pgm_t default5X5BlurKernel;

/* function prototypes */
pgm_t *blurFilter(const pgm_t *pgm);

#endif
