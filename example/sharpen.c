/**
 * Sharpen Filter example usage
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#include <stdio.h>
#include <stdlib.h>
#include "../src/pgm/pgm.h"
#include "../src/filter/linear/sharpFilter.h"

int main(int argc, char *argv[]) {
    printf("sharpen example: applies a default 3x3 sharpen kernel on the passed src.pgm file\n");
    if (argc < 3) {
        fprintf(stderr, "usage: %s src.pgm sharpen.pgm\n", argv[0]);
        exit(1);
    }

    // read in source file
    pgm_t *pgm = readPGMFile(argv[1]);

    // apply sharp filter
    pgm_t *sharpOutput = sharpFilter(pgm);
    writePGMFile(argv[2], sharpOutput);
    freePGM(sharpOutput);
	
    freePGM(pgm);
    return 0;
}

