#include <stdio.h>
#include "myBank.h"

int main() {
    int flag = 1;
    int initialize();
        while (flag == 1) {
        char operator;
        int Account_number;
        double temp;
        printf("\nPlease choose a transaction type:\n"
               " O-Open Account\n"
               " B-Balance Inquiry\n"
               " D-Deposit\n"
               " W-Withdrawal\n"
               " C-Close Account\n"
               " I-Interest\n"
               " P-Print\n"
               " E-Exit\n"
               );
        scanf(" %c", &operator);

        switch (operator) {
            case 'O':
                printf("Initial deposit: ");
                if(scanf(" %lf", &temp)==0){
                    printf("Failed to read the amount \n");
                    break;
                }
                addAccount(temp);
                break;

            case 'B':
                printf("Please enter account number: ");
                if(scanf(" %d", &Account_number)==0){
                printf("Failed to read the account number \n");
                break;}
                balanceCheck(Account_number);
                break;

            case 'D':
                printf("Please enter account number: ");
                if(scanf(" %d", &Account_number)==0){
                    printf("Failed to read the account number \n");
                    break;}
                printf("Please enter the amount to deposit: ");
                if(scanf(" %lf", &temp)==0){
                    printf("Failed to read the amount to deposit \n");
                    break;}
                deposit(Account_number,temp);
                break;

            case 'W':
                printf("Please enter account number: ");
                if(scanf(" %d", &Account_number)==0){
                    printf("Failed to read the account number \n");
                    break;}
                printf("Please enter the amount to withdraw: ");
                if(scanf(" %lf", &temp)==0){
                    printf("Failed to read the amount to withdraw \n");
                    break;}
                withdrawal(Account_number,temp);
                break;

            case 'C':
                printf("Please enter account number: ");
                if(scanf(" %d", &Account_number)==0){
                    printf("Failed to read the account number \n");
                    break;}
                AccountClosing(Account_number);
                break;

            case 'I':
                printf("Please enter interest rate: \n");
                if(scanf(" %lf", &temp)==0){
                    printf("Failed to read the interest rate \n");
                    break;}
                interest(temp);
                break;

            case 'P':
                PrintAccountsInfo();
                break;

            case 'E':
                closeAll();
                flag=0;
                break;

            default:
                printf("Invalid transaction type \n");
        }

    }

return 0;
}
