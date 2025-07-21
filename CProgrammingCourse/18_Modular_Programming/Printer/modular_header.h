/*******************************************************
*                                                     *
* Author        : Sanjeet Prasad                      *
* Email         : sanjeet8.23@gmail.com               *
* Description   : Header file for modular C programs. *
*                 Declares the extern global variable *
*                 `extnum` and a function prototype   *
*                 `printextern()` for accessing it.   *
*                 Ensures modularity and safe linkage *
*                 through include guards.             *
* Created On    : 26th June 2025                      *
*                                                     *
*******************************************************/

#ifndef HEADER
#define HEADER

// External global variable declaration
extern int extnum;

// Function prototype to display value of extnum
void printextern();

#endif
