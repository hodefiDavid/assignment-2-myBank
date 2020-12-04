//
// Created by david on 11/24/20.
//

#ifndef UNTITLED3_MYBANK_H
#define UNTITLED3_MYBANK_H
long down (double x);
double roundD(double num);
int checkIfTheAccountOpen(int account_number);
int initialize();
int addAccount(double initialDeposit);
int balanceCheck(int account_number);
int deposit(int account_number, double _deposit);
int withdrawal(int account_number, double cashToWithdraw);
int AccountClosing(int account_number);
int interest(double precent);
int PrintAccountsInfo();
int closeAll();
#endif //UNTITLED3_MYBANK_H
