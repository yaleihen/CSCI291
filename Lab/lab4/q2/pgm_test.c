#include<stdio.h>
#include<stdlib.h>
void main()
{ 
	int i, j, temp = 0;
	int width = 4, height = 4;
	
	// Suppose the 2D Array to be converted to Image 
	// is as given below 
	int img[10][10] = {
		{255, 0, 255, 0},
		{0, 255, 0, 255},
		{100, 200, 150, 100},
		{50, 150, 200, 0}
	};
	
	// file pointer to store image file
	FILE *pgmfile, *negative_pgmfile;

	// Open an image file
	pgmfile = fopen("img.pgm", "wb");
	
	// Open an negative image file
	negative_pgmfile = fopen("neg_img.pgm", "wb");
	
	fprintf(pgmfile, "P2 \n %d %d \n 255 \n", width, height);
	fprintf(negative_pgmfile, "P2 \n %d %d \n 255 \n", width, height);
	
	// Create PGM image using pixel value
	for(i = 0; i < height; i++) {
		for(j = 0; j < width; j++)
			fprintf(pgmfile, "%d ", img[i][j]);
		fprintf(pgmfile, "\n");
	}
	
	// Create negative PGM image using pixel value
	for(i = 0; i < height; i++) {
		for(j = 0; j < width; j++) 
			fprintf(negative_pgmfile, "%d ", (255 - img[i][j]));
		fprintf(negative_pgmfile, "\n");
	}
	
	fclose(pgmfile);
	fclose(negative_pgmfile);
}
