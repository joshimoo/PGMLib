/**
 * Sharpening Filter
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#ifndef SHARP_H
#define SHARP_H

#include "../filter.h"
#include "../../pgm/pgm.h"

/* default sharp filter kernel */
/* NOTE: in C consts objects have external linkage vs internal in C++ */
extern const pgm_t defaultSharpKernel;

/* function prototypes */
pgm_t *sharpFilter(const pgm_t *pgm);

#endif
