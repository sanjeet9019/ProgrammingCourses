/*******************************************************
*                                                     *
* Author        : Sanjeet Prasad                      *
* Email         : sanjeet8.23@gmail.com               *
* Description   : Demonstrates the use of structures  *
*                 in C, including declaration,        *
*                 initialization, nested structures,  *
*                 dynamic memory allocation for       *
*                 structure objects, and passing      *
*                 structures to and from functions    *
*                 via value and pointer references.   *
* Created On    : 06th June 2025                      *
* Compiler      : GCC 14.2.0                          *
* Standard      : C99                                 *
*                                                     *
*******************************************************/

#include<stdio.h>
#include<stdlib.h>//dynamic memory allocation malloc()
#include<string.h>



/* 	//Rakesh i want to represent you 
	Name = Rakesh    char name[20]
	Designation = SW engg   char designation[20]
	City place = Chennai   char city[] 
	Age = 22   int Age;
	Height = 170   float height ;
	salary = 90,545.70   float salary ;
	
	
	//Amazon 
	Name = Amazon   char companyname[20]
	Nos of emmployee = 20000  int nosofemployee
	Nos of office = 40 int officecount ;
	Dapartment = {"engineering","Marketing","HR"}   char department[3][20]/char *department[3] /char **department */

/* struct Rakesh
{
   char name[20];//name 
   char designation[20];//sw engg 
   char city[20] ;//City place = Chennai   
   int Age;//Age = 22   
   float height ;//Height = 170   
   float salary ;//salary = 90,545.70   
}; */

struct Cityinfo
{
   int pincode;
   char cityname[20];  
};


struct Person
{
   char name[20];//name  
   int Age;//Age = 22     
   float salary ;//salary = 90,545.70  
   struct Cityinfo personcity;  //nested structure 
   //int pincode;
   //char cityname[20];  
};

void struct_passfuntyp1(struct Person Rakeshinfo);
void struct_passfuntyp2(struct Person *Rakeshinfoptr);
struct Person struct_passfuntyp3();
struct Person* struct_passfuntyp4();

void struct_passfuntyp1(struct Person Rakeshinfo)
{
	printf("struct_passfuntyp1 = Rakeshinfo  = name = %s Age = %d Salary =%0.2f\n",Rakeshinfo.name,Rakeshinfo.Age,Rakeshinfo.salary);	
}

void struct_passfuntyp2(struct Person *Rakeshinfoptr)
{
	printf("struct_passfuntyp2 = Rakeshinfoptr  = name = %s Age = %d Salary =%0.2f\n",Rakeshinfoptr->name,Rakeshinfoptr->Age,Rakeshinfoptr->salary);	
}

struct Person struct_passfuntyp3()
{
	struct Person Royinfo = {.name = "roy ",.Age = 24,.salary = 3445.55};
	return Royinfo;
}

struct Person* struct_passfuntyp4()
{
	struct Person *Royinfoptr = (struct Person* )malloc(1*sizeof(struct Person));//static one 
	
	if(Royinfoptr == NULL)
	{
		printf("Malloc fail\n");
		return NULL;
	}
	strcpy(Royinfoptr->name,"Roy ptr");
	Royinfoptr->Age = 20;
	Royinfoptr->salary = 3444.556;
	return Royinfoptr;
/* 	
	int a = 10;//4 bytes 
	int *ptr = &a; //static memory 
	int *ptr1 = malloc(); //dynamic memory */ 
}

/* struct Person* struct_passfuntyp5()
{
	struct Person Royinfo1 = {.name = "roy ",.Age = 24,.salary = 3445.55};
	return &Royinfo;
}
 */

