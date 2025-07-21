/*******************************************************
*                                                     *
* Author        : Sanjeet Prasad                      *
* Email         : sanjeet8.23@gmail.com               *
* Description   : Header file for Bank operations.    *
*                 Declares global variable `balance`  *
*                 and function prototypes for deposit *
*                 and withdrawal logic. Used in       *
*                 modular banking system with Makefile.*
* Created On    : 26th June 2025                      *
*                                                     *
*******************************************************/

#ifndef BANK_H
#define BANK_H

// Global balance declared as extern (defined in bank.c)
extern float balance;

// Function declarations for bank operations
void deposit(float amount);
void withdraw(float amount);

#endif
