/**
 * Quantization Filter
 * that creates a discrete copy of the passed pgm
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#ifndef QUANTIZEFILTER_H
#define QUANTIZEFILTER_H

#include "../../pgm/pgm.h"
#include "../filter.h"
#include <limits.h>
#include <math.h>

typedef enum quantization {
    TRUNCATE,
    FLOOR,
    ROUND,
    CEIL,
} quantization_t;

#endif
