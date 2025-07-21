/*******************************************************
*                                                     *
* Author        : Sanjeet Prasad                       *
* Email         : sanjeet8.23@gmail.com                *
* Description   : Demonstrates array concepts in C,    *
*                 including declaration, initialization,*
*                 access via indexing, memory addressing*
*                 of 1D and 2D arrays, character arrays,*
*                 and function usage with arrays.       *
* Created On    : 22nd May 2025                         *
* Compiler      : GCC 14.2.0                            *
* Standard      : C99                                   *
*                                                     *
*******************************************************/


#include<stdio.h>

//step 1 .function declaration 
void printArrayandSum(int numbers[],int elementsize);

//step 2 .function defination 
/**
 * @brief Prints an integer array and calculates its sum.
 * 
 * This function iterates through a 1D integer array,
 * prints each element and its index, and calculates the total sum.
 * 
 * Example: input array = {10, 20, 30}
 * Output: index = 0 value = 10
 *         index = 1 value = 20
 *         index = 2 value = 30
 *         sum = 60
 * 
 * @param numbers Pointer to the array of integers.
 * @param elementsize Number of elements in the array.
 */

void printArrayandSum(int numbers[],int elementsize)
{
   int sum = 0;
   for(int i = 0;i<elementsize;i++)
   {
	   printf("printArray index = %d numbers[%d]= %d\n",i,i,numbers[i]);
	   sum = sum + numbers[i];
   }
   printf("printArray sum= %d\n",sum);	
}


