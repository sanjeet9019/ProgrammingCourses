/*******************************************************
*                                                     *
* Author       : Sanjeet Prasad                       *
* Email        : sanjeet8.23@gmail.com                *
* Description  : Demonstrates C primitive datatypes    *
*                including int, float, char, bool      *
* Created On   : 2nd May 2025                         *
* Compiler     : GCC 14.2.0                           *
* Standard     : C99                                  *
*                                                     *
*******************************************************/

#include<stdio.h>
#include <stdbool.h>

#define  PI  3.145
#define  NAME  "CPROGRAM"
#define  APPVERSION  "Appversion002"
#define  APPNAME  "CApp"

int main(int argc ,char *argv[])
{
    //Integer data types 
    int num = 100;
	int weight = 90;
	num = 999;
	int num1 = 1 ; // 4 bytes 
	printf("Value of num = %d\n",num);
	printf("Value of weigt = %d\n",weight);
	
	//Float data types 
    float pi = 3.1453423455;
	printf("Value of PI = %0.15f\n",pi);
	
	double pivalue = 3.1453423455;
	printf("Value of PI = %0.15f\n",pivalue);
	
	//Character data types 
	char firstLetter = 'A';
	char secondLetter = 'B'; // 1 bytes 
	char numOne = '1'; // 1 bytes save 3 bytes =  0= 48,1=49 ,50,51, 
	printf("Value of first = %c\n",firstLetter);
	printf("Value of first letter = %d\n",firstLetter);
	printf("Value of second = %c\n",secondLetter);
	printf("Value of second letter = %d\n",secondLetter);
	printf("Value of ASCII numOne = %d\n",numOne);
	printf("Value of Char numOne = %c\n",numOne);
	
	//Bool datatypes 
	bool isNum = true;//True is always 1 
	bool isChar = false; //False is always 0 
    printf("Value of isNum = %d\n",isNum);
	printf("Value of isChar = %d\n",isChar);
	
	//derived data types -array 
	/*
	int numofstudent = 5;
	int marksEachStudent[5] = {50,60,70,80,90}; //Array 
	int marksEachStudent[0] = 50; //first student ma/rks 
	int marksEachStudent[1] = 60; //second  student marks */
	
	printf("Value of define = %f  %s\n",PI,NAME);
	
	const int employee = 2022;
	//employee = 2025; because this is constant we cant change value of it 
	printf("employee number = %d\n",employee);
	
	//example int 
	
	int a ;
	a = 100;
	
	int b = 100;
	b = 999;
	b = 111111;
	
	return 0;
	
}