/*******************************************************
*                                                     *
* Author        : Sanjeet Prasad                      *
* Email         : sanjeet8.23@gmail.com               *
* Description   : Demonstrates C preprocessor         *
*                 directives including macros,        *
*                 conditional compilation (`#if`,     *
*                 `#ifdef`, `#elif`), function-like   *
*                 macros, and the integration of      *
*                 user-defined header files.          *
*                 Compares runtime functions with     *
*                 compile-time macros for basic ops.  *
* Created On    : 12th June 2025                      *
* Compiler      : GCC 14.2.0                          *
* Standard      : C99                                 *
*                                                     *
*******************************************************/


#include<stdio.h>
//calling the header file like this ,this is customized header file created by user 
#include"header.h"
#include"header.h"

//function is calculated on the run time 
int square(int num)
{
    return (num*num);	
}

int main(int argc ,char *argv[])
{
   #if CODEONOFF
   int student[ARRAYSIZE];
   int num = 5;
   
   #ifdef RUNMACROCODE
   printf("INDEPDENCEYEAR = %d\n",INDEPDENCEYEAR);//int 
   printf("PI = %0.2f\n",PI); //float 
   printf("LEARNINGCOURSE = %s\n",LEARNINGCOURSE); //string 
   printf("ARRAYSIZE = %d\n",ARRAYSIZE); //ARRAYSIZE 
   printf("SOFWAREVER = %0.1f\n",SOFWAREVER); //SOFWAREVER 
 
   #elif defined(NORMALFUN)
   int result = square(num);
   printf("Sqaure of a number using function ,run time = %d\n",result);//int 
   
   #elif defined(MACROLIKEFUNC)
   printf("Sqaure of a number using MACRO ,compile time  SQUARE(%d) = %d\n",num,SQUARE(num)); 
   printf("Cube of a number using MACRO ,compile time  CUBE(%d) = %d\n",num,CUBE(num)); 
   printf("Addition of two number using MACRO ,compile time  ADD(%d,%d) = %d\n",num,num,ADD(num,num)); 
   #endif 
   
   #endif 
   
   return 0;
}


//1.Function like MACRO -> (A+B) square 
//2.using compilation macro to control to print your name using function fun() print() ,and Function like MACRO -> (A+B) square printf 