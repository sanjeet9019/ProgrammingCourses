/*******************************************************
*                                                     *
* Author       : Sanjeet Prasad                       *
* Email        : sanjeet8.23@gmail.com                *
* Description  : Comprehensive demo of C operators     *
*                including arithmetic, logical,        *
*                relational, bitwise, and expressions  *
* Created On   : 7th May 2025                         *
* Compiler     : GCC 14.2.0                           *
* Standard     : C99                                  *
*                                                     *
*******************************************************/

#include<stdio.h>
#include <stdbool.h>

#define PI 3.14

int main(int argc ,char *argv[])
{
    //Arithmetic operators 
	
	int num1 = 20;
	int num2 = 10;
	int result = 0; //int result ; uniniatize variable 
	
	printf("Arithmetic Operations\n");
	
	//Addition 
	result = num1 + num2 ;
	printf("Addition = %d\n",result);
	
	//Subtraction 
	result = num1 - num2 ;
	printf("Subtraction = %d\n",result);
	
	
	//Multiplation 
	result = num1*num2 ;
	printf("Multiplation = %d\n",result);
	
	//Division 
	result = num1/num2 ;
	printf("Division = %d\n",result);
	
    //Modulus  
	result = num1%num2 ; //11/2 = 1 remainder 
	printf("Modulus = %d\n",result);
	
	result = 10-5*2;
	printf("result = %d\n",result);
	
	//Discount 
	int original = 100;
	int discount = 20;
	
	int finalprice = original - (discount*original)/100;
	
	printf("finalprice after discount = %d\n",finalprice);
/* 	
	Discount Price = Original Price - Discount * Original Price / 100;
   Area of a Circle (A = πr²)
   Simple Interest (SI = (P * R * T) / 100)
   Area of a Triangle (A = (1/2) * base * height)
   Speed Formula (Speed = Distance / Time)
   Force Formula (F = m × a)
   Kinetic Energy (KE = 0.5 × m × v²)
 */
   //Area of a Circle (A = πr²)
   
   float areaOfCircle = 0.0;
   float radius = 5.0;
   
   areaOfCircle = (PI*radius*radius);
   
   printf("Area of a Circle = %0.2f\n",areaOfCircle);
   
   //Simple Interest (SI = (P * R * T) / 100)
   float simpleInterest = 0.0; 
   float principal = 1000.45;
   float rateOfInterest = 8.5;//percentage 
   float time = 2.5 ;//years 

   simpleInterest = (principal * rateOfInterest * time)/100;
   
   printf("simpleInterest = %0.2f\n",simpleInterest);
   
   
   //Relationship operations or comparsion operators 
   	num1 = 10;
	num2 = 5;
    bool Result = false;

	Result = (num1 == num2); //false = 0
	printf("(num1 == num2) = %d\n",Result);
	Result = (num1 > num2); //true = 1
	printf("(num1 > num2) = %d\n",Result);
	Result = (num1 < num2); //false = 0 
	printf("(num1 < num2) = %d\n",Result);
	Result = (num1 >= num2); //true = 1 
	printf("num1 >= num2) = %d\n",Result);
   
   
    //Logical Operators 
	num1 = 10;//Non zero 
	num2 = 20; //Non zero 
	                                            // int temp = 42 ; delhi 
	Result = (num1 && num2);//Logical AND      ((temp > 40) && (temp <50))  = summer in delhi 
	printf("num1 && num2) = %d\n",Result);//true only of both the operands are non zero else false 
	
	Result = (num1 || num2); //Logical OR 
	printf("(num1 || num2) = %d\n",Result);//true 
	
	Result = (!num2); //Logical NOT operators 
	printf("(!num2) = %d\n",Result);//true 
	
	//Assigment operators 
	int temperature = 50 ;//degree 
	temperature+=10;//temperature = temperature + 10;
	temperature = temperature + 10;//recommendation to use this reason being it is easy to understand the code 
	printf("temperature+= = %d\n",temperature); 
	temperature-=10;//temperature = temperature - 10;
	printf("temperature-= = %d\n",temperature); 
	temperature/=10;//temperature = temperature / 10;
	printf("temperature/= = %d\n",temperature); 
	
	int x = 5 ;
	
	printf("Value of x = %d\n",x);
	
	printf("Value of ++x = %d\n",++x);//prefix increment operator ,it will do at the same time +1 ++x ,x = x +1 
	
	printf("Value of x++ = %d\n",x++);//post fix increment operator ,it will do +1 in next line ,x++ , x = x+ 1
	
	printf("Value of x++ after next line = %d\n",x);
	
	x = 8;
	
	printf("Value of --x = %d\n",--x);//prefix increment operator ,it will do at the same time -1 x ,x = x -1 
	
	printf("Value of x-- = %d\n",x--);//post fix increment operator ,it will do +1 in next line ,x++ , x = x- 1
	
	printf("Value of x-- after next line = %d\n",x);
	
	
	//Bitwise operators 
	int a = 5;  //0000 0101  4 bytes = 32 bits 
	int b = 3;  //0000 0011
	int c = -5; //1111 1011 = 2 complement 
	
	result = (a&b); //and operator 0000 0101 & 0000 0011
	
/* 	0000 0101
   &0000 0011
---------------
    0000  0001 = 1 MSB = 0 ,+ve  */
	
	printf("Bitwise and operator = %d\n",result);
	
	result = (a&c);//and 
	
/* 	0000 0101 a
&	1111 1011 c
---------------
    0000 0001 */
	         
	printf("Bitwise and operator = %d\n",result);	
	
	result = (a|b); //and operator 0000 0101 & 0000 0011
	
/* 	0000 0101
   |0000 0011
---------------
    0000 0111 ,0 = +ve  */	
	
	printf("Bitwise or operator = %d\n",result);
	
	result = (a|c);//or 
/* 	0000 0101 a
   |1111 1011 c
---------------
    1111 1111     1 = -ve  
	
	
	1111 1111 = 2 complement form 
	
	1.1111 1111  = 0000 0000 reverse the number 
	2.0000 0000 + 1 = 0000 0001 = -1 
	
	*/
    
	printf("Bitwise or operator = %d\n",result);
	
	
	result = (a^b);//xor 
	
	
	/* 0000 0101  a
   ^   0000 0011  b
---------------
       0000 0110    = 1 MSB = 0 ,+ve  */
	   
	   printf("Bitwise xor operator = %d\n",result);
	   
	   result = ~(a);   //1 complement /not bitwise operators = reverse the bits  -(num+1)
	
	
	/* 0000 0101  a
	   1111 1010  output  = 2 complement form *    11111111  11111111 11111111  11111010*/ 
	   
	   printf("Bitwise not operator = %d\n",result);
	   
	   a = 99 ;
	   
	   result = ~(a);   //1 complement /not bitwise operators = reverse the bits  -(num+1)
	
	   printf("Bitwise not operator = %d\n",result);
	   
	   a = 5; //0000 0101 
	   //Left shift operation 
	   result = a << 3;
	
	   //0000 0101  -->  0000 1010 by  1 = 10  = 5*2
	   //0000 0101  -->  0001 0100 by  2 = 20  = 5*4
	   //0000 0101  -->  0001 0100 by  3 = 40  = 5*8
	   printf("Bitwise left shift operator = %d\n",result);
	   
	   
	   a = 127 ;//input by roy     00000000 00000000 00000000 0111 1111
	   result = a << 1;//input by roy 0111 1111  =    1111 1110=  127*2 
	   
	   result = a << 2;//input by roy 0111 1111  =    1111 1100=  127*4
	   
	   
	   printf("Bitwise left shift operator = %d\n",result);
	   
	   a = 5;
	   int multiply3 = 0 ;
	   
	   multiply3 = (a << 1) + a; // 5*3 
	   
	   printf("Bitwise left shift operator multiply 3 = %d\n",multiply3);
	   
	   int multiply6 = (a << 2) + (a<<1); // 5*3 
	   
	   printf("Bitwise left shift operator multiply 6 = %d\n",multiply6);
	   
	   a = 10; //0000 0101 
	   //Right shift operation 
	   result = a >> 1;  //  0000 0010 
	   printf("Bitwise right shift operator  = %d\n",result);
	   
	   signed char schar = 129 ;
	   unsigned char unschar = -1 ; //11111111
	   




	   
	   return 0;
	
}
