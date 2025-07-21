/*******************************************************
*                                                     *
* Author       : Sanjeet Prasad                       *
* Email        : sanjeet8.23@gmail.com                *
* Description  : Demonstrates various C input/output   *
*                methods including scanf, getchar,     *
*                gets, fgets, sscanf, sprintf,         *
*                putchar, and puts                     *
* Created On   : 9th May 2025                         *
* Compiler     : GCC 14.2.0                           *
* Standard     : C99                                  *
*                                                     *
*******************************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
    // 🎯 Basic input using scanf, getchar, and putchar
    char name[50];     // String input
    int age;           // Integer input
    char grade;        // Single character input

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your age: ");
    scanf("%d", &age);

    getchar();  // Clear leftover newline from buffer

    printf("Enter your grade (single character): ");
    grade = getchar();

    printf("\n--- User Input Summary ---\n");
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Grade: %c\n", grade);
    printf("Grade printed with putchar: ");
    putchar(grade);
    printf("\n\n");

    // 🎯 Parsing structured input from string using sscanf & sprintf
    char roydetails[] = "Rakesh 20 2456.56";
    char parsedName[20];
    int parsedAge;
    float parsedSalary;
    char output[100];

    sscanf(roydetails, "%s %d %f", parsedName, &parsedAge, &parsedSalary);

    printf("--- Parsed String Data ---\n");
    printf("Name: %s\n", parsedName);
    printf("Age: %d\n", parsedAge);
    printf("Salary: %.2f\n", parsedSalary);

    sprintf(output, "Name: %s Age: %d Salary: %.2f", parsedName, parsedAge, parsedSalary);
    printf("Formatted string with sprintf:\n%s\n\n", output);

    // ⚠️ gets() is unsafe, so we demonstrate fgets() instead
    char safeName[50];
    printf("Enter your full name using fgets: ");
    getchar();  // Clear buffer again before using fgets
    fgets(safeName, sizeof(safeName), stdin);
    printf("Hello, ");
    puts(safeName);

    // 📝 Reading a word with scanf into a char buffer
    char keyword[50];
    printf("Enter a keyword: ");
    scanf("%s", keyword);
    printf("You entered: %s\n", keyword);

    return 0;
}