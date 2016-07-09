/**
 * Canny Edge detection Filter
 * The canny filter, is a combination of different filters
 * @author Joshua Moody (joshimoo@hotmail.de)
 */

#include "cannyFilter.h"


/**
 * Simplified canny edge detection filter
 * instead of using histeresis for thresholding, we just use a constant value
 */
pgm_t *cannyFilter(const pgm_t *pgm) {

    /* blur and sobel filters */
    pgm_t *blur = blurFilter(pgm);
    pgm_t *gx = sobelXFilter(blur);
    pgm_t *gy = sobelYFilter(blur);

    /* calculate edge strength (magnitude) */
    pgm_t *mag = edgeMagnitudeFilter(gx, gy);

    /* remove all edges under threshold */
    pgm_t *magFiltered = thresholdFilter(mag, 0.45);

    /* calculate edge direction */
    pgm_t *dir = edgeDirectionFilter(gx, gy);

    /* non-maximum suppression.
     * if you want to make sure that the nms filter does not removes an edge if the value is within [0.0, 1.0)
     * apply a quantizationFilter on the magFiltered before hand.
     */
    pgm_t *nms = nonMaximumSuppressionFilter(magFiltered, dir);

    /* final binary pass */
    pgm_t *bin = binaryFilter(nms);

    /* free intermediate results */
    freePGM(blur);
    freePGM(gx);
    freePGM(gy);
    freePGM(mag);
    freePGM(magFiltered);
    freePGM(dir);
    freePGM(nms);
    return bin;
}


/* TODO: move into own testing space, etc */
#if 0
pgm_t *cannyFilterTest(const pgm_t *pgm) {

    /* blur and sobel filters */
    pgm_t *blur = limitFilter(blurFilter(pgm), 0, 255);
    pgm_t *gx = sobelXFilter(blur);
    pgm_t *gy = sobelYFilter(blur);

    /* calculate edge strength (magnitude) */
    pgm_t *mag = edgeMagnitudeFilter(gx, gy);
    pgm_t *magNormalized = normalizeFilter(mag, 0, 255);
    pgm_t *magTruncated = limitFilter(mag, 0, 255); /* we need to truncate values to range [0,255] to produce pdf output */

    /* remove all edges under threshold */
    pgm_t *magFiltered = thresholdFilter(mag, 0.45);

    /* calculate edge direction */
    pgm_t *dir = edgeDirectionFilter(gx, gy);

    /* non-maximum suppression. */
    pgm_t *nms = nonMaximumSuppressionFilter(magFiltered, dir);

    /* final binary pass */
    pgm_t *bin = binaryFilter(nms);

    // TODO: extract this into a test method, with filename params
    // cleanup the intermediate products
    pgm_t *blurNormalized = normalizeFilter(blur, 0, 255);
    writePGMFile("test\\01-canny-blur-normalized.pgm", blurNormalized);
    freePGM(blurNormalized);
    writePGMFile("test\\01-canny-blur.pgm", blur);
    freePGM(blur);

    pgm_t *gxNormalized = normalizeFilter(gx, 0, 255);
    writePGMFile("test\\02-canny-gx-normalized.pgm", gxNormalized);
    freePGM(gxNormalized);
    writePGMFile("test\\02-canny-gx.pgm", gx);
    freePGM(gx);

    pgm_t *gyNormalized = normalizeFilter(gy, 0, 255);
    writePGMFile("test\\02-canny-gy-normalized.pgm", gyNormalized);
    freePGM(gyNormalized);
    writePGMFile("test\\02-canny-gy.pgm", gy);
    freePGM(gy);

    writePGMFile("test\\03-canny-mag-normalized.pgm", magNormalized);
    freePGM(magNormalized);
    writePGMFile("test\\03-canny-mag-truncated.pgm", magTruncated);
    freePGM(magTruncated);
    writePGMFile("test\\03-canny-mag.pgm", mag);
    freePGM(mag);

    pgm_t *magFilteredNormalized = normalizeFilter(magFiltered, 0, 255);
    writePGMFile("test\\04-canny-magFiltered-normalized.pgm", magFilteredNormalized);
    freePGM(magFilteredNormalized);
    writePGMFile("test\\04-canny-magFiltered.pgm", magFiltered);
    freePGM(magFiltered);

    pgm_t *dirNormalized = normalizeFilter(dir, 0, 255);
    writePGMFile("test\\05-canny-dir-normalized.pgm", dirNormalized);
    freePGM(dirNormalized);
    writePGMFile("test\\05-canny-dir.pgm", dir);
    freePGM(dir);

    pgm_t *nmsNormalized = normalizeFilter(nms, 0, 255);
    writePGMFile("test\\06-canny-nms-normalized.pgm", nmsNormalized);
    freePGM(nmsNormalized);
    writePGMFile("test\\06-canny-nms.pgm", nms);
    freePGM(nms);

    writePGMFile("test\\07-canny-bin.pgm", bin);
    return bin;
}
#endif




