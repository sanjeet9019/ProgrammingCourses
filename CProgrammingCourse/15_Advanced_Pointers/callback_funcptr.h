#ifndef FUNPTR_H
#define FUNPTR_H

typedef struct axis
{
   int x;
   int y;
}POINT;
typedef int (*FUNPTR)(int a,int b);

//Callback functions examples 
//void MathOperation(int (*funptr)(int a,int b),int num1,int num2);
void MathOperation(FUNPTR funptr,int num1,int num2,const char *operations);

//Step 1 : Function declaration
void greet(void);
int *returnintptr(int a);
void structfunc(POINT p);
POINT structfuncret(POINT p);

//Math operations 
int sub(int a,int b);
int sum(int a,int b);
int mul(int a,int b);
int divide(int a,int b);

typedef void(*START)(void);
typedef void(*STOP)(void);

typedef struct Device
{
   START start;//fun ptr 
   STOP stop;//fun ptr
   char name[50];   
   int status ;	
}DEVICE;

#endif 