#include <stdio.h>
#include <unistd.h>

int main(void) {
    // initialize balance variable and transaction arrays
    int balance = 1000;
    int transactions[11] = {200, -150, -500, -400, 
                            -50, -200, 300, -400, 
                            500, 500, 500};
    int toBeProcessed[11];
    int skipped = 0;
    int breakIndex = -1; // Tracks where the balance reached zero

    // for loop to sequentially read transactions array
    for (int i = 0; i < 11; i++) {
        // skip transaction if it would set the balance below 0
        if (balance + transactions[i] < 0) {
            toBeProcessed[skipped++] = transactions[i];
            printf("WARNING: Negative balance\n"
                   "Skipping transaction...\n");
            sleep(1);
            continue;
        }

        // if transaction sets balance to exactly 0, add to skipped, update balance, and break
        if (balance + transactions[i] == 0) {
            printf("WARNING: Balance close to 0\n"
                   "Skipping subsequent transactions...\n");
            toBeProcessed[skipped++] = transactions[i];
            breakIndex = i; // Store the index where balance reaches zero
            sleep(1);
            for (int j = breakIndex + 1; j < 11; j++) {
                toBeProcessed[skipped++] = transactions[j];
                }
            break;
        }

        // apply valid transaction to balance
        balance += transactions[i];
        // (debug) printf("Balance = %d\n", balance);
        sleep(1);
    }

    // output the final balance and all skipped transactions
    printf("Final Balance = %d\n", balance);
    sleep(1);
    printf("Skipped Transactions:\n");
    for (int i = 0; i < skipped; i++) {
        printf("[%d]: %d\n", i + 1, toBeProcessed[i]);
    }

    return 0;
}