int main(int argc ,char *argv[])
{
	//we have declare 5 variable to store 5 numbers 
   int num1 = 10;
   int num2 = 20;
   int num3 = 30;
   int num4 = 40;   
   int num5 = 50;    
   
   printf("num1 = %d\n",num1);
   printf("num2 = %d\n",num2);
   printf("num3 = %d\n",num3);   
   printf("num4 = %d\n",num4);
   printf("num5 = %d\n",num5);
   
   //1D dimensional Array,we have just declare one variable to store 5 numbers 
   int numbers[5] = {10,20,30,40,50}; //declare an array of 5 numbers which of integer types 0,1,2,3,4
   //numbers[0] = 10 = num1
   //numbers[1] = 20 = num2
   //numbers[3] = 20 = num3 
   
   printf("Size of array in bytes numbers = %d\n",sizeof(numbers));
   
   int elements = sizeof(numbers)/sizeof(int);
   printf("Number of elements in array numbers = %d\n",elements);
   
      //step 3 call the function 
   printArrayandSum(numbers,elements);
   
   /*    //Update the value of first element or index 0 element 
   numbers[0] = 100;
   printf("Updated value of First element of integer array  = %d\n",numbers[0]); */
   
   //Array access via index concept ,array index always start from 0 
   //output
   
   
/*    printf("Memory address of first int array element  = 0x%p value = %d\n ",&numbers[0],numbers[0]);
   printf("Memory address of second int array element  = 0x%p value = %d\n ",&numbers[1],numbers[1]);
   printf("Memory address of Third int array element  = 0x%p value = %d\n ",&numbers[2],numbers[2]);
   printf("Memory address of Fourth int array element  = 0x%p value = %d\n ",&numbers[3],numbers[3]);
   printf("Memory address of Fifth int array element  = 0x%p value = %d\n ",&numbers[4],numbers[4]);
    */
	  /*    output 
   Memory address of first int array element  = 0x0000006b43fff9b0 value = 10 
   Memory address of second int array element  = 0x0000006b43fff9b4 value = 20  + 4 
   Memory address of Third int array element  = 0x0000006b43fff9b8 value = 30  +4 
   Memory address of Fourth int array element  = 0x0000006b43fff9bc value = 40 +4 
   Memory address of Fifth int array element  = 0x0000006b43fff9c0 value = 50 +4 */
   for(int i = 0;i<elements;i++)
   {
	   printf("Memory address of int array %d th element  = 0x%p and value = %d index = %d\n",i+1,&numbers[i],numbers[i],i);
   }
   
   /* Memory address of 1 th element  = 0x0000006cbf5ffe00 and value = 10 index = 0
   Memory address of 2 th element  = 0x0000006cbf5ffe04 and value = 20 index = 1
   Memory address of 3 th element  = 0x0000006cbf5ffe08 and value = 30 index = 2
   Memory address of 4 th element  = 0x0000006cbf5ffe0c and value = 40 index = 3
   Memory address of 5 th element  = 0x0000006cbf5ffe10 and value = 50 index = 4 */
   
   int score[] = {45,77,56,78,80};  //if you dont know the size use this one ,only one for loop 

   printf("Size of score = %d\n",sizeof(score));
   printf("Number of elements = %d\n",sizeof(score)/sizeof(int));
   
   
   //First way to declare character of array 
   char name[] = {'R','A','K','E','S','H','\0'}; //Alway put at the end of the character array ,this is null character
   //it is needed to tell that characters ends explicity 

   
   elements = sizeof(name)/sizeof(char);
   printf("Size of name = %d\n",sizeof(name));
   printf("Number of elements in character array = %d\n",elements);
   
   for(int i = 0;i<elements;i++)
   {
	   printf("Memory address of char array  %d th element  = 0x%p and value = %c index = %d\n",i+1,&name[i],name[i],i);
   }
   /*    Number of elements in character array = 7
   Memory address of char array  1 th element  = 0x000000a354bff909 and value = R index = 0
   Memory address of char array  2 th element  = 0x000000a354bff90a and value = A index = 1 
   Memory address of char array  3 th element  = 0x000000a354bff90b and value = K index = 2
   Memory address of char array  4 th element  = 0x000000a354bff90c and value = E index = 3
   Memory address of char array  5 th element  = 0x000000a354bff90d and value = S index = 4
   Memory address of char array  6 th element  = 0x000000a354bff90e and value = H index = 5
   Memory address of char array  7 th element  = 0x000000a354bff90f and value =  index = 6 */
   
      
   //Second way to declare character of array or 1D Char array 
   char fullname[] = "SoumRoy";//\0 null character but it will add by compiler 
   
   elements = sizeof(fullname)/sizeof(char);//it will add null character as well 
   printf("Size of fullname = %d\n",sizeof(fullname));
   printf("Number of elements in character array = %d\n",elements);
   for(int i = 0;i<elements-1;i++)
   {
	   printf("Memory address of char array fullname %d th element  = 0x%p and value = %c index = %d\n",i+1,&fullname[i],fullname[i],i);
   }
   
   printf("Full name = %s\n",fullname);


   //2D int Array 
   int studentMarks[3][5]= { //int arr[row][col]
	                          {45,45,56,77,78},  //student 1   1D Array 20 bytes 0 rowth 
	                          {55,65,86,77,88},  //student 2   1D Array 20 bytes 1 
	                          {65,75,86,87,98},  //student 3   1D Array 20 bytes 2
                           };

   
   elements = sizeof(studentMarks)/sizeof(int);//it will add null character as well 
   printf("Size of studentMarks = %d\n",sizeof(studentMarks));
   printf("Number of elements in studentMarks 2d array = %d\n",elements);
   
   //First row 
   printf("First row Memory address of first int 2d array element  = 0x%p value = %d\n ",&studentMarks[0][0],studentMarks[0][0]);
   printf("First row Memory address of second int 2d array element  = 0x%p value = %d\n ",&studentMarks[0][1],studentMarks[0][1]);
   printf("First row Memory address of third int 2d array element  = 0x%p value = %d\n ",&studentMarks[0][2],studentMarks[0][2]);
   printf("First row Memory address of fourth int 2d array element  = 0x%p value = %d\n ",&studentMarks[0][3],studentMarks[0][3]);
   printf("First row Memory address of fifth int 2d array element  = 0x%p value = %d\n ",&studentMarks[0][4],studentMarks[0][4]);

   //Second row 
   printf("Second Row Memory address of first int 2d array element  = 0x%p value = %d\n ",&studentMarks[1][0],studentMarks[1][0]);
   printf("Second Row Memory address of second int 2d array element  = 0x%p value = %d\n ",&studentMarks[1][1],studentMarks[1][1]);
   printf("Second Row Memory address of third int 2d array element  = 0x%p value = %d\n ",&studentMarks[1][2],studentMarks[1][2]);
   printf("Second Row Memory address of fourth int 2d array element  = 0x%p value = %d\n ",&studentMarks[1][3],studentMarks[1][3]);
   printf("Second Row Memory address of fifth int 2d array element  = 0x%p value = %d\n ",&studentMarks[1][4],studentMarks[1][4]);
   
    //Third row 
   printf("Third Row Memory address of first int 2d array element  = 0x%p value = %d\n ",&studentMarks[2][0],studentMarks[2][0]);
   printf("Third Row Memory address of second int 2d array element  = 0x%p value = %d\n ",&studentMarks[2][1],studentMarks[2][1]);
   printf("Third Row Memory address of third int 2d array element  = 0x%p value = %d\n ",&studentMarks[2][2],studentMarks[2][2]);
   printf("Third Row Memory address of fourth int 2d array element  = 0x%p value = %d\n ",&studentMarks[2][3],studentMarks[2][3]);
   printf("Third Row Memory address of fifth int 2d array element  = 0x%p value = %d\n ",&studentMarks[2][4],studentMarks[2][4]);

 
   //2D Character array 
   char studentname[][20] = 
   {
	   "Rakesh Kumar", //studentname[0] 
	   "SoumRoy",  //studentname[1] 
	   "Sanjeet"  //studentname[2] a
   };
 
   //if there is 2D array it means we need 2 for loop that nested one inside others 
   for(int row = 0;row<3;row++) //row 
   {
	   printf("student name = %s got below marks \n",studentname[row]);
	   for(int col = 0;col<5;col++)//column 
	   {
		 printf("studentMarks[%d][%d] = %d address = 0x%p\n", row,col,studentMarks[row][col],&studentMarks[row][col]); 
	   }
	   printf("\n");
   }
 

   return 0;
}


