/*******************************************************
*                                                     *
* Author        : Sanjeet Prasad                      *
* Email         : sanjeet8.23@gmail.com               *
* Description   : Demonstrates various ways to use    *
*                 integer pointers and arrays in C,   *
*                 including 1D array access through    *
*                 standard indexing, pointer arithmetic, *
*                 fixed-size array pointers, and pointer *
*                 to entire array. Also showcases how  *
*                 character arrays (2D) are managed,   *
*                 accessed, and printed using pointers.*
* Created On    : 28th May 2025                       *
* Compiler      : GCC 14.2.0                          *
* Standard      : C99                                 *
*                                                     *
*******************************************************/


#include<stdio.h>
#include <string.h>

void print1DArray_1(int arr[],int size); //1st way array notation
void print1DArray_2(int *arrptr,int size); //2nd way  ptr arithematic
void print1DArray_3(int arrptr[5]) ;//3rd way  ptr arithematic fixed size 
void print1DArray_4(int (*ptrToArr)[5]); //4th way 
int sum(int aaa,int bbb); //call by value 
void print2DCharArray_1(char arr2dcountry[3][20]);//2D Character Array 
void print2DCharArray_2(char (*ptrarr2dcountry)[20],int row);

//2D Char array 
void print2DCharArray_1(char countryname[3][20]);




void recursionprintstring(const char *baseptr);

void recursionprintstring(const char *baseptr)
{
    if(*baseptr == '\0')
        return ;
    putchar(*baseptr);	
	recursionprintstring(baseptr+1);
}

//function where we pass value we call ,call by value ,value remain unchanged 
int sum(int a,int b) // int sum(10,20)
{
    a = a + 100;//110
    b = b + 100; //120
    return (a + b) ;	
}


//1st way to access 1D array using func ,array notation
void print1DArray_1(int arr[],int size) //1st way  void print1DArray_1(&address of array,int size)
{
	for(int i =0;i<size;i++)
	{	
        //arr[i] = arr[i]*10;  
		printf("1st way to access 1D array using func index notation arr[%d] = 0x%p  value = %d\n",i,&arr[i],arr[i]);

	}
	
}

//2nd way to access 1D array using func ,array notation, where we pass address ,we called such function call by address 
void print1DArray_2(int *arrptr,int size) //2nd way 
{
	for(int i =0;i<size;i++)
	{	  
		printf("2nd way to access 1D array using func index notation arr[%d] = 0x%p  value = %d\n",i,arrptr,*arrptr);
		arrptr = arrptr +1;
	}
}

//3rd way to access 1D array using func ,int array notation
void print1DArray_3(int arrfixed[5]) 
{
	for(int i =0;i<5;i++)
	{	
        //arr[i] = arr[i]*10;  
		printf("/3rd way to access 1D array using func fixed size arr[%d] = 0x%p  value = %d\n",i,&arrfixed[i],arrfixed[i]);

	}
}

//4th way to access 1D array using func ,pointer to an int array 
void print1DArray_4(int (*ptrToArr)[5])
{
	for(int i =0;i<5;i++)
	{	
		printf("/4th way to access 1D array using func ,pointer to an int array arr[%d] = 0x%p  value = %d\n",i,&(*ptrToArr)[i],(*ptrToArr)[i]);
	}
}


//First way to print 2D char array 
void print2DCharArray_1(char countryname[3][20])
{
     for(int i = 0;i<3;i++)
     {
        printf("First way to print 2D char array countryname = %s  Address = 0x%p\n",countryname[i],countryname[i]);
     }		 
	
}
//Second way to print 2D Char array 
void print2DCharArray_2(char (*ptrtoarcountry)[20],int row)
{
	 for(int i = 0;i<row;i++)
     {
        printf("Second way to print 2D Char array countryname = %s  Address = 0x%p\n",ptrtoarcountry[i],ptrtoarcountry[i]);
     }		
}





//5th way  array of int pointers ,you can try yourself 

