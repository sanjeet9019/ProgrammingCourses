/*******************************************************
*                                                     *
* Author       : Sanjeet Prasad                       *
* Email        : sanjeet8.23@gmail.com                *
* Description  : Demonstrates various C I/O methods    *
*                including scanf, getchar, gets,       *
*                fgets, sscanf, sprintf, fprintf       *
* Created On   : 2nd May 2025                         *
* Compiler     : GCC 14.2.0                           *
* Standard     : C99                                  *
*                                                     *
*******************************************************/

#include <stdio.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
	char name[20];  // String input
	int age;        // Integer input
	char grade;     // Single character input

	// Using printf() to display output
	printf("Enter your name: ");
	scanf("%s", &name);  // Using scanf() to read a string

	printf("Enter your age: ");
	scanf("%d", &age);  // Using scanf() to read an integer

	char newline = getchar();  // To clear the newline left in the buffer
	printf("newline: %d\n", newline); 

	printf("Enter your grade: ");
	grade = getchar();  // Using getchar() to read a single character

	printf("\nYour details:\n");  
	printf("Name: %s\n", name);  
	printf("Age: %d\n", age);  
	printf("Grade: ");
	putchar(grade);  // Using putchar() to display a single character
	printf("\n");


	char inputData[100] = "25 3.14 Engineer"; // Space-separated values
	char output[100];		          // Space separated
	int agee;
	float pi;
	char profession[20];

	sscanf(inputData,"%d %f %s",&agee,&pi,&profession);

	printf("Age = %d, Pi value = %0.2f,Profession = %s\n",agee,pi,profession);

	sprintf(output,"Age = %d, Pi value = %0.2f,Profession = %s",agee,pi,profession);
	printf("%s", output);
	
	getchar();
	
	char name1[50];  // Buffer to store input

    printf("Enter your name using gets : ");
    gets(name1);  // Unsafe input method

    puts(name1);
    printf("Hello, %s!\n", name1);


	char name2[50];  // Buffer to store input
	
	printf("Enter your name using fgets: ");
	fgets(name2,50,stdin);
	puts(name2);
	
	fprintf(stdout, "This is standard output\n");  // Proper stdout usage
	fprintf(stderr, "This is standard Error \n");  // Proper stdout usage
	return 0;
}
