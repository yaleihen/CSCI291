#include<stdio.h>               // give access to the stdio.h library
#define C2F     (1.82)          // definition of celsius to fahrenheit conv. factor
int main(void)
{
    float fahrTemp;             // fahrenheit - variable declaration
    float celsTemp;             // celsius - variable declaration
    printf("Enter the Temperature in Celsius (C): "); // take inputted temperature by user
    scanf("%f", &celsTemp);     // transform input into the celsTemp variable
    fahrTemp = C2F * celsTemp + 32; // convert to celsius
    printf("Fahrenheit Temperature = %.1f", fahrTemp); // prints the converted temperature
    return 0;                   // prints code=0 in shell when script runs successfully
}