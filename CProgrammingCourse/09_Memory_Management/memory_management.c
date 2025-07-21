/*******************************************************
*                                                     *
* Author        : Sanjeet Prasad                      *
* Email         : sanjeet8.23@gmail.com               *
* Description   : Demonstrates memory management in C,*
*                 including dynamic allocation using  *
*                 malloc, calloc, realloc, and free.  *
*                 Explores concepts like memory leaks,*
*                 dangling pointers, pointer safety,  *
*                 and double pointer usage for 2D arrays.*
*                 Also includes practical illustrations*
*                 for handling strings and arrays with *
*                 dynamic memory.                     *
* Created On    : 06th June 2025                      *
* Compiler      : GCC 14.2.0                          *
* Standard      : C99                                 *
*                                                     *
*******************************************************/


#include<stdio.h>
#include<stdlib.h>//dynamic memory allocation malloc()
#include<string.h>

void memoryleak(void);
void danglingpointer(void);

void danglingpointer(void)
{
	char *cPtr = NULL; //always pointer with NULL 	
	cPtr = (char*)malloc(1*sizeof(char));
	
   	int *ptr =  (int*)malloc(1*sizeof(int)); //ptr1 = 1000  int ptr[1]
	if(ptr == NULL)//null == zero means memory allocation failed 
	{
		printf("Malloc memory allocation failed  \n");
		return ;//error condition 
    }
	ptr[0] = 1000;
	printf("dangling pointer\n");
	printf("ptr[0] = %d\n",ptr[0]);
	
	free(ptr);
	//here ptr is become a dangling pointer because after free we have not make it NULL ,still it is pointing to something garbage value  
	printf("after free let try to access this ptr[0] = %d\n",ptr[0]);//giving garbage value 
	ptr = NULL ; //If you access any NULL value pointer ,it will give you Segmentation fault 
	
	//free  this is standard way to make it free ,always NULL ,best way to make it free and make NULL 
	if(ptr!=NULL)
	{
	  free(ptr);
      ptr = NULL; 	  
	}
}

void memoryleak(void)
{
   int numberofelement = 10;
   int num = 5;
   int *ptr = (int*)malloc(numberofelement*sizeof(int));  //exactly same as int ptr[10]//compile or static memory allocation 
   
	if(ptr == NULL)//null == zero means memory allocation failed 
	{
		printf("Malloc memory allocation failed  \n");
		return ;//error condition 
    }
	
	printf("Print multiplication for %d using malloc or dynamic memory\n",num);
	for(int i = 1;i<=10;i++)
	{
		ptr[i-1] = num * i;
	   	printf("%d x %d = %d \n",num,i,ptr[i-1]);
	}
	
	//free(ptr); we dont do this here ,we called in c programming it is case of memory leak 
	//solution always free the memory after use 
	
	int *ptr1 = (int*)malloc(1*sizeof(int)); //ptr1 = 1000
	int *ptr2 = ptr1; //ptr2 = 1000
	free(ptr1); 
	ptr1 = NULL ;
	ptr2 = NULL;
	//ptr2 is also free this is case of memory leak 
	
	int *ptr3 =  (int*)malloc(1*sizeof(int)); //ptr1 = 1000
	//free(ptr3); first you need to free first ptr3
	ptr3 =  (int*)malloc(5*sizeof(int));
/* 	free(ptr3);//memory leak 
	free(ptr3);//memory leak  */
	
}