int main(int argc ,char *argv[])
{
   /* /* //1 D array ,array of integers 
   
   int studentscore[5] = {50,60,70,80,90};  //1000,1004,1008,1012,1016 
   
   
   //studentscore -> name of the array is address of array ,first element address ,studentscore = &studentscore[0]
   //studentscore = &studentscore[0] first element address of an array ,that we called this is constant pointer,also base address 
    
	printf("1D array first element address studentscore = 0x%p\n",studentscore);
	printf("1D array first element address &studentscore[0] = 0x%p\n",&studentscore[0]);
	
	//Pointer variable 
	int *arrPtr = &studentscore[0] ;
	printf("1D array first element address using pointer variable = 0x%p\n",arrPtr);
	
	//1st way to access 1D array ,index notation arr[i]
	int size = sizeof(studentscore)/sizeof(int);
	
	for(int i =0;i<size;i++)
	{
		//studentscore[i] = studentscore[i]+1;
		printf("1st way to access 1D array ,index notation arr[%d] = 0x%p  value = %d\n",i,&studentscore[i],studentscore[i]);
		
	}
	
	//2nd way to access 1D using pointer arithematic  //int *arrPtr = &studentscore[0] ;*& = NULL or VOID  +2-2 = 0
	
/* 	(arrPtr + 0) = &studentscore[0] --> *(arrPtr + 0) = *&studentscore[0] = studentscore[0] = value                
	(arrPtr + 1) = &studentscore[1] --> *(arrPtr + 1) = *&studentscore[1] = studentscore[1] = value 
	(arrPtr + 2) = &studentscore[2] --> *(arrPtr + 2) = *&studentscore[2] = studentscore[2] = value 
	*(arrPtr + 0) = studentscore[0]  //First value of array 
	*(arrPtr + 1) = studentscore[1]  //second value of array 
	*(arrPtr + i) = studentscore[i] */
/* 	
    for(int i =0;i<size;i++)
	{
		printf("2nd way to access 1D array using pointer arithematic  ptr arr add = 0x%p  ptr arr value = %d\n",arrPtr,*arrPtr);
		arrPtr = arrPtr + 1;  //arrPtr + 1
	}
	 */
	//3rd way to access 1D array ,array of pointers 
	//int studentscore[5] = {50,60,70,80,90}; //array of integers 
	//int *arrPtrs[5] = {&studentscore[0],&studentscore[1],&studentscore[2],&studentscore[3],&studentscore[4]}; 
	
/* 	arrPtr[0] = &studentscore[0];
	arrPtr[1] = &studentscore[1];
	arrPtr[2] = &studentscore[2];
	arrPtr[3] = &studentscore[3];
	arrPtr[4] = &studentscore[3]; */
	
/* 	for(int i =0;i<size;i++)
	{
		printf("3rd way to access 1D array ,array of pointers  add = 0x%p  ptr arr value = %d\n",arrPtrs[i],*arrPtrs[i]);
	}	 */
	
	//4th way of accessing 1D array , Pointers to an array 
	//int studentscore[5] = {50,60,70,80,90}; //array of integers 
/* 	int (*ptrToArr)[5] = &studentscore ;// &studentscore[0] = wrong ,studentscore = wrong  ,&studentscore = total number of elements 
	
	printf("4th way of access 1D array (*ptrToArr)[5]  add = 0x%p \n",ptrToArr);
	for(int i =0;i<size;i++)
	{
		printf("4th way of access 1D array (*ptrToArr)[5]  add = 0x%p ptr arr value = %d\n",&(*ptrToArr)[i],(*ptrToArr)[i]);
	}	
	ptrToArr = ptrToArr + 1 ;
	printf("4th way of access 1D array (*ptrToArr)[5]  add = 0x%p \n",ptrToArr);
	 */
	
	//Array passing to function 
	//int studentscore[5] = {50,60,70,80,90};
	
	//1. Array notation
/* 	print1DArray_1(studentscore,size);//studentscore address 

	for(int i =0;i<size;i++)
	{	
		printf("print1DArray_1 after the func call  using func index notation arr[%d] = 0x%p  value = %d\n",i,&studentscore[i],studentscore[i]);

	}
	 */
	//2.pointer arithemetic 
	//print1DArray_2(studentscore,size);//studentscore address 
	
	//3.Fixed array 
	//print1DArray_3(studentscore);//studentscore address 
	
	//4. pointer to array size 
	//print1DArray_4(&studentscore);//studentscore address - //call by reference function 
	
	//Function : Pass by value 
/* 	int a = 10,b = 20;
	int c = sum(a,b);//call by value function 
	printf("value of a ,b,c = %d, %d %d\n",a,b,c);//10,20,230 */
	
	
	//Character 1 D array 
	
	/* char full_name[] = "Soumadipta Roy";
    int char_count = (sizeof(full_name) / sizeof(char)) - 1;

    //1st way index notation
    for (int i = 0; i < char_count; i++)
    {
        printf("Character at position %d at address %p is %c\n", i + 1, &full_name[i], full_name[i]);
    }

    //2nd way pointer arithmatic
    char *arrPtr1 = full_name;
    for (int i = 0; i < char_count; i++)
    {
        printf("Character at position %d at address %p is %c\n", i + 1, arrPtr1, *arrPtr1);
        arrPtr1++;
    }

    // 3rd way array of pointers
    char *arrPtrs1[char_count];
    for (int i = 0; i < char_count; i++)
    {
        arrPtrs1[i] = &full_name[i];
    }

    for (int i = 0; i < char_count; i++)
    {
        printf("Character at position %d at address %p is %c\n", i + 1, arrPtrs1[i], *arrPtrs1[i]);
    }
    // 4th way pointers to an array
    char (*ptrToArr1)[char_count] = &full_name;
    for (int i = 0; i < char_count; i++)
    {
        printf("Character at position %d at address %p is %c\n", i + 1, &(*ptrToArr1)[i], (*ptrToArr1)[i]);
    } */
	
	//Try passing character array in different way  as argument to function ,try yourself ,4 ways  */ */
	
	//Printing whole string 
	char aword[] = "India is my country"; //'\0' implicitely 
	
	//1st way to do that aword -> base address or we called first element address 
	char *baseptr = aword;//&aword[0]
	
	printf("1st way Print whole char array = %s ,address = 0x%p\n", aword,aword);//%s always want an address to print the whole string 
	printf("2nd way Print whole char array = %s ,address = 0x%p\n", &aword[0],&aword[0]);//%s always want an address to print the whole string 
	printf("3rd way Print whole char array using ptr = %s ,address = 0x%p\n", baseptr,baseptr);//%s always want an address to 
	
	printf("4st way Print whole char array = %s ,address = 0x%p\n", aword+5,aword+5);//%s always want an address to print the whole string 

    //5th way to do that 
	printf("Using Puts to print whole string \n");
	puts(aword); //int puts(const char *ptr)  puts(aword+2);
	
	//6th way to print whole string
     printf("Using Putchar to print whole string \n");
     while(*baseptr!='\0')
     {
        putchar(*baseptr);
		baseptr = baseptr + 1;
     }		 
	 
	//7th way to print whole string
    printf("\nUsing recursion  to print whole string \n");
	char *baseptr1 = aword;
	recursionprintstring(baseptr1);
	
	
	//2D Array Integer

    int numbers[3][3] = {
					{1,2,3},	 //1st row 
					{4,5,6},	 //2nd row 
					{7,8,9},     //3rd row 
	};
      
    //1st way index way 
    printf("1st way to access 2D int array using index notation \n");
	for (int row = 0;row<3;row++)
	{
	   for(int col = 0;col<3;col++)
       {
           printf("numbers[%d][%d] = %d address = 0x%p\n",row,col,numbers[row][col],&numbers[row][col]);
	   }		   
	}
	
	//2nd way to access 2D array ,pointer arithematic
	
	int *iarr2dptr = &numbers[0][0];
	int numberelement = 0;
	printf("2nd way to access 2D int array using pointer arithematic\n");

	for (int numberelement = 0;numberelement<9;numberelement++)  //9 = 3*3
	{
        printf(" 2D array element value  = %d address = 0x%p\n",*iarr2dptr,iarr2dptr);
        iarr2dptr = iarr2dptr + 1;//adding each element to next 2d array element 		
	}
	
	//3rd way to access 2D array ,row wise pointers 
	printf("3rd way to access 2D array ,row wise pointers \n");
	int *iarr2dptrr = numbers[0]; //first base adddress of row 1 0x000000bec0dff8e0
	//+3 address 
	/* int *iarr2dptrr1 = numbers[1]; //row 2 base address , 0x000000bec0dff8ec
	//+3 address  = 12 bytes 
	int *iarr2dptrr2 = numbers[2]; //row 3 base address , 0x000000bec0dff8f8 */
	
	for(int row = 0;row<3;row++)
	{
		for(int col = 0;col<3;col++)
		{
			printf("address 0x%p value =%d\n",(iarr2dptrr+col),*(iarr2dptrr + col));
		}
	    iarr2dptrr = iarr2dptrr + 3; //row = 3 
	}
	
	//4th way to represent an 2Darray ,Pointer to an array 

    int (*arrr2dptr)[3] = numbers; //3 is always number of row elements  
 	printf("4th way to access 2D array ,Pointer to an array \n");
	for(int row = 0;row<3;row++)
	{
		for(int col = 0;col<3;col++)
		{
	      	printf("address 0x%p value =%d\n",&(*arrr2dptr)[col],(*arrr2dptr)[col]);	
		}
		arrr2dptr = arrr2dptr + 1;//it is single unit of a row 
	}
	
	//Array of pointers 
	//int *ptr[9] = {&numbers[0][0],&numbers[0][1],}
	
	//Function passing 2D array in different ways ,implement yourself 

    //2D Character array function passing 
	
	char countryname[3][20] = {
                          "India",
                          "Ireland",
                          "United Kingdom",
	                    };						  
	
	print2DCharArray_1(countryname);
	print2DCharArray_2(countryname,3);
	
	//Another way to write a string in C using pointers 
	char *ptr = "India is my country";
	
	printf("Ptr string value = %s\n",ptr);
	
	//Array of pointers 
	char *country[3] = {
                          "India is my country ",  //country[0]
                          "Ireland is roy place ",  //country[0]
                          "United Kingdom capital is london",
	                    };	
	
	printf("country[0] = %s\n",country[0]);
	printf("country[1] = %s\n",country[1]);
	printf("country[2] = %s\n",country[2]);
	
	//using for loop plus function types print2DCharArray_3(countryname,3);

    //int *ptrrrr[3] = {&a, &b, &c};
	
	//double pointer 
	int number100 = 100; 
	int *ptrnum100 = &number100;// integer pointer ,ptrnum100 is a pointer to an integer ,first pointer holding 1 address 
	int **dptrptrnum100 = &ptrnum100; //double pointer to an integer value 
	int ***dptrptrnum1000 = &dptrptrnum100;//triple pointers 
	
	//dptrptrnum100 = &ptrnum100 pointer address  + &number100(int number address )
	
	printf("number100 = %d  number100 address = 0x%p dptrptrnum100 = 0x%p\n",number100,ptrnum100,dptrptrnum100);
	
	printf("Double pointer dptrptrnum100 = 0x%p  *dptrptrnum100 gives address of  &number100 = 0x%p **dptrptrnum100 value of number = %d\n",dptrptrnum100,*dptrptrnum100,**dptrptrnum100);
	
	
   //	int num2darr[i][j] ;

	/* 	(arrPtr + 0) = &studentscore[0] --> *(arrPtr + 0) = *&studentscore[0] = studentscore[0] = value                
	(arrPtr + 1) = &studentscore[1] --> *(arrPtr + 1) = *&studentscore[1] = studentscore[1] = value 
	(arrPtr + 2) = &studentscore[2] --> *(arrPtr + 2) = *&studentscore[2] = studentscore[2] = value 
	*(arrPtr + 0) = studentscore[0]  //First value of array 
	*(arrPtr + 1) = studentscore[1]  //second value of array 
	*((*(arrPtr + i)+j) = studentscore[i] */
	
	
	//string functions 
/* 	strlen() – Find String Length
      - Returns the number of characters in a string (excluding \0).
       - Syntax:
        size_t strlen(const char *str);
        Example: char str[] = "hello"; printf("Length: %lu\n", strlen(str));  // Output: 5
strcpy() – Copy a String
     Copies one string into another.
     Syntax:
     char *strcpy(char *dest, const char *src);
strcat() – Concatenate Strings
      Appends a source string to the end of the destination.
        Syntax:
      char *strcat(char *dest, const char *src);
      Important: dest must have sufficient space.
strcmp() – Compare Two Strings
      Compares two strings lexicographically.
      Syntax:
      int strcmp(const char *str1, const char *str2);
      Example:   int result = strcmp(s1, s2);
      Return Values:
      < 0 → str1 is smaller than str2
      0 → Strings are identical
      > 0 → str1 is greater than str2 */
	
	
	
	 //size_t strlen(const char *str);size_t  = int 
     //Example: char str[] = "hello"; printf("Length: %lu\n", strlen(str));  // Output: 5
	 
	 char country1d[] = "India is my country";//size calulcated itself 
	 char countryname1[50] = "Ireland is my country";//fixed size 50 
	 char *countrynameptr = "India is my country"; //pointer to constant char 
	 
	
	//int strlen(const char *str);
	
	int length = strlen(country1d);
	int *ptry = &length ;
	printf("country1d[] String length = %d size of country1d = %d \n",length,sizeof(country1d));
	length = strlen(countryname1);
	printf("countryname1[] String length = %d size of countryname1 = %d \n",length,sizeof(countryname1));
	length = strlen(countrynameptr);
	printf("countrynameptr String length = %d size of countrynameptr = %d integer ptr = %d\n",length,sizeof(countrynameptr),sizeof(ptry));
	
/* /* /* 	
	strcpy() – Copy a String
     Copies one string into another.
     Syntax:
	 char src = "India is my country");
	 char dest ;
     char *strcpy(char *dest, const char *src); */

	 
	 //your implement of strlen dont use built in or standard library function 
	 //char *strcat(char *dest, const char *src);
	 
	 char src[] = "Kumar ";
	 char dest[50] = "Rakesh";
	 
	 // char *strcpy(char *dest, const char *src);
	 char *ccptr = strcat(dest,src);
	 
	 printf("strcat(dest,src) = %s ptr = %s\n",dest,strcat(dest,src));
	 
/* 	 strcmp() – Compare Two Strings
      Compares two strings lexicographically.
      Syntax:
      int strcmp(const char *str1, const char *str2);
      Example:   int result = strcmp(s1, s2);
      Return Values:
      < 0 → str1 is smaller than str2
      0 → Strings are identical
      > 0 → str1 is greater than str2 */
	  
	  
/* 	  📌 Pointer and 2D char Array
Theoretical Questions
- How does pointer arithmetic work in a 2D character array?
- Why must the number of columns be specified when passing a 2D character array to a function?
- How does an array of pointers (char *arr[]) differ from a statically allocated 2D character array (char arr[row][col])?
- How do pointers help in handling variable-length strings efficiently in C?
Programming Questions
- Write a function that prints a 2D character array using pointer notation.
- Implement a program to sort rows of a 2D character array (list of words) using pointers.s.
- Create a program that finds and prints palindromic words in a 2D character array using pointer manipulation.
- Implement a pointer-based function that searches for a specific word in a 2D character array. */

    return 0;
}