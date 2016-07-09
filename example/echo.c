/**
 * Input Output example usage
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#include <stdio.h>
#include <stdlib.h>
#include "../src/pgm/pgm.h"

int main(int argc, char *argv[]) {
    printf("echo example: reads in a src.pgm file and outputs it unchanged\n");
    if (argc < 3) {
        fprintf(stderr, "usage: %s src.pgm out.pgm\n", argv[0]);
        exit(1);
    }

    pgm_t *pgm = readPGMFile(argv[1]);
    writePGMFile(argv[2], pgm);
	
    freePGM(pgm);
    return 0;
}

