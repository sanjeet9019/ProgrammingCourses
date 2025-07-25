/*******************************************************
*                                                     *
* Author        : Sanjeet Prasad                      *
* Email         : sanjeet8.23@gmail.com               *
* Description   : Demonstrates common debugging issues*
*                 in C such as NULL pointer access,   *
*                 buffer overflow, array index errors,*
*                 division by zero, dangling pointers,*
*                 recursion base case, and double free*
*                 scenarios. Solutions and fixes are  *
*                 provided alongside commentary.      *
* Created On    : 10th July 2025                      *
* Compiler      : GCC 14.2.0 (with `-g` flag)         *
* Standard      : C99                                 *
*                                                     *
*******************************************************/


#include<stdio.h>
#include <stdlib.h>
#include <string.h>


void fun();
void printnum(int numb);

void fun()
{
    int a = 10;
    int b = 20;	
	int c = a +b;
	printf("result = %d\n",a+b);
}

void printnum(int numb)
{
	if(numb == 0)  //base condition for recursion 
	{
	   return ;
	}
	else
	{	
        printnum(numb -1 );
		printf("num %d\n",numb);
		printf("recursion function printnum\n");
    }		
}


int main(int argc ,char *argv[])
{
  //1.print statement is one way of debugging 
  //how to fix the code ,num100 = 100 code fixed 
  int num100 = 100;
  //what will print 
  fun();
  
  printf("value of num100 = %d\n",num100);
  
  //2 .gdb tool $ gcc -g debugging.c -o debug
  
  
/*   Theory 
    //Compile time 
  int num = 100;
  int *ptr = &num;//address we get here 
  
  //run time 
  int *ptr = (int*)malloc(sizeof(int));//allocate the memory ,int get 4 bytes of memory 
  *ptr = 100; */
  //Segmentation fault -> condition where memory crash or memory leak or memory   
  
  //1.NULL point reference, int *ptr = NULL 
  
  //Fixed the code ,two ways 
  //Compile time 
  printf("Issue 1 NULL point reference, int *ptr = NULL \n");
  int num = 100;
  int *ptr = &num;//address we get here 
  
  printf("Fixed code using compile time memory allocation value of *ptr = %d\n",*ptr);
  
    //run time 
  int *ptr1 = (int*)malloc(sizeof(int));//allocate the memory ,int get 4 bytes of memory 
  
  if(ptr1==NULL)
  {
	return -1;  
  }
  *ptr1 = 100; 
  //Segmentation fault -> condition where memory crash or memory leak or memory   
  printf("Fixed code using run time memory alloc malloc value of *ptr = %d\n",*ptr);
  
  //NULL reference for float *and char * and practice all gdb command which we learn now 
 
  //Array out of index 
  printf("Issue 2 Array out of index \n");
  int number[3] = {1,2,3};
  int size = sizeof(number)/sizeof(int);

  //for(int i = 0;i<=5;i++) bug line 
  //fixed the code  
  for(int i = 0;i<size;i++)   //fixed 
  {
	 printf("number[%d] = %d\n",i,number[i]);  
  }
  
  
  //bug/issue 3 
  printf("Issue 3 divide by 0 \n");
  int div1 = 100;
  int div2 = 10;
  int result = 0;
 
  //division 
  //fixed the code 
  
  if(div2 == 0)
  {	  
     printf("div2 is 0,please make it more than 0 for divide operation \n");
	 return -1;
  }
  else
  {
	 result  = div1/div2;  
  }
  
  printf("divide result = %d\n",result);
  
  
  //Buffer overflow 
  printf("Issue 4 Buffer overflow \n");
  
  char name[10];
  
  //bug code 
  //strcpy(name,"I am a c programmer,i live in india ,twice I am a c programmer,i live in india"); 
  //printf("Name buffer = %s\n",name);
  
  
  //Fixed for buffer overflow 
  
  //1.strncpy
  strncpy(name,"I am a c programmer,i live in india ,twice I am a c programmer,i live in india",sizeof(name) -1);
  name[sizeof(name) -1] = '\0';//NULL terminated 
  printf("Fix1  buffer overflow using strncpy = %s\n",name);
  
  //2.snprintf  prefer fix for buffer overflow case 
  snprintf(name,sizeof(name),"I am a c programmer,i live in india ,twice I am a c programmer,i live in india");
  printf("Fix2  buffer overflow using snprintf = %s\n",name);
  
  int numb = 10;
   //Recursion error ,fix always have base condition in recursion code and use gdb bt command(back trace command) 
  printf("Issue 5 Recursion error\n");
  printnum(numb);
  
  //Use After Free (Dangling Pointer)
  
  printf("Issue 6 Use After Free (Dangling Pointer)\n");
  
  char *cPtr = (char *)malloc(sizeof(char)*1); //same as this array char ptr[1];
  
  if(cPtr == NULL)
  {
	  printf("Malloc fail for char ptr\n");
	  return -1;  
  }
  *cPtr = 'A';
  printf("Value of *cPtr = %c\n",*cPtr);
 //*cPtr = 'C';//right 
  //Wrong way of doing free 
  /*free(cPtr);
  *cPtr = 'B'; //Wrong*/ 
  
  //How to fix the code by free exactly below  
  if(cPtr!=NULL)
  {
	free(cPtr);
    cPtr = NULL;	
  }

 //*cPtr = 'B'; //Wrong segmentation fault as ptr = NULL 
 
   printf("Issue 7 Uninitialized Memory Access\n");
 
   int *pArr = (int *)malloc(sizeof(int)*3); // int pArr[3];
   memset(pArr,0x00,3);
   if(pArr == NULL)
  {
	  printf("Malloc fail for char ptr\n");
	  return -1;  
  }
  pArr[0] = 10;
  //How to fix the code 
  pArr[1] = 20;
  pArr[2] = 30;
  
  printf("Uninitialized Memory Access pArr[2] = %d\n",pArr[2]);
 
  int num1 = 0;
  float pi = 0.0;
  char ch = 0;
  char buff[5];
  //initialize all value with zero not garbage
  memset(buff,0x00,sizeof(buff));
  
  for(int i = 0;i<5;i++)
  {
	printf("value of buff[%d] = %d\n",i,buff[i]);  
  }
  printf("Issue 8 Double free \n");
  float *fptr = (float *)malloc(sizeof(float)*1);
  
   if(fptr == NULL)
  {
	  printf("Malloc fail for char ptr\n");
	  return -1;  
  }
  
  //free(fptr);
  //free(fptr);
  
  //how to fix the code 
  if(fptr!=NULL)
  {
	free(fptr);
    fptr = NULL;	
  }
  printf("Issue 9 Invalid Pointer Arithmetic \n"); // gdb -> b 217
  int arr[5] = {1, 2, 3, 4, 5};// gdb -> b 218
  int size1 = (sizeof(arr)/sizeof(int));
  int *iptr = arr + (size1 -1);
  printf("Size of arr: %ld\n",size1);
  printf("%d\n", *iptr);
  
  return 0;	
}