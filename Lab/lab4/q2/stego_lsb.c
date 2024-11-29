// Program to embed and extract a secret image within a cover image
 
/* 4-bit LSB Steganography is implemented through fetching nibbles
 * (4-bits) from two 8-bit pixels, one from the cover image and the
 * other from the secret and combining them to make a stego pixel */
 
/* File processing errors are accounted for, each case is associated 
 * with a specific number, 0 for success, -1 for file opening / memalloc errors */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 512
#define HEIGHT 512

// Function to ignore any comments in .pgm files
void ignoreComments(FILE* dotpgm) {
    int ch;
    char line[100];

    while ((ch = fgetc(dotpgm)) != EOF && isspace(ch))
        ;

    if (ch == '#') {
        fgets(line, sizeof(line), dotpgm);
        ignoreComments(dotpgm);
    } else
        fseek(dotpgm, -1, SEEK_CUR);
}

// Function to read a PGM image in text (ASCII) format.
int readPGMText(const char *filename, unsigned char *pixels, int width, int height) {
    FILE *pgmfile = fopen(filename, "r");
    if (!pgmfile) return -1; // File not found

    char format[3];
    fscanf(pgmfile, "%2s", format);
    if (strcmp(format, "P2") != 0) return -2; // Incorrect format

    ignoreComments(pgmfile);

    int imgWidth, imgHeight, maxGray;
    fscanf(pgmfile, "%d %d %d", &imgWidth, &imgHeight, &maxGray);
    if (imgWidth != width || imgHeight != height) return -3; // Dimension mismatch

    for (int i = 0; i < width * height; i++) {
        fscanf(pgmfile, "%hhu", &pixels[i]);
    }

    fclose(pgmfile);
    return 0;
}

// Function to write a PGM image in ASCII format.
int writePGMText(const char *filename, unsigned char *pixels, int width, int height) {
    FILE *pgmfile = fopen(filename, "w");
    if (!pgmfile) return -1;

    fprintf(pgmfile, "P2\n%d %d\n255\n", width, height);
    for (int i = 0; i < width * height; i++) {
        fprintf(pgmfile, "%d\n", pixels[i]);
    }

    fclose(pgmfile);
    return 0;
}

// Function to write a PGM image in binary format.
int writePGMBinary(const char *filename, unsigned char *pixels, int width, int height) {
    FILE *pgmfile = fopen(filename, "wb");
    if (!pgmfile) return -1;

    fprintf(pgmfile, "P5\n%d %d\n255\n", width, height);
    fwrite(pixels, sizeof(unsigned char), width * height, pgmfile);

    fclose(pgmfile);
    return 0;
}

// Function to embed the secret image using XOR-based 4-bit (nibble) LSB steganography.
void embedLSB(unsigned char *coverPixels, unsigned char *secretPixels, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        unsigned char coverCleared = coverPixels[i] & 0xF0; // Clear 4 LSBs of cover pixel
        unsigned char secretBits = (secretPixels[i] >> 4) & 0x0F; // Extract 4 MSBs of secret pixel
        coverPixels[i] = coverCleared ^ secretBits; // Embed secret in cover using XOR
    }
}

// Function to extract the secret image using XOR-based 4-bit LSB steganography.
void extractLSB(unsigned char *coverPixels, unsigned char *outputPixels, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        unsigned char secretBits = coverPixels[i] & 0x0F; // Extract 4 LSB of cover
        outputPixels[i] = secretBits << 4; // Left-shift to reconstruct secret MSBs
    }
}

int main() {
    unsigned char *coverPixels, *secretPixels, *outputPixels;

    // Allocate memory for images
    coverPixels = (unsigned char *)malloc(WIDTH * HEIGHT);
    secretPixels = (unsigned char *)malloc(WIDTH * HEIGHT);
    outputPixels = (unsigned char *)malloc(WIDTH * HEIGHT);

    if (!coverPixels || !secretPixels || !outputPixels) {
        printf("Memory allocation failed.\n");
        return -1;
    }

    // Read input images
    if (readPGMText("baboon.pgm", coverPixels, WIDTH, HEIGHT) < 0 ||
        readPGMText("farm.pgm", secretPixels, WIDTH, HEIGHT) < 0) {
        printf("Error reading input images.\n");
        free(coverPixels); free(secretPixels); free(outputPixels);
        return -1;
    }

    // Embed secret image
    embedLSB(coverPixels, secretPixels, WIDTH, HEIGHT);
    writePGMBinary("stego_image_bin.pgm", coverPixels, WIDTH, HEIGHT);

    // Extract secret image
    extractLSB(coverPixels, outputPixels, WIDTH, HEIGHT);
    writePGMText("extracted_secret.pgm", outputPixels, WIDTH, HEIGHT);

    // Free allocated memory
    free(coverPixels);
    free(secretPixels);
    free(outputPixels);

    return 0;
}