int main(int argc ,char *argv[])
{

   //First way to use struct assigment ,initialize 
   struct Person Rakesh = {"Rakesh",22,70000.67} ;  //int a ;Rakesh is variable what type struct Person
	
   //Access struct element 
   printf("First way struct Person Rakesh	- name = %s age = %d salary = %0.2f\n",Rakesh.name,Rakesh.Age,Rakesh.salary);
   
   
   struct Person Roy = {"Roy",24,90000.67} ;  //int a ;Roy is variable what type struct Person
	
   //Access struct element 
   printf("First way struct Person Roy	- name = %s age = %d salary = %0.2f\n",Roy.name,Roy.Age,Roy.salary);
   
   
   
   //Second way to struct 
   struct Person Sanjeet; //static or compile time memory allocation 
   //Sanjeet.name = "Sanjeet"
   strcpy(Sanjeet.name ,"Sanjeet");
   Sanjeet.Age = 28;
   Sanjeet.salary = 10000.45;
   
   //Access struct element 
   printf("Second way struct Person Sanjeet	- name = %s age = %d salary = %0.2f\n",Sanjeet.name,Sanjeet.Age,Sanjeet.salary);
	 

   //3rd way of initiaze struct ----> This is latest C99 ,recommended to use in your coding 
   struct Person Simba = {.name = "Simba",.Age = 4,.salary = 0.0}; ////static or compile time memory allocation
    
   //Access struct element	
   printf("Third way struct Person Simba	- name = %s age = %d salary = %0.2f\n",Simba.name,Simba.Age,Simba.salary);
   
   struct Person *ptr = &Sanjeet; //this is again compile time or static memory 
   struct Person *ptrRakesh = &Rakesh; 
   
    //Access struct element	
   printf("Using pointer struct Person Sanjeet- name = %s age = %d salary = %0.2f\n",ptr->name,ptr->Age,ptr->salary);
   
   //Using dynamic struct allocation 
   //using scanf you pass this number 1 or 2 or 4 
   struct Person *ptrmalloc =  (struct Person *)malloc(1*sizeof(struct Person));// 1 struct value = struct Person ptrmalloc[1];
   
   if(ptrmalloc == NULL)
   {
	 printf("Malloc fail struct\n");
     return -1;	 
   }
	   
   strcpy(ptrmalloc->name,"Sanjeet Prasad");//in case of string copy always use strcpy 
   ptrmalloc->Age = 30;
   ptrmalloc->salary = 4556.88;
   
   //Access struct element	
   printf("Using pointer dynamic memory malloc struct Person Sanjeet- name = %s age = %d salary = %0.2f\n",ptrmalloc->name,ptrmalloc->Age,ptrmalloc->salary);


  struct Person arrayper[3] = {
	  {.name = "Simba",.Age = 4,.salary = 0.0},	  //first element  
	   {.name = "Sanjeet",.Age = 40,.salary = 55660.60},
	    {.name = "Rakesh",.Age = 30,.salary = 99999.60},
  };
   
   for(int i =0;i<3;i++)
   {
	  printf("Array of struct Person name = %s age = %d salary = %0.2f\n",arrayper[i].name,arrayper[i].Age,arrayper[i].salary); 
   }
   
   //nested structure 
   struct Person  Rakeshinfo = { .name = "Rakesh Kumar",.Age = 30,.salary = 4456.77,.personcity = {.pincode = 110001,.cityname = "Chennai"}};
   
   printf("Nested struct Person Rakeshinfo	- name = %s age = %d salary = %0.2f pincode = %d cityname = %s\n",Rakeshinfo.name,Rakeshinfo.Age,Rakeshinfo.salary,Rakeshinfo.personcity.pincode,Rakeshinfo.personcity.cityname);
   
   
   //Passing structure in the function 
   
   //Type1 pass by value 
   struct_passfuntyp1(Rakeshinfo);
   
   //Type2 pass by address 
   struct_passfuntyp2(&Rakeshinfo);
   
   //Type3  
   struct Person Royinfo = struct_passfuntyp3();
   printf("struct_passfuntyp3 = Royinfo  = name = %s Age = %d Salary =%0.2f\n",Royinfo.name,Royinfo.Age,Royinfo.salary);

   //Type4  
   struct Person *Royinfoptr = struct_passfuntyp4();
   printf("struct_passfuntyp4 = Royinfoptr  = name = %s Age = %d Salary =%0.2f\n",Royinfoptr->name,Royinfoptr->Age,Royinfoptr->salary);   
   
   
   return 0;
}

