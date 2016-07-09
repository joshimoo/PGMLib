/**
 * PGM Handler
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#ifndef PGM_H
#define PGM_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

/* TODO: the orignial standard only supports the range [0-255] as data value */
typedef struct pgm {
    unsigned int width;
    unsigned int height;
    double max;
    double *data; /* TODO: consider storing as 2D array (**data) instead */
} pgm_t;


/* function prototypes */
pgm_t *createPGM(const unsigned int width, const unsigned int height, const double max);
bool writePGMFile(const char *filename, const pgm_t *pgm);
pgm_t* readPGMFile(const char *filename);
void freePGM(pgm_t *pgm);

#endif
