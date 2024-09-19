#include <stdio.h>

int main(void)
{
    int varint = 9; // initialize integer 'varint' with a value of 9
    
    varint = -varint; // inverts the value from positive to negative
    printf("%d\n", varint);

    varint -= varint; // compound assignment operator, subtracts variable with its own value
    printf("%d\n", varint);

    --varint;       // decrements the value then stores back into variable
    printf("%d\n", varint);

    varint = (varint == varint); // relational operator that prints 1 because the comparison is true
    printf("%d\n", varint);

    return 0;
}