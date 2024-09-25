#include <stdio.h>

int main(){

  int choice;

  while (1){
  printf("Coffee Maker Interface\n 1. Order coffee\n 2. ADMIN MODE (for operators)\n 0. Exit\n");
  scanf("%d", &choice);

} // end of loop
}

void ordercoffee(){
        int z;
        printf("You will now order coffee!\n\n");
        while(1){
          printf("put 0 otherwise you stay here forever");
          scanf("%d", &z);
          if(z==0)
          break;
}
}