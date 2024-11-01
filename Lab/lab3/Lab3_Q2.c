#include <stdio.h>
#include <unistd.h>

int main(void){

    // initialize Balance variable and Transaction Arrays
    
    int balance = 1000;
    int transactions[11] = {200, -150, -500, -400, -50, -200, 300, -400, 500, 500, 500};
    int toBeProcessed[11];
    int skipped = 0;
    
    // for loop sequentially reads transactions array

    for (int i = 0; i < 11; i++){
        
        /* breaks loop if upcoming transaction
         * sets balance to 0, skips it too */

        if (balance + transactions[i] == 0){
            printf("Balance is 0\n");
            printf("Skipping subsequent transactions...\n");
            toBeProcessed[skipped] = transactions[i];
            sleep(1);
            skipped++;
            break;
        }

        // skip transaction if it sets balance below 0

        if (balance + transactions[i] < 0){
            // printf("Invalid Transaction\n"); // debug
            toBeProcessed[skipped] = transactions[i];
            skipped++;
            sleep(1);
            continue;
            }
        balance += transactions[i];
        // printf("Balance = %d\n", balance); // debug
    }
    printf("Final Balance = %d\n", balance);
    sleep(1);
    printf("Invalid Transactions:-\n");
    for(int i = 0; i < skipped; i++){
        printf("[%d]: %d\n", i+1, toBeProcessed[i]);
    }
}
