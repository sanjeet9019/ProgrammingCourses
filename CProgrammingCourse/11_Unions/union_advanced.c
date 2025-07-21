/*******************************************************
*                                                     *
* Author        : Sanjeet Prasad                      *
* Email         : sanjeet8.23@gmail.com               *
* Description   : Demonstrates advanced C union usage *
*                 including union vs. struct memory   *
*                 handling, nested unions, type-based *
*                 access, and memory sharing behavior.*
*                 Illustrates unions with sensors,    *
*                 data formatting, and bit-level view *
*                 via typecasting and enum support.   *
* Created On    : 12th June 2025                      *
* Compiler      : GCC 14.2.0                          *
* Standard      : C99                                 *
*                                                     *
*******************************************************/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

/* Differece between struct and union 
1.//struct members share the different memory location that gurateed that it will unique values 
//union members share the same memory location 
2.size of struct will be total of all members and size of union will be maximum of members elements 
3.struct take always more memory and union take less memory  
4.nested union and nested struct 
5.union nest struct and struct nested union 

*/

struct student //struct members share the different memory location that gurateed that it will unique values 
{
	int rollno;//4 bytes 
	float marks; // 4 bytes 
	char name[20]; //20 bytes 
};

/* union studdata
{
	int rollno; //4 bytes 
	float marks; // 4 bytes
	char name[20];// 20 bytes 
};

 */
union studdata //union members share the same memory location 
{
	int rollno; //4 bytes same data types %d  65 
	int marks; // 4 bytes same data types  %f
	char name[20];// 20 bytes  %c A
}; 

struct pressure
{
   int force;
   int area;   
};

union weathers //union members share the same memory location 
{
	int temperature; //4 bytes same data types %d  65 
	float humanity; // 4 bytes same data types  %f
	struct pressure a;// 20 bytes  %c A
}; 

union data 
{
	int a;
	float b;
	char c;
};


struct datatypes{
int type ; //type 1 ,int ,type 2 - float ,type 3 = char 
union data d;
};


/* 12-06-2025  struct 1  - UK 
2025-06-12  struct 2  IND 
20250612    struct 3  US 

union ddmmyear
{
	struct 1;same memory 
	struct 2;same memory 
	struct 3;same memory 
}; */


/* union network
{
   struct data
   {
      int voicedata;
      char text;	  
   };
   struct header
   {
      int desipaddress; //sanjeet laptop address 
	  int srcipaddress; //rakesh laptop address 
   };	   
} */


/* union endian
{
   int num; //4 bytes  1 
   char endian[4]; // 4 bytes    %d  [0] ->1  bytes ,[1] second ,[2] third ,[3] 4th
}
//little endian 
endian[0] = 1; // lower address
endian[1] = 0;
endian[2] = 0;
endian[3] = 0;

//big endian 
endian[0] = 0;
endian[1] = 0;
endian[2] = 0;
endian[3] = 1;  //higher addres  */

union DateFormat {
    struct {
        int month;
        int day;
        int year;
    } mmddyyyy;

    struct {
        int day;
        int month;
        int year;
    } ddmmyyyy;
};


int main(int argc ,char *argv[])
{
   struct student s1= {.rollno = 100,.marks=34.55,.name = "Rakesh "};
   printf("Size of struct student = %d\n",sizeof(struct student));
   printf("struct student s1 data rollno = %d address = 0x%p  marks = %0.2f address = 0x%p name=%s address = 0x%p \n",
    s1.rollno,&s1.rollno,s1.marks,&s1.marks,s1.name,&s1.name);
   
   union studdata stud = {.rollno = 120}; 
   printf("Size of union studdata = %d\n",sizeof(union studdata));
   printf("union studdata stud rollno = %d address = 0x%p  marks = %d address = 0x%p name=%s address = 0x%p \n",
   stud.rollno,&stud.rollno,stud.marks,&stud.marks,stud.name,&stud.name);
   
   union weathers  noida ;
/*    noida.temperature = 36;
   noida.humanity = 43.34; 
   noida.a.force = 100; //sensor data 
   noida.a.area = 20;//sensor data  */
   while(1)
   {
	  //display on screen now only temperature  
	  noida.temperature = 36; // int gettemperaturefromsensor() 
      printf("noida.temperature = %d\n",noida.temperature);
	  //function(noida); by value 
   
      //display on screen now only humanity  
      noida.humanity = 43.34; // int gethumanityfromsensor() 
      printf("noida.humanity  = %0.2f\n",noida.humanity);
	  //function(&noida);by address 
	   
	  //display on screen now only pressure 
      //noida.a = {.force = 10,.area = 20};
	  noida.a.force = 100; //sensor data 
	  noida.a.area = 20;//sensor data 
	  
	  printf("noida pressure  force/aread = %d \n",(noida.a.force)/(noida.a.area));
	  sleep(5);//sleep the code for 5 seconds 
   
   }
   
   struct datatypes datastruct;
   
   //int data types 
   datastruct.type = 1 ;//int 
   datastruct.d.a = 100;
   
   //float 
   datastruct.type = 2 ;//float
   datastruct.d.a = 100.344;
   
   
   return 0;
}
