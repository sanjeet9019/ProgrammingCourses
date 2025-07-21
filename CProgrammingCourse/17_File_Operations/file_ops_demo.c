/*******************************************************
*                                                     *
* Author        : Sanjeet Prasad                      *
* Email         : sanjeet8.23@gmail.com               *
* Description   : Demonstrates file handling in C     *
*                 including reading using fscanf,     *
*                 fgetc, fgets; writing using fprintf,*
*                 fputc, fputs; append mode, pointer  *
*                 manipulation using rewind, fseek,   *
*                 and ftell. Also explores file modes *
*                 like "r", "w", "r+", "w+", "a" and  *
*                 platform-independent path handling. *
* Created On    : 03rd July 2025                      *
* Compiler      : GCC 14.2.0                          *
* Standard      : C99                                 *
*                                                     *
*******************************************************/

#include<stdio.h>
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
  //FILE *fpr = fopen("sample.txt","r");// file read from current directory 
  FILE *fpr = fopen(filepath,"r");// file read from current directory 
  
  if(fpr == NULL)
  {
	printf("File open failed\n");
    return -1;	
  }
  printf("File open successfully = 0x%p\n",fpr);
  //read  file operations in C 
  
  //1.fscanf 
  char buffer[100];
  
  int filepos = ftell(fpr);
  printf("Sample.txt file position(fpr) = %d\n",ftell(fpr));
  
  printf("File read operation using fscanf()\n");
  while(fscanf(fpr,"%s",buffer)!=EOF)
  {	  
	printf("File read operation fscanf() sample.txt = %s\n",buffer);
  }
  printf("Sample.txt file position(fpr) = %d\n",ftell(fpr));
  printf("File read operation sample.txt  successfully done using fscanf()\n");

  
  //2.fgetc file operation 
  rewind(fpr); //it will take the file position or file ptr to start of the file 
  printf("Sample.txt file position(fpr) before fgetc = %d\n",ftell(fpr));
  int ch ;
  printf("File read operation using fgetc(fpr)\n");
  while((ch = fgetc(fpr))!=EOF)
  {
     printf("%c",ch);
  }	  
  printf("Sample.txt file position(fpr) after fgetc = %d\n",ftell(fpr));

  //3. fgets file operation  
  
  fseek(fpr,0,SEEK_SET);  //Take the file pointer to the begining of the file or same thing is done rewind(fpr)
  //fseek(fpr,5,SEEK_SET); 5 is the offset to read the file 
  fseek(fpr,0,SEEK_CUR); //Current position of file pointer 
  fseek(fpr,-117,SEEK_END); // it will take the file pointer to end of the file is same as rewind(fpr)
  
  printf("Sample.txt file position(fpr) using fseek() SEEK_SET = %d\n",ftell(fpr));
  
  
  printf("File read operation using fgets(fpr)\n");
  while(fgets(buffer,100,fpr)!=NULL)
  {
	printf("%s",buffer);  
  }
    fclose(fpr);

  //Steps for file read operations standard library  
  //1. fopen - open the file 
  //2. read in various ways 
      //2.1 fscanf()
      //2.2 fgetc() 
      //2.3 fgets()	
  //3. write in various way 
      //3.1 fprintf()
      //3.2 fputc() 
      //3.3 fputs()	
  //4. fseek()  
  //5. rewind() -> Go to the start of the file ,same as fseek(fp ,0,SEEK_SET) 
  //6. ftell() -> currrent position of file pointers in bytes 
  //7. fclose()
  //8. feof(fp) //- Returns non-zero if the file pointer has reached the end of the file.
  //9.  

   printf("File write operation \n");

   //3.1 using fprint(),
   //case 1 if file exist,it will overwrite from start of the file  
   //case 2 if file does not exist,file automatically created by fopen 
   FILE *fpw = fopen("samplew.txt","w");
   
   if(fpw == NULL)
   {
		printf("File open for write fpw failed \n");
		return -1;	
   }
   
   //3.1 fprintf()
   printf("File write operation for a existing file using printf\n");
   float pi = 3.14;
   
   fprintf(fpw,"fprintf for writing to a existing file, pi = %0.2f\n",pi);
   

   fclose(fpw);
   
   
   //3.1 using fprint(), 
   //case 2 if file does not exist,a new file automatically created first by fopen 
   FILE *fpww = fopen("samplenotexit.txt","w");
   
   if(fpww == NULL)
   {
		printf("File open for write fpww failed \n");
		return -1;	
   }
   
   //3.1 fprintf()
   printf("File write operation for non existing file using printf file position(fpww) = %d\n",ftell(fpww));

   char *name = "Sanjeet"; //scanf
   int empno = 9019; //scanf 
   float sal = 9343.56;
   
   
   fprintf(fpww,"File write using first way fprintf\n",name);
   fprintf(fpww,"My name is %s \n",name);
   printf("My name is %s \n",name);
   fprintf(fpww,"employee number %d \n",empno);
   printf("employee number %d \n",empno);
   fprintf(fpww,"salary is %0.2f \n",sal);
   printf("salary is %0.2f \n",sal);
   
   printf("samplenotexit.txt file position(fpww) after fprintf = %d\n",ftell(fpww));
  
   //2nd way to write the programm fgetc()
   int prev = 0;
   printf("File operation using fgetc ,break loop enter #\n");
   while(ch = getchar())
   {
	  //this is exist condition for while loop   
	  if(ch == '#' && prev =='\n')
	  {
		break;
	  }
      fputc(ch,fpww);
	  prev = ch;//new line \n 
   }	 

   printf("samplenotexit.txt file position(fpww) after fputc = %d\n",ftell(fpww));
   //3rd way to write the programm
   fputs("File write using third way fputs\n",fpww);   
   printf("File write using third way fputs\n");  
   fputs("My name is Roy\n",fpww);  
   printf("My name is Roy\n");    
   fputs("Address 104,dublin,ireland\n",fpww);  
   printf("Address 104,dublin,ireland\n");     
   fputs("salary  3423.455 dollar\n",fpww); 
   printf("salary  3423.455 dollar\n");  
   printf("samplenotexit.txt file position(fpww) after fgets = %d\n",ftell(fpww));   
   fclose(fpww);
   
   
   //Append operation 
     //case 1 if file exist,it will writing from start of the file  
   //case 2 if file does not exist,file automatically created by fopen 
   FILE *fpa = fopen("appendfile.txt","a");
   
   if(fpa == NULL)
   {
		printf("File open for append fpa failed \n");
		return -1;	
   }
   
   //Append means writing into the file at the end of the file 
   printf("appendfile.txt file position(fpa) before fputs append = %d\n",ftell(fpa));   
   fputs("File appendfile.txt Append using fputs \n",fpa);   
   printf("File append using fputs\n");  
   fputs("My name is Simbha\n",fpa);  
   printf("My name is Simbha\n");    
   fputs("Address 105,London,UK\n",fpa);  
   printf("Address 105,London,UK\n");     
   fputs("salary  500.455 dollar\n",fpa); 
   printf("salary  500.455 dollar\n");  
   printf("appendfile.txt file position(fpa) after fputs append = %d\n",ftell(fpa));  

   fclose(fpa);   

   //r+ -> read file then write 

   FILE *fprplus = fopen("sample.txt","r+");
	
	//read using fgets 
	//write the file at the end using fputs 
    //w+ -> write file then read 
    FILE *fpwplus = fopen("samplew.txt","w+");
	
	//write  using fputs 
	//read the file using fgets
	
	//feof(fp)
   //- Returns non-zero if the file pointer has reached the end of the file.
    //ferror(fp)
    //- Returns non-zero if there's an error in the file stream.

	
	
    return 0;	
}