/**
 * PGM Handler
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#include <math.h>
#include "pgm.h"


/** local function prototypes */
static bool readPGMHeader(const FILE *fp, pgm_t *pgm);
static bool readPGMData(const FILE *fp, pgm_t *pgm);

pgm_t *createPGM(const unsigned int width, const unsigned int height, const double max) {

    pgm_t *pgm = malloc(sizeof(pgm_t));
    if (pgm == NULL) {
        fprintf(stderr, "cannot allocate space for pgm structure\n");
        return NULL;
    }

    /* apply params */
    pgm->width = width;
    pgm->height = height;
    pgm->max = max;

    unsigned int bytes = pgm->height * pgm->width * sizeof(*(pgm->data));
    pgm->data = malloc(bytes);
    if (pgm->data == NULL) {
        fprintf(stderr, "cannot allocate space for pgm data\n");
        return false;
    }

    return pgm;
}


bool writePGMFile(const char *filename, const pgm_t *pgm) {

    FILE* dst = fopen(filename, "w");
    if (dst == NULL) {
        fprintf(stderr, "could not open %s\n", filename);
        return false;
    }

    if (pgm == NULL) {
        fprintf(stderr, "pgm is not valid\n");
        return false;
    }

    /* write magic value */
    fprintf(dst, "P2\n");

    /* write pgm comment */
    fprintf(dst, "# JMGSSF PGM\n");

    /* write pgm header */
    fprintf(dst, "%u %u\n", pgm->width, pgm->height);

    /* write pgm max */
    fprintf(dst, "%d\n", (int)round(pgm->max));

    /* write pgm data */
    for (int y = 0; y < pgm->height; ++y) {
        for (int x = 0; x < pgm->width; ++x) {
            // project into output range (cutoff values outside [0,255])
            double elem = round((pgm->data)[y * pgm->width + x]);
            int value = (int) (elem > 255 ? 255 : elem < 0 ? 0 : elem);
            fprintf(dst, "%d", value);
            if(x == pgm->width - 1) { fprintf(dst, "\n"); }
            else { fprintf(dst, " "); }
        }
    }

    fclose(dst);
    return true;
}


pgm_t* readPGMFile(const char *filename) {

    FILE* src = fopen(filename, "r");
    if (src == NULL) {
        fprintf(stderr, "could not open %s\n", filename);
        return NULL;
    }

    pgm_t *pgm = malloc(sizeof(pgm_t));
    if (pgm == NULL) {
        fprintf(stderr, "cannot allocate space for pgm structure\n");
        return NULL;
    }

    /* set data NULL to protect against freeing random memory */
    pgm->data = NULL;

    if (!readPGMHeader(src, pgm)) {
        freePGM(pgm);
        fclose(src);
        return NULL;
    }
    if (!readPGMData(src, pgm)) {
        freePGM(pgm);
        fclose(src);
        return NULL;
    }

    fclose(src);
    return pgm;
}


static bool readPGMHeader(const FILE *fp, pgm_t *pgm) {

    /* read pgm header */
    const int MAX_LENGTH = 4096;
    enum states {INIT, P2_FOUND, COMMENTS_IGNORED, WIDTH_HEIGHT_FOUND, MAX_FOUND, ERROR};
    enum states state = INIT;

    char *buf = malloc(sizeof(char) * MAX_LENGTH);
    bool readHeader = true;

    while(readHeader) {
        fgets(buf, MAX_LENGTH, (FILE *) fp);
        switch(state) {
            case INIT:
                if(strncmp(buf,"P2",2) == 0) { state = P2_FOUND; }
                break;
            case P2_FOUND:
                // ignore comments "#"
                if(strncmp(buf,"#",1) == 0) { break; }
            case COMMENTS_IGNORED:
                // Read width and height
                if(sscanf(buf,"%u %u", &pgm->width, &pgm->height) == 2) { state = WIDTH_HEIGHT_FOUND; }
                else { readHeader = false; }
                break;
            case WIDTH_HEIGHT_FOUND:
                // Read max
                if(sscanf(buf,"%lf", &pgm->max) == 1) {
                    if(pgm->max == 0) { fprintf(stderr, "PGM Header: a max value of 0 is not valid\n"); }
                    else { state = MAX_FOUND; }
                }
                readHeader = false;
                break;
            default:
                state = ERROR;
                readHeader = false;
        }
    }

    free(buf);
    if(state != MAX_FOUND) {
        fprintf(stderr, "invalid PGM Header, parser terminated at step %d\n", state);
        return false;
    }

    return true;
}


static bool readPGMData(const FILE *fp, pgm_t *pgm) {

    unsigned int bytes = pgm->height * pgm->width * sizeof(*(pgm->data));
    pgm->data = malloc(bytes);
    if (pgm->data == NULL) {
        fprintf(stderr, "cannot allocate space for pgm data\n");
        return false;
    }

    /* read pixel data, we go for very flexible format
     * ie accept anything that looks remotely like a pgm :)
     * we can currently read in floats/doubles for example, as a valid pgm
     * additionally to regular integer pixel values
     * TODO: make sure to have a write kernel method,
     * TODO: that does conversion from double range via max value into int range */
    double *data = pgm->data;
    for (int y = 0; y < pgm->height; ++y) {
        for (int x = 0; x < pgm->width; ++x) {
            /* throw away leading or following whitespace */
            if(fscanf((FILE *) fp, " %lf ", data++) == 0) {
                fprintf(stderr, "invalid pgm data\n");
                return false;
            }
        }
    }

    return true;
}


void freePGM(pgm_t *pgm) {
    if (pgm != NULL) { free(pgm->data); }
    free(pgm);
}
