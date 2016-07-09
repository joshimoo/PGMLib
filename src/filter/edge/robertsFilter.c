/**
 * Roberts Filter
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#include "robertsFilter.h"

/** default roberts x direction kernel */
// FIXME: we currently don't support arbitrary sized kernels, only odd squared kernels.
const pgm_t defaultRobertsXKernel = {
        .width = 2,
        .height = 2,
        .max = 1,
        .data = (double[]) {
                1,  0,
                0, -1
        }
};

/** default roberts y direction kernel */
// FIXME: we currently don't support arbitrary sized kernels, only odd squared kernels.
const pgm_t defaultRobertsYKernel = {
        .width = 2,
        .height = 2,
        .max = 1,
        .data = (double[]) {
                 0,  1,
                -1,  0
        }
};


/**
 * apply the X Roberts Filter kernel
 * FIXME: we currently don't support arbitrary sized kernels, only odd squared kernels.
 */
// pgm_t *robertsXFilter(const pgm_t *pgm) { return applyLinearFilter(pgm, &defaultRobertsXKernel); }

/**
 * apply the Y Roberts Filter kernel
 * FIXME: we currently don't support arbitrary sized kernels, only odd squared kernels.
 */
// pgm_t *robertsYFilter(const pgm_t *pgm) { return applyLinearFilter(pgm, &defaultRobertsYKernel); }