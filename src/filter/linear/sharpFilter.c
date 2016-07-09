/**
 * Sharpening Filter
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#include "sharpFilter.h"

/* define default sharp kernel */
const pgm_t defaultSharpKernel = {
        .width = 3,
        .height = 3,
        .max = 1,
        .data = (double[]) {
                 0, -1,  0,
                -1,  5, -1,
                 0,  -1, 0
        }
};


/**
 * applys the default sharpening kernel
 */
pgm_t *sharpFilter(const pgm_t *pgm) { return applyLinearFilter(pgm, &defaultSharpKernel); }
