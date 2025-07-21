/*******************************************************
*                                                     *
* Author        : Sanjeet Prasad                      *
* Email         : sanjeet8.23@gmail.com               *
* Description   : Main source file for C Bank Project.*
*                 Calls deposit and withdraw functions*
*                 from the bank module and displays   *
*                 the final balance. This file is     *
*                 designed to be used with bank.c and *
*                 bank.h in a modular setup compiled  *
*                 via Makefile.                       *
* Created On    : 26th June 2025                      *
* Compiler      : GCC 14.2.0                          *
* Standard      : C99                                 *
*                                                     *
*******************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "bank_module.h"

int main(int argc, char *argv[])
{
    // Deposit money to the account
    deposit(1000.0f);

    // Withdraw money from the account
    withdraw(300.0f);

    // Display final balance
    printf("Balance amount = %.2f\n", balance);

    // Indicate build integration
    printf("Compiled using Makefile structure\n");

    return 0;
}


