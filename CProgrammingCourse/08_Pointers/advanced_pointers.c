/***********************************************
* Name - C Programmer(youreemail@gmail.com)    * 
* Description - C Pointers advance             *
* Date 04th June 2025                          *
***********************************************/

#include<stdio.h>

enum datatype
{
	INT,//0 
	CHAR, //1
	FLOAT, //2
};

void printvalue(void *ptr,enum datatype type);
void printhelloworld(void);
int sum(int num1,int num2);
void copynumberwithourestrict(int *ptrnumber99,int *ptrnumber999);
void copynumberwithrestrict(int *restrict ptrnumber99,int *restrict ptrnumber999);


void copynumberwithourestrict(int *ptrnumber99,int *ptrnumber999) //memory overlapping 
{
    *ptrnumber99 = 	*ptrnumber999;  //both the address is pointing to 99 
	printf("copynumberwithourestrict Address of ptrnumber99 = 0x%p and Address of ptrnumber999 = 0x%p\n",ptrnumber99,ptrnumber999);
}

void copynumberwithrestrict(int *restrict ptrnumber99,int *restrict ptrnumber999)
{
    *ptrnumber99 = 	*ptrnumber999;//both the address is pointing to 99 
	printf("copynumberwithrestrict Address of ptrnumber99 = 0x%p and Address of ptrnumber999 = 0x%p\n",ptrnumber99,ptrnumber999);
	
}

void printhelloworld(void)
{
	 printf("printhelloworld ->Hello World\n");
}


int sum(int num1,int num2)
{
    return num1+num2;	
}
//generic programming 
void printvalue(void *ptr,enum datatype type)
{
	switch(type)
	{
	   case INT:
            printf("explicit typecast for void ptr which is holding integer data types add = 0x%p and value = %d\n",(int*)ptr,*(int*)ptr);
	        break ;
	   case CHAR:
          printf("explicit typecast for void ptr which is holding char data types add = 0x%p and value = %c\n",(char*)ptr,*(char*)ptr);
	      break ;
	   case FLOAT:
          printf("explicit typecast for void ptr which is holding integer data types add = 0x%p and value = %0.2f\n",(float*)ptr,*(float*)ptr);
	      break ;
	   default :
	           printf("None of the condition");

	}	
}

int main(int argc ,char *argv[])
{
	/*typecasting 
	
	casting - play role 
	type - datatype (int ,char ,float,...)*/
	
	char ch = 65;// A 1 bytes 
	
	int a = ch; //int bytes 4 bytes , 1byte data type  --> 4 bytes data types implicit
	
	printf("Print the value of int a = %d ,and value of char ch = %d\n",a,ch);
	
	//typecasting happened from char(1 byte) --> integer(4 byte) lower bytes to upper bytes we called implicit typecasting happened 
	
	int a1 = 9999;//4 bytes 
	char ch11 = a1;  //we have converting from 4 bytes to 1 bytes ,255 unsigned number signed -127 to 128 
	
	int num1 = 1;  /* //00000000 00000000 00000000 00000001      Little endian represenation -> intel computer 
	                 0x1003   0x1002        0x1001    0x1000
					 
					 //00000000 00000000 00000000 00000001      Big endian represenation -> IBM computer 
	                 0x1000   0x1001        0x1002  0x1003   */
					 
	char ch1 = (char)num1; //00000000 00000000 00000000 00000001 implicit typecasting 
	
	if(ch1 == 1)
	{
		printf("Computer using little endain way to represent memory \n");
	}
	else
	{
		printf("Computer using big endain way to represent memory \n");
	}
	
	
	int div1 = 13;
	int div2 = 2;

    float result = (float)div1/div2;
    printf("result of div1/div2 = %0.2f\n",(float)div1/div2);//explicit typecasting ,mean you have enter or add (int),(float) yourself
	printf("result of div1/div2 = %0.2f\n",result);//explicit typecasting ,mean you have enter or add (int),(float) yourself
	
	double num3 = 9999; //bytes 8 
	int typecast1 = (int)num3;//explicit typecast you save here 4 bytes 
	
	//please refer AI to find 5 types of implicit and 5 types of explicty typecasting in  C


    int num100 = 100;
	void *ptr ;//it is pointer but it does not have any types 
	ptr = &num100; 
	
	//explicit typecast to get the value of it 
	int *ptr1 = (int*)ptr;
	int value = *(int*)ptr;

	printf("explicit typecast for void ptr which is holding integer data types add = 0x%p and value = %d\n",ptr1,value);
	
	int num10 = 10;
	char chA = 'A';
	float pi = 3.14;
	
	//Explicit typecasting is must in the case of void pointers 
	printvalue(&num10,INT);
	printvalue(&chA,CHAR);
	printvalue(&pi,FLOAT);
	
	//Function pointers 
	printf("The address of function printhelloworld = 0x%p\n",printhelloworld);
	
	
	//create a function pointers 
	void (*funptrprinthelloworld)(void);//funptrprinthelloworld is a function pointer which will holding the address of printhelloworld
	funptrprinthelloworld = printhelloworld;//here you assign the address of printhelloworld into funptrprinthelloworld func pointers 
	
	//Normal function call 
	printf("Func printhelloworld calling normal\n");
	printhelloworld();
	
	//Function pointer function call 
	printf("Func printhelloworld using function pointer\n");
	funptrprinthelloworld();
	
    //create a function pointers 
	int (*ptrfunsum)(int num1,int num2); //ptrfunsum is a func pointer which is taking 2 input num1 and num2 and return int type of value
	ptrfunsum = &sum;
	
    //Normal function call 
	printf("Func sum calling normal\n");
	printf("sum of two number using normal = %d\n",sum(10,20));
	
	//Function pointer function call 
	printf("Func sum using function pointer\n");
	printf("sum of two number using func ptr = %d\n",ptrfunsum(100,200));
	
	//2 int ,1 float and return sum of this as float type and print using normal and with function ptr 
	//input 1 int array of holding 5 number 10,20,30,40,50 return sum of 5 numbers  and print using normal and with function ptr 
	
	
	int number99 = 99;
	int number999 = 999;
	
	copynumberwithourestrict(&number99,&number999);
	copynumberwithrestrict(&number99,&number999);
	
   return 0;
}


/* Theoretical Questions
Why is direct dereferencing of a void * pointer not allowed in C?
How does the restrict keyword optimize memory access in array operations?
How can function pointers be used to switch between multiple functions dynamically?
What is the advantage of using function pointers in a menu-driven program(sum,sub,multiplication)?
How does combining restrict pointers and function pointers improve computational performance?
How does a void * pointer enable generic programming in C?
What happens if a function pointer is not initialized before use?
How does the restrict keyword impact compiler optimizations in multi-threaded applications?
Why are function pointers useful in implementing callback functions?
What is the difference between a normal pointer and a function pointer in C?
Programming Questions
Write a program that uses a void * pointer to store and print an integer, float, and character using explicit typecasting.
Implement an array-copying function in C using both regular and restrict pointers and compare their execution time.
Create a function pointer-based calculator that allows users to choose between addition, subtraction, and multiplication dynamically.
Implement a menu-driven system using an array of function pointers, allowing users to select different actions.
Write a C program that demonstrates storing multiple function pointers in an array and executing them in sequence. */
