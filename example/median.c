/**
 * Median Filter example usage
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#include <stdio.h>
#include <stdlib.h>
#include "../src/pgm/pgm.h"
#include "../src/filter/nonlinear/medianFilter.h"

int main(int argc, char *argv[]) {
    printf("median example: applies a median filter on the passed src.pgm file\n");
    if (argc < 4) {
        fprintf(stderr, "usage: %s src.pgm median.pgm filterSize\n", argv[0]);
        exit(1);
    }

    // verify filter size
    int filterSize = atoi(argv[3]);
    if (filterSize %2 == 0 || filterSize < 0) {
        fprintf(stderr, "N needs to be a positive odd number\n");
        exit(1);
    }
	
	// read in source file
    pgm_t *pgm = readPGMFile(argv[1]);
	
    // apply median filter
    pgm_t *medianOutput = medianFilter(pgm, (const unsigned int) filterSize);
    writePGMFile(argv[2], medianOutput);
    freePGM(medianOutput);
	
    freePGM(pgm);
    return 0;
}

