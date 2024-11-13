#include <stdio.h>
int calculator(char operator, int a, int b);
int main() {
    int a,b;
    char operator;
    printf("Enter the operator: ");
    scanf(" %c",&operator);
    printf("Enter the operands: ");
    scanf("%d %d",&a,&b);
    calculator(operator,a,b);
    return 0;
}

int calculator(char operator, int a, int b) {
    switch(operator) {
        case '+':
            printf("%d", a + b);
            break;
        case '-':
            printf("%d", a - b);
            break;
        case '*':
            printf("%d", a * b);
            break;
        default:
            printf("Invalid operator");
    }
    return 0;
}