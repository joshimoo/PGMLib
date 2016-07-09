/**
 * Blur Filter example usage
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#include <stdio.h>
#include <stdlib.h>
#include "../src/pgm/pgm.h"
#include "../src/filter/linear/blurFilter.h"

int main(int argc, char *argv[]) {
	printf("blur example: applies a default 3x3 gausian blur kernel on the passed src.pgm file\n");
    if (argc < 3) {
        fprintf(stderr, "usage: %s src.pgm blur.pgm\n", argv[0]);
        exit(1);
    }

    // read in source file
    pgm_t *pgm = readPGMFile(argv[1]);

    // apply blur filter
    pgm_t *blurOutput = blurFilter(pgm);
    writePGMFile(argv[2], blurOutput);
    freePGM(blurOutput);
	
    freePGM(pgm);
    return 0;
}

