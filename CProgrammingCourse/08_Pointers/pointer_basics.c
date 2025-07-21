/*******************************************************
*                                                     *
* Author        : Sanjeet Prasad                      *
* Email         : sanjeet8.23@gmail.com               *
* Description   : Demonstrates pointer concepts in C, *
*                 including declaration, dereferencing,*
*                 pointer arithmetic, NULL and const   *
*                 pointers, and their usage with arrays*
*                 and functions. The program shows how *
*                 pointers interact with data and how  *
*                 values can be modified through memory*
*                 references.                         *
* Created On    : 24th May 2025                       *
* Compiler      : GCC 14.2.0                          *
* Standard      : C99                                 *
*                                                     *
*******************************************************/

#include<stdio.h>

//function declaration step1 
void funcdouble(int *iptr1);//here we pass address ,not value 
void funcdoubwithoutptr(int num1);

//steps 2 
void funcdoubwithoutptr(int num1)
{
   num1= (num1)*2;	
}

//steps 2 
void funcdouble(int *iptr1)//iptr1 = &num1 
{
   *iptr1 = (*iptr1)*2;	//double the number 
}

int main(int argc ,char *argv[])
{
	
	//Integer pointers 
	int num = 10;//4 bytes 
	
	printf("Number = %d\n",num);
	
	printf("Address of Num = 0x%p\n",&num);


    int *iptr = &num;//iptr is a pointer which hold the address of int num ,pointer to an integer(4 bytes)
	printf("Address of Num using pointer variable iptr = 0x%p\n",iptr);
	
	//access of num using pointer variable ,we have to use *iptr
	printf("value of Num using pointer variable iptr = %d\n",*iptr);
	
	*iptr  = 100;//we have update the value inside the iptr address -> num 
	//num = 100;
	
	*iptr  = 1000;
	
	printf("value of Num using pointer variable iptr after update value  = %d\n",*iptr);
	printf("value of Num after update by pointer variable  iptr = %d\n",num);
	
	//Characters pointers 
	char ch = 'A';
	
    printf("ch = %c\n",ch);
	
	printf("Address of ch = 0x%p\n",&ch);


    char *cptr = &ch;//cptr is a pointer which hold the address of char ch ,pointer to an char (1 byte) 
	printf("Address of ch using pointer variable cptr = 0x%p\n",cptr);
	
	//access of ch using pointer variable ,we have to use *cptr
	printf("value of Ch using pointer variable cptr = %c\n",*cptr);
	
		
	//float and double pointers ,thanks Roy for double pointers 
	
	//steps 1 .Pointer is an variable(int,char,float,enum,array) which hold the address of other variable 
	//steps 2 . datatype *ptr = &other; datatype int float etc ,int other ,float other 
	//steps 3 . Getting Address,print %p 
    //steps 4 .Access pointer variable/getting the value , *ptr	
	
	
	int arrnum[] = {1,2,3,4,5};//address 1000,1004,1008,1012,1016
	int size = sizeof(arrnum)/sizeof(int);
	int *iarrptr = &arrnum[0];//address of first element of array 
	
	
	for(int i =0;i<size;i++)
	{
		printf("arrnum[%d] = %d address = %p\n",i,arrnum[i],&arrnum[i]);
		printf("address of arrnum using ptr variable = 0x%p and value of aarnum using  ptr = %d\n",iarrptr,*iarrptr);
		iarrptr = iarrptr + 1; // pointer is int type so it will increase by its datatypes size automatically
	}
	
	//Function passing normal and address 
	int num1 = 10;
	int *iptr1 = &num1; 
	
	funcdoubwithoutptr(num);//here pass the value 
	printf("Value of num1 = %d\n",num1);
	funcdouble(&num1);//here we pass address ,not value   both are same 
	//funcdouble(iptr1);//here we pass address ,not value both are same 
	printf("Value of num1 = %d\n",num1);
	
	
	//NULL pointer ,it means a pointer which does not point to any thing 
	int *ptr = NULL;//NULL = 0 ,int *ptr = &num;
	
	
	//const pointer 
	
	const int a =1000; //constant integer it means we cant change of a 
	printf("Value of a = %d\n",a);
	//a = 2000;//true or false we can do it or not ??
	
	int aa = 99;
	int bb = 88;
	int *const ptra = &aa;//address of aa ->>constant pointer 
	
	printf("Address of aa using pointer variable ptra = 0x%p\n",ptra);
	printf("value of aa using pointer variable ptra = %d\n",*ptra);
	
	//ptra = &bb; //address of bb ,PointersBasic.c:113:14: error: assignment of read-only variable 'ptra',we cant change const
    *ptra = 999;//Yes we can do it because value is not constant 
	printf("value of aa using pointer variable ptra = %d\n",*ptra);
	
	
	const int aaa = 99;
	const int bbb = 88;
	const int *ptraa = &aaa;//address of aa 
	
	printf("Address of aaa using pointer variable ptraa = 0x%p\n",ptraa);
	printf("value of aaa using pointer variable ptraa = %d\n",*ptraa);
	
	ptraa = &bbb; //address we can change but value cannot 
    //*ptraa = 9999;//This is wrong as variable is constant now 
	printf("value of bbb using pointer variable ptraa = %d\n",*ptraa);
	
	
    //const int *const ptr = &aaa;//try yourself here pointer is constant and value is constant 
	
	int *ptr3 = &aaa;
	*ptr3 =  2000;
	
	
	//try for float pointers all category , fun(&float), float *const fptr 
   return 0;
}