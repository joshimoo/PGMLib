/**
 * Contains Common Filter Functionality
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#ifndef FILTER_H
#define FILTER_H

#include "../pgm/pgm.h"
#include <limits.h>

/* rank function pointer */
typedef double (*selection_func)(double *buf, const unsigned int count);

/* function prototypes */
pgm_t *applyRankOrderFilter(const pgm_t *pgm, selection_func select, const unsigned int size);
pgm_t *applyLinearFilter(const pgm_t *pgm, const pgm_t *kernel);
double getPixel(const pgm_t *pgm, int x, int y);
bool isValidPixel(const pgm_t *pgm, const int x, const int y);
int comparePixels(const void *p1, const void *p2);




#endif
