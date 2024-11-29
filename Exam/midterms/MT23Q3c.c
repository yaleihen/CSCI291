#include <stdio.h>
#include <stdbool.h>
#include <math.h>
int read_pos_validation();
void skip_line();
bool Is_prime(int a)
{
    bool isPrime = true;

    if (a < 2)
    {
        isPrime = false;
    }
    for (int i = 2; i <= sqrt(a); i++)
    {
        if (a % i == 0)
        {
            isPrime = false;
            break;
        }
    }

    return isPrime;
}

int main()
{
    
    int num = read_pos_validation();
    printf(Is_prime(num) ? "The number is prime\n" : "The number is not prime\n");
}

// Function to read and validate a positive integer input
int read_pos_validation() {
    int num;
    while (1) {
        printf("Enter a positive number: ");
        // Check if the input is a valid integer
        if (scanf("%d", &num) != 1) {
            printf("Invalid input. Please enter a positive integer.\n");
            skip_line(); // Skip the invalid input
            continue;    // Ask for input again
        }

        // Check if the number is positive
        if (num <= 0) {
            printf("Please enter a positive integer.\n");
        } else {
            return num;  // Return the valid positive integer
        }
    }
}


void skip_line(){
#define LINE_SIZE 100
char line [LINE_SIZE];
scanf("%[^\n]s", line);}
