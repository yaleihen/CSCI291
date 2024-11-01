/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int k=1;
int dummy(int k);
int main(void)
{
    printf(" value of k at the start of main() is %d, its location is %p\n ", k, &k);
    int k=2;
    k=dummy(k);
    printf("value of k after the function call is %d, its location is  %p\n ", k, &k);
    {
    int k=4;
    printf("value of k from the main inner block is %d, its location is %p\n ", k, &k);    
    }
   printf("value of k after the Block code  is %d, its location is %p\n ", k, &k);
    return 0;
}
int dummy(int k){
    printf("value of k from the function dummy is %d, its location is  %p\n ", k, &k);
    return k+1;
}