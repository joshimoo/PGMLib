/**
 * Prewitt Filter
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#include "prewittFilter.h"

/** default prewitt x direction kernel */
const pgm_t defaultPrewittXKernel = {
        .width = 3,
        .height = 3,
        .max = 1,
        .data = (double[]) {
                -1, 0, 1,
                -1, 0, 1,
                -1, 0, 1
        }
};

/** default prewitt y direction kernel */
const pgm_t defaultPrewittYKernel = {
        .width = 3,
        .height = 3,
        .max = 1,
        .data = (double[]) {
                -1,  -1,  -1,
                 0,   0,   0,
                 1,   1,   1
        }
};


/**
 * apply the X Prewitt Filter kernel
 */
pgm_t *prewittXFilter(const pgm_t *pgm) { return applyLinearFilter(pgm, &defaultPrewittXKernel); }

/**
 * apply the Y Prewitt Filter kernel
 */
pgm_t *prewittYFilter(const pgm_t *pgm) { return applyLinearFilter(pgm, &defaultPrewittYKernel); }