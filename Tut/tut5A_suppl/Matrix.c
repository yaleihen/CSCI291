/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define SIZE 5
int prod_array(const int array[], int length);
int main()
{ 
    int size=4; 
    int data[4][4]={{10,20,30,40},{11,21,31,41},{12,22,32,42},{13,23,33,43}};
    for(int row=0;row<size;row++){
       for(int col=0; col<size; col++)
          printf("%d ", data[row][col]);
     printf("\n");
    } 
}