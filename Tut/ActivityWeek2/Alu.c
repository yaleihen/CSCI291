

#include <stdio.h>
#include<stdbool.h>

int addition(int a, int b);
int subtraction(int a, int b);
int multiplication(int a, int b);
int division(int a, int b);

int main(void)
{   bool carryOn=true;
    int res;
    int choice;
    int a, b;
    do
    {
    printf(" input your choice, 1: addition,  2: subtraction, 3 multiplication, 4 division\n")  ;  
    scanf("%d", &choice);
    printf(" input your two operands\n")  ;  
    scanf("%d%d", &a, &b);
    switch(choice){
        case 1: res=addition(a,b);break;
        case 2: res=subtraction(a,b);break;
        case 3: res=multiplication(a,b);break;
        case 4: res=division(a,b);
        default: printf("unexpected input \n");
    } 
    printf(" The result is %d\n", res);
    printf(">>> input zero to exit\n") ;
    scanf("%d", &choice);
    if (choice==0) carryOn=false;
    } while(carryOn);
}

int addition(int a, int b){
    int res;
    res = a + b;
    return res;
}

int subtraction(int a, int b){
    int res;
    res = a - b;
    return res;
}

int multiplication(int a, int b){
    int res;
    res = a * b;
    return res;
}

int division(int a, int b){
    int res;
    res = a / b;
    return res;
}