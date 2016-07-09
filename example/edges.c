/**
 * Canny Filter example usage
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#include <stdio.h>
#include <stdlib.h>
#include "../src/pgm/pgm.h"
#include "../src/filter/edge/cannyFilter.h"

int main(int argc, char *argv[]) {
    printf("edges example: applies a modified canny edge detector on the passed src.pgm file\n");
    if (argc < 3) {
        fprintf(stderr, "usage: %s src.pgm edges.pgm\n", argv[0]);
        exit(1);
    }

    // read in source file
    pgm_t *pgm = readPGMFile(argv[1]);

    // apply canny filter
    pgm_t *cannyOutput = cannyFilter(pgm);
    writePGMFile(argv[2], cannyOutput);
    freePGM(cannyOutput);
	
    freePGM(pgm);
    return 0;
}