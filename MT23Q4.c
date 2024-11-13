#include <stdio.h>

void display_pattern(int depth, int nrows);

int main() {
    display_pattern(4, 6);
}

void display_pattern(int depth, int nrows) {
    int num_stars = 1;
    for (int i = 1; i <= nrows; i++) {
        for (int j = 0; j < depth - num_stars; j++) {
            printf(" ");
        }
        for (int j = 1; j <= num_stars; j++) {
            printf("*");
        }
        printf("\n");
        num_stars++;
        if (num_stars > depth) {
            num_stars = 1;
        }
    }
}