int main(int argc ,char *argv[])
{
	int a = 10; // 4 bytes 
	int num[5];// 5*4 = 20 bytes  compile time memory allocation or static memory allocation 
	
	int nostudent = 0;
	printf("Enter the number of student \n");
	scanf("%d",&nostudent);
	printf("Number of student = %d\n",nostudent);
	
	int *ptr ;
	//explicit type casting
	
	ptr = (int*)malloc(nostudent*sizeof(int));//int  ptr[nostudent] [alllocate memory dynamically on the user input ,dynamic memory allocation 
	
	//int  ptr[0] = junk or fake value 2432575
	//int  ptr[1] = junk or fake value 2432575
	if(ptr == NULL)//null == zero means memory allocation failed 
	{
		printf("Malloc memory allocation failed  \n");
		return -1;//error condition 
    }
	
	//ptr = (int*)malloc(nostudent*sizeof(int)); nostudent = 5 = int ptr[5];
	
    for (int i =0;i<nostudent;i++)
	{
		*(ptr+i) = (i+1)*10;//ptr[i] = (i+1)*10
		printf("Malloc *(ptr+%d)= %d\n",i,*(ptr+i));
	}
	
	
	
	//Calloc 
	
	int *ptrcalloc = (int*)calloc(nostudent,sizeof(int)); //int ptrcalloc[10];1 D int  
	
/* 	int ptrcalloc[0] = 0;
	int ptrcalloc[1] = 0;
	int ptrcalloc[2] = 0; */
	
	//always check 
	if(ptrcalloc == NULL)//null == zero means memory allocation failed 
	{
		printf("Calloc dynamic memory allocation failed  \n");
		return -1;//error condition 
    }
	
	//int *ptrcalloc = (int*)calloc(nostudent,sizeof(int)); //int ptrcalloc[10];
	
    for (int i =0;i<nostudent;i++)
	{
		*(ptrcalloc+i) = (i+1)*11;//ptr[i] = *(ptrcalloc+i) =(i+1)*11
		printf("calloc *(ptrcalloc+%d)= %d\n",i,*(ptrcalloc+i));
	}
	
	
	//realloc increase memory on run time which is previously allocated with the help of malloc and calloc 
	int *ptrrealloc = realloc(ptr,20*sizeof(int));//;ptr[10] already 

    //always check 
	if(ptrrealloc == NULL)//null == zero means memory allocation failed 
	{
		printf("ptrrealloc dynamic memory allocation failed  \n");
		return -1;//error condition 
    }
	
	   for (int i =0;i<20;i++)
	{
		*(ptrrealloc+i) = (i+1)*12;//ptr[i] = (i+1)*11  ptr[20]
		printf("ptrrealloc *(ptrrealloc+%d)= %d\n",i,*(ptrrealloc+i));
	}


   char *ptrchar = (char *)malloc(20*sizeof(char)); // char ptrchar[20] 1 D Char 
   
     //always check 
	if(ptrchar == NULL)//null == zero means memory allocation failed 
	{
		printf("ptrchar dynamic memory allocation failed  \n"); // ptrchar = &abc;
		return -1;//error condition 
    }

	strcpy(ptrchar,"Rakesh Kumar");
	
	printf("malloc char ptrchar = %s\n",ptrchar);

/* 
   	int student[3][3];  
	{
		
		1,2,3
		4,5,6
		7,8,9
	} */
	int row = 3;
	int col =3; //input from user 
	//row wise 
	int **ptrdouble = (int**)malloc(row *sizeof(int)); // int ptr[0],ptr[1],ptr[2]
    for(int i = 0;i<col ;i++)
	{
		ptrdouble[i] = (int*)malloc(col*sizeof(int));	//cover column 
	}
		

	for(int i =0;i<row;i++)
	{
	   for(int j = 0;j<col;j++)
	   {
            ptrdouble[i][j] = (i+1)*2; //same *((*ptrdouble+i)+j) =  ptrdouble[i][j] 
			printf("Double ptr 2D array  malloc = %d\n", ptrdouble[i][j]);
       }		   
	}
	
	/*int **ptr represents a pointer to a pointer, which is commonly used to store an array of pointers.
	int *arr[3]; // Array of 3 pointers to int a[] = {1,2,3}
    int **ptr = arr; // Pointer to an array of int pointers*/

    //int main(int argc ,char *argv[])  //char *argv[] = char **argv = { "string1","string2","string3"...} = array of char pointer 
	 
	int **ptrchar1 = (int**)malloc(row *sizeof(int*)); // int ptr[0],ptr[1],ptr[2] int **ptrchar1 = int *ptrchar[row] = {add1,add2,add3})
    for(int i = 0;i<col ;i++)
	{
		ptrchar1[i] = (int*)malloc(col*sizeof(int));	//cover column 
	}
		
	for(int i =0;i<row;i++)
	{
	   for(int j = 0;j<col;j++)
	   {
            ptrchar1[i][j] = (i+1)*2; //same *((*ptrchar1+i)+j) =  ptrchar1[i][j] 
			printf("Double ptr 2D array  malloc = %d\n", ptrchar1[i][j]);
       }		   
	}
	
    memoryleak();
    danglingpointer();
	
   free(ptr); //deallocate the memory and make it free for other to use 
   ptr = NULL;
   free(ptrcalloc);//deallocate the memory and make it free for other to use 
   ptrcalloc = NULL;
   free(ptrrealloc);//deallocate the memory and make it free for other to use 
   free(ptrchar1);//deallocate the memory and make it free for other to use 
   free(ptrdouble);//deallocate the memory and make it free for other to use
   return 0;
}



