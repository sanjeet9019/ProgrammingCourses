/*******************************************************
*                                                     *
* Author        : Sanjeet Prasad                      *
* Email         : sanjeet8.23@gmail.com               *
* Description   : Custom C header file demonstrating  *
*                 usage of header guards, macros,     *
*                 function-like macros, typedefs,     *
*                 structs, unions, enums, and         *
*                 conditional compilation. Serves     *
*                 as a reusable component for C demos *
*                 involving preprocessor concepts.    *
* Created On    : 12th June 2025                      *
* Compiler      : GCC 14.2.0                          *
* Standard      : C99                                 *
*                                                     *
*******************************************************/


#ifndef HEADER_1 //header guard ,save it to include twice ,better use this 
#define HEADER_1

//#pragma once //this is same header guard ,save it to include twice 

#include<math.h>
//function declaration 
int square(int num);

//MACRO 
//NORMAL MACRO
#define INDEPDENCEYEAR 1947 
#define PI 3.14 
#define LEARNINGCOURSE  "C PROGRAMMING"   //char name[] = "rakesh", char *ptr = "rakesh"  
#define ARRAYSIZE  50

//is there any meaning of these ??
#ifndef ARRAYSIZE
#define ARRAYSIZE  100
#endif 

//FUNCTION LIKE MACRO -> it computate in compile time 
#define SQUARE(X)    (X*X)    //5  --> (5*5)
#define CUBE(X)    (X*X*X)    //5  --> (5*5)
#define ADD(X,Y)    (X+Y)     // (a+b)  (a+b)*(a+b)


//This is required for conditional compilation of C code on run time 
#define RUNMACROCODE
#define MACROLIKEFUNC
#define NORMALFUN

//Condition compilation of source code #if 0 means all line are commented if non zero line are not commented 
#define CODEONOFF  1

//NOT define 
#ifndef SOFWAREVER 
#define SOFWAREVER  1.0
#endif 

//typedef 
typedef unsigned char  unint ;

//struct and union 
struct student 
{
   char name[20];
   int roll;   
};

union studentunion 
{
   char name[20];
   int roll;   
};

//Enum 
enum Traffic
{ 
	RED,
	GREEN,
	YELLOW,
};

//inline function 
//int inline square(int num) { return (num * num) };

#endif 