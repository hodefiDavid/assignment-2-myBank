//
// Created by david on 11/24/20.
//

#include <stdio.h>
#include "myBank.h"

#define HASHARR 901
static double accountsInfo[50][2];

long down(double x) {
    long t = (long) x;
    if (t > x)
        return t - 1;
    else
        return t;
}

double roundD(double num) {
    num = num * 100;
    long temp = down(num);
    double num_2 = temp;
    return num_2 / 100;
}

int checkIfTheAccountOpen(int account_number) {
    if (accountsInfo[account_number - HASHARR][1] == 1)
        return 1;
    else return 0;
}

//initialize the accountsInfo
int initialize() {
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 2; j++) {
            accountsInfo[i][j] = 0.0;
        }
    }
    return 0;
}


//Opening an account and saving the initial deposit amount.
//Prints the new account number.
//Opening an account is only possible if there are less than 50
//Open accounts.
int addAccount(double initialDeposit) {
    if (initialDeposit >= 0) {
            for (int i = HASHARR; i < HASHARR + 50; i++) {
                if (!checkIfTheAccountOpen(i)) {
                    initialDeposit = roundD(initialDeposit);
                    accountsInfo[i - HASHARR][0] = initialDeposit;
                    accountsInfo[i - HASHARR][1] = 1.0;
                    printf("New account number is: %d \n", i);
                    return 0;
                }
            }

        printf("sorry you cannot open a new account, the capacity of the bank is full\n");
    }
    else{printf("you cannot deposit a negative amount\n");}
    return -1;
}


//Balance check, receives the account number and prints
//The balance.
//This is only allowed if the account is open.
int balanceCheck(int account_number) {
    if (checkIfTheAccountOpen(account_number)) {
        printf("The balance of account number %d is: %.2lf \n",account_number, accountsInfo[account_number - HASHARR][0]);
        return 0;
    }
    printf("This account is closed \n");
    return -1;
}


//Deposit, receives the account number and prints the
//The new balance.
//This is only allowed if the account is open.
int deposit(int account_number, double _deposit) {
    if (checkIfTheAccountOpen(account_number)) {
        if (_deposit >= 0) {
            _deposit = roundD(_deposit);
            accountsInfo[account_number - HASHARR][0] += _deposit;
            printf("your new balance is %.2lf \n", accountsInfo[account_number - HASHARR][0]);
            return 0;
        }
        printf("you cannot deposit a negative amount \n");
        return -1;
    }
    printf("you cannot deposit in a closed account \n");
    return -2;
}

//Withdrawal, get the account number and print the
//The new balance.
//This is only allowed if the account is open and there are
//Enough cash to withdraw.
int withdrawal(int account_number, double cashToWithdraw) {
    if (checkIfTheAccountOpen(account_number)) {
        if (accountsInfo[account_number - HASHARR][0] >= cashToWithdraw) {
            cashToWithdraw = roundD(cashToWithdraw);
            accountsInfo[account_number - HASHARR][0] -= cashToWithdraw;
            printf("The new balance is: %.2lf \n", accountsInfo[account_number - HASHARR][0]);
            return 0;
        }
        printf("Cannot withdraw more than the balance \n");
        return -1;
    }
    printf("account number %d is closed \n", account_number);
    return -2;
}

//Account closing.
//Only allowed if the account is open.
int AccountClosing(int account_number) {
    if (checkIfTheAccountOpen(account_number)) {
        accountsInfo[account_number - HASHARR][1] = 0.0;
        accountsInfo[account_number - HASHARR][0] = 0.0;

        printf("Your account has been closed \n");
        return 0;
    }
    printf("you cannot close your account because is already closed \n");
    return -1;
}

//Adding interest at a given percentage rate to all the open accounts
int interest(double precent) {
    if(precent<100 && precent>-100) {
        for (int i = 0; i < 50; ++i) {
            if (checkIfTheAccountOpen(HASHARR + i)) {
                double temp = roundD(accountsInfo[i][0] * ((100 + precent) / 100));
                accountsInfo[i][0] = temp;
            }
        }
        return 0;
    }
    else printf("the given interest should be between 100 and -100 but the given interest is(%.2lf)\n", precent);
    return -1;

}

//Print all open accounts and the balance in them
int PrintAccountsInfo() {
    for (int i = 0; i < 50; ++i) {
        if (checkIfTheAccountOpen(HASHARR + i)) {
            int tempAccount = i + HASHARR;
            printf("The balance of account number: %d is: %.2lf \n", tempAccount, accountsInfo[i][0]);
        }
    }
    return 0;
}

//Closing all accounts and exiting the program
int closeAll() {
    initialize();
    return 0;
}