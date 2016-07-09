/**
 * Gausian Blur Filter
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#include "blurFilter.h"

/** define default 3x3 blur kernel */
const pgm_t default3X3BlurKernel = {
        .width = 3,
        .height = 3,
        .max = 16, /* NOTE: the max will be used, to scale down the values, if you don't want scaling use 1 */
        .data = (double[]) {
                1, 2, 1,
                2, 4, 2,
                1, 2, 1
        }
};

/** define default 5x5 blur kernel */
const pgm_t default5X5BlurKernel = {
        .width = 5,
        .height = 5,
        .max = 115, /* NOTE: the max will be used, to scale down the values, if you don't want scaling use 1 */
        .data = (double[]) {
                2,  4,  5,  4,  2,
                4,  9, 12,  9,  4,
                5, 12, 15, 12,  5,
                4,  9, 12,  9,  4,
                2,  4,  5,  4,  2
        }
};


/**
 * apply the default blurFilter kernel
 */
pgm_t *blurFilter(const pgm_t *pgm) { return applyLinearFilter(pgm, &default3X3BlurKernel); }