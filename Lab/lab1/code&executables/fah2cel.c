#include <stdio.h>                  // give access to the stdio.h library
#define F2C     (5.0/9)             // definition of fahrenheit to celsius conv. factor
int main(void)
{
    float celsTemp;                 // celsius - variable declaration
    float fahrTemp;                 //  fahrenheit - variable declaration
    printf("Enter the Temperature in Fahrenheit (F): "); // take inputted temperature by user
    scanf("%f", &fahrTemp);        // transform input into fahrTemp variable
    celsTemp = F2C * (fahrTemp - 32); // convert to celsius
    printf("Celsius Temperature = %.1f" , celsTemp); // prints the converted temperature
    return 0;                       // prints code=0 in shell when script runs successfully
}