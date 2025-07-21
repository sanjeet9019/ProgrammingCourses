/*******************************************************
*                                                     *
* Author        : Sanjeet Prasad                      *
* Email         : sanjeet8.23@gmail.com               *
* Description   : Demonstrates advanced C structure   *
*                 concepts including bit fields,      *
*                 padding and alignment behavior,     *
*                 packed structures using attributes, *
*                 typedef aliases, and type definitions.*
*                 Highlights memory layout optimization*
*                 and readability practices for struct.*
* Created On    : 11th June 2025                      *
* Compiler      : GCC 14.2.0                          *
* Standard      : C99                                 *
*                                                     *
*******************************************************/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//type 2 to struct packing ,whole struct will packed 
//#pragma pack(1) 

struct bitfield
{
   unsigned int read:1;  //4 bytes = 32 bits ,1 bit 
   unsigned int write:1;  //4 bytes = 32 bits  ,2 bits  = 0,1,2,3  
   unsigned int exec:1;  //4 bytes = 32 bits  ,2 ,0,1,2,3 
};

//real sense total bytes = 5 
struct padding1
{
   char a; // 1 byte
   int b;  // 4 bytes  
};

struct padding2
{
   char a; // 1 byte
};
//same as char a ; because it has only one member that is character 

struct padding3
{
   char a; // 1 byte
   int b;  // 4 bytes  
   char c; // 1 byte
};


struct padding4
{
   char a; // 1 byte
   char c; // 1 byte
   int b;  // 4 bytes  
};

struct padding5
{
   char a; // 1 byte
   float c; // 4 byte
   int b;  // 4 bytes  
};

struct padding6
{
   char name[4];
   double a; // 8 byte
   float c; // 4 byte
   int b;  // 4 bytes  
};

//First way to do it packed structure
struct __attribute__((packed))  packed1
{
   char a; // 1 byte
   int b;  // 4 bytes  
};

struct __attribute__((packed))  packed2
{
   char a; // 1 byte
   int b;  // 4 bytes  
   char c; // 1 byte
   char name[100];// 100 bytes 
};

typedef struct student
{
   char name[20];
   int roll;
   int standard;
   float marks;  
}STUD;//STUD is alias of struct student

//enum ,array ,pointer ,struct ,function pointers so on 
typedef short int SHORT;
typedef unsigned int UINT;

int main(int argc ,char *argv[])
{
    struct bitfield file1permission = {.read = 1,.write = 0,.exec = 1};
	printf("bitfield file1permission  read = %d ,write = %d exec = %d\n",file1permission.read,file1permission.write,file1permission.exec);
	 
	printf("size of struct bitfield file1permission = %d\n",sizeof(struct bitfield));
	
	//struct padding 
	printf("size of struct padding1 = %d bytes\n",sizeof(struct padding1));
	printf("size of struct padding2 = %d bytes \n",sizeof(struct padding2));
	printf("size of struct padding3 = %d bytes\n",sizeof(struct padding3));
	printf("size of struct padding4 = %d bytes \n",sizeof(struct padding4));
	printf("size of struct padding5 = %d bytes\n",sizeof(struct padding5));
	printf("size of struct padding6 = %d bytes\n",sizeof(struct padding6));
	
	//Packed structure -> to avoid structure padding 
	printf("size of struct packed1 = %d bytes \n",sizeof(struct packed1));
	printf("size of struct packed2 = %d bytes \n",sizeof(struct packed2));
	 
	 
   //float ,int,char ,point ,int arr,char arr ,float arry ,float *ptr , double ,short int ,long int ,5 types of struct padding,5 type packed 
   
   STUD Rakesh  = {.name = "Rakesh",.roll = 200};//struct student Rakesh
   STUD Roy;//struct student Roy; 
   
   printf("typedef example STUD Rakesh name = %s roll = %d \n",Rakesh.name,Rakesh.roll);
   
   SHORT a = 200;//2 bytes short int a = 200;
   printf("typedef SHORT int a = %d \n",a);
   
   return 0;
}

