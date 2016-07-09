/**
 * Sobel Filter
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#include "sobelFilter.h"

/** default sobel x direction kernel */
const pgm_t defaultSobelXKernel = {
        .width = 3,
        .height = 3,
        .max = 1,
        .data = (double[]) {
                1, 0, -1,
                2, 0, -2,
                1, 0, -1
        }
};

/** default sobel y direction kernel */
const pgm_t defaultSobelYKernel = {
        .width = 3,
        .height = 3,
        .max = 1,
        .data = (double[]) {
                 1,  2,  1,
                 0,  0,  0,
                -1, -2, -1
        }
};


/**
 * apply the X Sobel Filter kernel
 */
pgm_t *sobelXFilter(const pgm_t *pgm) { return applyLinearFilter(pgm, &defaultSobelXKernel); }

/**
 * apply the Y Sobel Filter kernel
 */
pgm_t *sobelYFilter(const pgm_t *pgm) { return applyLinearFilter(pgm, &defaultSobelYKernel); }

