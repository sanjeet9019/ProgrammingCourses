/*******************************************************
*                                                      *
* Author        : Sanjeet Prasad                       *
* Email         : sanjeet8.23@gmail.com                *
* Description   : Bank module implementation file.     *
*                 Defines core banking operations such *
*                 as deposit and withdraw, with global *
*                 balance tracking. Designed for use   *
*                 across multiple C files in a modular *
*                 setup (Makefile compatible).         *
* Created On    : 26th June 2025                       *
* Compiler      : GCC 14.2.0                           *
* Standard      : C99                                  *
*                                                     *
*******************************************************/


#include<stdio.h>
#include"bank_module.h"

float balance = 0; //define and iniatize 

void deposit(float amount)  //int balance = 1000;
{
    balance = balance + amount;
	printf("Amount deposit = %0.2f\n",amount);
}	
void withdraw(float amount) //int balance = 700 
{
	if(balance >=amount)
	{
		printf("Amount withdraw = %0.2f\n",amount);
		balance = balance - amount;
	}
	else
	{
		printf("Insufficient balance \n");
	}
}