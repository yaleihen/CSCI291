#include<stdio.h> 
#include <stdbool.h> 
#define SIZE 24
#define nRows 8
#define nCols 3

//** Function Prototypes **//
void print_array(int array[], int length);
void print_matrix(int mat[][nCols], int rows);

//** Main Function **//

int main()
{
int arr[SIZE];
int arr2d[nRows][nCols];
print_array(arr[5], 4);
// print_matrix(arr2d,nRows);
}

//** Defining Functions **//

void print_array(int array[], int length){
   for(int i=0;i<length; i++)
      printf("array[%d]= %d\n", i, array[i]);
}

void print_matrix(int mat[][nCols], int rows){
   for(int i=0;i<rows; i++){
    for(int j=0;j<nCols; j++)
         printf("mat[%d][%d]= %d\n", i,j, mat[i][j]);
    puts("");     
   }     
}

// wdw
