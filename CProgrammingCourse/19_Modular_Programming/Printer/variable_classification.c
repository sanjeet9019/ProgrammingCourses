/*******************************************************
*                                                     *
* Author        : Sanjeet Prasad                      *
* Email         : sanjeet8.23@gmail.com               *
* Description   : Demonstrates modular programming in *
*                 C, covering variable classification *
*                 based on scope, storage classes,    *
*                 and data types (primitive, derived).*
*                 Showcases local/global/static/extern*
*                 variables, typedefs, structs, unions*
*                 enums, and pointer usage.           *
* Created On    : 26th June 2025                      *
* Compiler      : GCC 14.2.0                          *
* Standard      : C99                                 *
*                                                     *
*******************************************************/


#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "modular_header.h"

//Global scope/global variable 

//here we defined extern variable 
int extnum = 99999;

char *programname = "variable.c";
typedef struct Axis 
{
  int x;	
  int y;
}AXIS;

enum Result
	{
	   PASS,
       FAIL 	   
	};

typedef union data
{
		int num;
		float pi ;
		char name[20];
}DATA ;

//global static variable 
static int funcount = 0;
//1.default is zero 
//2.scope is global ,across all function plus in the same file(variable.c) only)

//global scope 	
void localvariable();
void sum(int num1,int num2);
void log_msg(const char *msg);
void userid_login();
void passwordenter();

void localvariable()
{
    int localvarnum1 = 100;
    int localvarnum2 = 200;
	int num1 = 300;
	printf("localvariable()  localvarnum1 = %d ,localvarnum2 = %d\n",localvarnum1,localvarnum2);
	printf("Access global variable  programname from localvariable() = %s\n",programname);
	sum(20,30);
	printf("localvariable() global static variable which will give function = %d\n",++funcount);
}

void sum(int num1,int num2)
{
	// int num1 ;  //local variable 
	// int num2 ;  //local variable 
     int res = num1 +num2 ;
	 printf("formal parameter int num1 = %d ,int num2 = %d\n",num1,num2);
     printf("Sum of two number = %d\n",res);	 
	 printf("Access global variable  programname from sum() = %s\n",programname);
	 printf("sum() global static variable which will give function = %d\n",++funcount);
}

void log_msg(const char *msg)
{
	static int count = 0;//default is zero ,call only once 
	count++;
	printf("log message = %s ,count = %d\n",msg,count);
	printf("log_msg() global static variable which will give function = %d\n",++funcount);
}


void userid_login()
{
   static int logincount ;//default = 0 
   logincount++;
   printf("static variable User id logincount = %d\n", logincount); 
   printf("userid_login() global static variable which will give function = %d\n",++funcount);
}

void passwordenter()
{
   static int enter = 0;
   if(enter == 0)
   {
	  printf("Enter the password successfully\n");   
	  //something you want to only once 
	  enter = 1; 
	  printf("passwordenter() global static variable which will give function = %d\n",++funcount);
   }
   else
   {
	   printf("Password is alread enter successfully,No need to enter again \n");
   }
	
}

void storageclass()
{
	//1.auto 
    auto int a;	//RAM memory 
	int b; //same as above by default all the variable inside a function(block {}) are local variable or local scope 
	printf("value of storage class = auto int a = %d  address = 0x%p b = %d address = 0x%p\n",a,b ,&a,&b);
	//2 register storage class 
	register int c =5; //it tell compiler to use the CPU register(a sort of memory - 4bytes),it not mandatory that it will get cpu registers
	for (int i = 0;i<c;i++)
	{
		printf("value of i = %d\n",i);
		printf("register int c = %d \n",c );
	}
    //3.Static storage class 
	printf("Static storage class\n");
	log_msg("We are in storage class");
	log_msg("We are learning static variable ");
	log_msg("I am learning variable  ");
	userid_login("Rakesh login");
	userid_login("Roy login");
	userid_login("Simba login");
	passwordenter(); //password successfully
	passwordenter();
	passwordenter();
	printextern();
}



int main(int argc ,char *argv[])
{
    //Variable 
	//1.On the basic of data types 
	//1.1 -> Primitive data types/Basic Data types ->int ,char,bool,float ,double
	int num1 = 100;
	char ch = 'A';
	bool cond = true;
	float pi = 3.14455;  //Upto 7 decimel place
	double sal = 2044.5566777; //Upto 15 decimel place 
	printf("1.On the basic of data types \n");
	printf("1.1 -> Primitive data types/Basic Data types ->int ,char,bool,float ,double\n");
	printf("int num1 = %d ,char ch = %c ,bool cond = %d ,float pi = %0.5f ,double sal = %0.7f\n",num1,ch,cond,pi,sal);
	
    //1.2 -> User defined data types /Derived Data types -> struct, Union,Pointers ,enum,array	
	
	//struct
	AXIS  squarecordinate = { .x = 5,.y = 5};
	//Union
	DATA data = {.name = "Char name"};
	
	//Pointers
	int num100 = 100;
	int *ptr = &num100;//compile time memory allocation 
	
	//enum
	enum Result rakResult = PASS;
	
	//array
	int a[5] = {1,2,3,4,5};
	
	printf("1.2 -> User defined data types /Derived Data types -> struct, Union,Pointers ,enum,array\n");
	printf("struct AXIS  squarecordinate x = %d y = %d\n",squarecordinate.x,squarecordinate.y);
	printf("union data  name = %s , Pointers int *ptr =0x%p   enum Result rakResult = %d\n",data.name,ptr,rakResult);
	printf("Array a[0] = %d a[1] = %d a[2] = %d a[3] = %d a[4] = %d \n",a[0],a[1],a[2],a[3],a[4]);
	
	
	//Variable ->On the basic of Scope 
	//1.local scope -> local variable 
	printf("1.On the basic of Scope \n");
	printf("1.1.Local scope ->local variable  \n");
	localvariable();
	//printf("localvarnum1 = %d \n",localvarnum1); error because localvarnum1 is define in other function or other scope 
	
	//2.Formal Parameters/Variable
	sum(10,20);
	
	//3.Global variables 
	printf("Access global variable  programname from main() = %s\n",programname);
	
	//Variable ->On the basic of storage class  
	//1.auto storage class (automatic )
	printf("1.On the basic of storage 1.auto ,\n");
	storageclass();
	printf("main() global static variable which will give function = %d\n",++funcount);
	
	return 0;
}


//Write a c code to demonstate the use of variable on the basis of Scope 
//1.Local scope or local variable,float ,int 
//2.Global scope or global variable struct ,union 
//3.Formal parameter ,array ,float 