/*******************************************************
*                                                     *
* Author        : Sanjeet Prasad                      *
* Email         : sanjeet8.23@gmail.com               *
* Description   : Demonstrates file I/O operations in *
*                 C, including writing and reading    *
*                 integer and struct data using both  *
*                 text and binary formats. Covers use *
*                 of `fwrite()` and `fread()` for     *
*                 binary serialization, and shows how *
*                 struct data is stored and accessed  *
*                 from disk. Also handles cross-OS    *
*                 file paths with macros.             *
* Created On    : 09th July 2025                      *
* Compiler      : GCC 14.2.0                          *
* Standard      : C99                                 *
*                                                     *
*******************************************************/


#include<stdio.h>

typedef struct student
{
	 int roll;
     char name[20];
     float marks ;	 
}STUDENT;
  

#define WINDOWS

int main(int argc ,char *argv[])
{
  //windows path
  #ifdef WINDOWS  
  const char* filepath = "C:\\Users\\x\\Desktop\\sanjeet\\github\\CProject\\CProgram\\Day19\\sample.txt";
  #else
  //linux path 
  const char* filepath = "/c/Users/x/Desktop/sanjeet/github/CProject/CProgram/Day19/sample.txt";
  #endif 	
	
  printf("File open for reading = %s\n",filepath);	
  
  //Write 123 into text.txt in normal mode 
  int num = 123;
  FILE *fptext = fopen("text.txt","w");
  
  if(fptext == NULL)
  {
	   printf("File open failed\n");
	   return -1;
  }
  //write 123 to fptext 
  fprintf(fptext,"%d",num);
  printf("text.txt 123 is written successfully\n");
  
  fclose(fptext);
  
  //Write 123 into binary.dat in binary mode 
  FILE *fpbin = fopen("binary.dat","wb");
  
  if(fpbin == NULL)
  {
	   printf("File open binary failed\n");
	   return -1;
  }
  
  //write 123 to fpbin 
  //size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream); 
  fwrite(&num,sizeof(int), 1,fpbin);
  printf("binary.dat 123 is written successfully\n"); 
  fclose(fpbin);
  
  //Binary Write operations
  printf("File Write in Binary format \n");
  FILE *fpwb = fopen("student.dat","wb");
  STUDENT roy = {.roll = 100,.name = "S Roy",.marks = 87.55}; 
  if(fpwb == NULL)
  {
	   printf("File open binary failed\n");
	   return -1;
  }
    //size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream); 
  fwrite(&roy,sizeof(STUDENT), 1,fpwb);
  printf("student.dat roy details is written successfully\n"); 
  fclose(fpwb);
  
  //Binary Read operations
  printf("File Read in Binary format \n");
  STUDENT roydetails; 
  FILE *fprb = fopen("student.dat","rb");

  if(fprb == NULL)
  {
	   printf("File open binary failed\n");
	   return -1;
  }
  //size_t fread(void *ptr, size_t size, size_t count, FILE *stream);
  fread(&roydetails,sizeof(STUDENT), 1,fprb);
  printf("Roy details name = %s ,roll = %d marks = %0.2f\n",roydetails.name,roydetails.roll,roydetails.marks); 
  printf("student.dat roy details is read successfully\n"); 
  fclose(fprb);
  
  
  
  
  return 0;	
}