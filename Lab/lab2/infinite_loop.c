#include<stdio.h>

#define coffeebeangrams 8
#define watermocha 30
#define water 39
#define adminpasswd "27341"

int main() {
  int i;

  //infinite loop
  while (1){
    printf(" please input the value of i, 0 to exit> ");
    scanf("%d", &i);
    if(i==0)
        break;  // exit the loop
    else if (i<0)
       {
       printf(" you've inputted a negative value, I am going to skip the rest of the loop and branch back\n");       
       continue;  // skip the rest of the loop and go back to check the loop condition
       }
    else
       printf(" you've inputted the positive value %d\n", i);
  } // end of loop
} // end of main
