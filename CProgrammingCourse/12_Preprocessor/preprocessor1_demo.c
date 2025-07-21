/*******************************************************
*                                                     *
* Author        : Sanjeet Prasad                      *
* Email         : sanjeet8.23@gmail.com               *
* Description   : Demonstrates C preprocessor usage   *
*                 including conditional compilation,  *
*                 function-like macros, and integration*
*                 of custom header files. Defines and *
*                 uses a `struct` from the header file,*
*                 with macro-controlled feature flags.*
* Created On    : 12th June 2025                      *
* Compiler      : GCC 14.2.0                          *
* Standard      : C99                                 *
*                                                     *
*******************************************************/


#include<stdio.h>
//calling the header file like this ,this is customized header file created by user 
#include"header.h"

int main(int argc ,char *argv[])
{
   struct student Rakesh = {.name = "Rakesh",.roll = 100};
   printf("Student Rakesh name = %s ,roll = %d\n",Rakesh.name ,Rakesh.roll);
   
   return 0;
}


//1.Function like MACRO -> (A+B) square 
//2.using compilation macro to control to print your name using function fun() print() ,and Function like MACRO -> (A+B) square printf 