#include <stdio.h>          // include stdio.h library

int main(void)
{
    /*part a*/
    
    int int1;               // integer variable int1
    int int2;               // integer variable int2
    int sum;                // integer variable sum
    printf("Enter first of two integers: "); // prompt user to input integer
    scanf("%d", &int1); // turn input into values for int variables
    printf("Enter second of two integers: ");
    scanf("%d", &int2);
    sum = int1 + int2; // add them up and assign the sum to variable 'sum'
    printf("The sum of the two integers = %d\n", sum); // display the result

    /*part b*/

    float float1;           // float variable float1
    float float2;           // float variable float2
    float product;          // float variable product
    printf("Enter first of two floats: "); // prompt user to input float
    scanf("%f", &float1); // turn input into values for float variables
    printf("Enter second of two floats: ");
    scanf("%f", &float2);
    product = float1 * float2; // multiply them and assign the product to variable 'product'
    printf("The product of the two floats = %.2f\n", product); // display the result in 2 decimal points

    /*part c*/

    char character;         // char variable character
    printf("Enter a character: "); // prompt user to input character
    scanf(" %c", &character); // store character in variable 'character'
    printf("%c%c", character); // print it as output

   return 0;
}