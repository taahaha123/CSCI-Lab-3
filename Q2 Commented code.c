#include <stdio.h>

#define INITIAL_BALANCE 1000 // Initial balance in AED
#define MAX_TRANSACTIONS 100 // Maximum number of transactions

int main() {
    printf("Initial balance: 1000\n");

    int transactions[] = {200, -150, -500, -400, -50, -200, 300}; // Array of transactions
    int num_transactions = sizeof(transactions) / sizeof(transactions[0]); // Number of transactions
    int balance = INITIAL_BALANCE; // Current balance
    int tobeprocessed[MAX_TRANSACTIONS]; // Array to store unprocessed transactions
    int tobeprocessed_count = 0; // Count of unprocessed transactions

    // Process each transaction
    for (int i = 0; i < num_transactions; i++) {
        int transaction = transactions[i];

        // Check if withdrawal exceeds current balance
        if (transaction < 0 && balance + transaction < 0) {
            printf("Transaction of %d AED is invalid due to insufficient balance.\n", transaction);
            tobeprocessed[tobeprocessed_count++] = transaction; // Store invalid transaction
            continue; // Skip to next transaction
        }

        // Update balance with valid transaction
        balance += transaction;

        // Stop processing if balance reaches 0
        if (balance <= 0) {
            printf("Balance is 0 AED, no further transactions will be processed.\n");
            // Store remaining unprocessed transactions
            for (int j = i + 1; j < num_transactions; j++) {
                tobeprocessed[tobeprocessed_count++] = transactions[j];
            }
            break; // Exit loop
        }
    }

    // Print final balance
    printf("Final balance: %d AED\n", balance);
    // Print unprocessed transactions
    printf("Unprocessed transactions:\n");
    for (int i = 0; i < tobeprocessed_count; i++) {
        printf("%d AED\n", tobeprocessed[i]);
    }

    return 0;
}
