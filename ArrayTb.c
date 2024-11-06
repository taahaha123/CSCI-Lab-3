#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define Transactions_amt 1000
#define SIZE 24
#define nRows 8
#define nCols 3

void  process_transactions(int transactions[], int length);
bool withdrawal_Valid(int withdrawal, int balance);
int main() {


}
bool withdrawal_Valid (int withdrawal, int balance) {
    return (balance - withdrawal >= 0);
}
void  process_transactions(int transactions[], int length) {
int balance = Transactions_amt;  // Start with the initial balance of 1000 AED
    int tobeprocessed[SIZE];  // Storing the array for the unprocessed ones
    int tobeprocessed_count = 0;  // Length of the array
    for (int i = 0; i < length; i++) {
        int transaction = transactions[i];
        
        if (transaction < 0) {  // It's a withdrawal
            if (!withdrawal_Valid (transaction, balance)) {
                // If the withdrawal exceeds the current balance, skip it
                printf("Invalid transaction: Withdrawal of %d exceeds current balance.\n", -transaction);
                continue;
            }
        }
        

        