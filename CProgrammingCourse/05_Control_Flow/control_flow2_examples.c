/*******************************************************
*                                                     *
* Author       : Sanjeet Prasad                       *
* Email        : sanjeet8.23@gmail.com                *
* Description  : Demonstrates control flow in C using  *
*                if-else, switch-case, and enums       *
* Created On   : 14th May 2025                        *
* Compiler     : GCC 14.2.0                           *
* Standard     : C99                                  *
*                                                     *
*******************************************************/

#include <stdio.h>

// Define enums for readability
enum Days { MON, TUE, WED, THU, FRI, SAT, SUN };
enum Traffic { RED, GREEN, YELLOW };
enum Calculation { ADD, SUB, MUL, DIV };
enum Result { FIRST, SECOND, THIRD };

int main(int argc, char *argv[])
{
    // ✨ Check number positivity
    int num = 0;
    if (num > 0)
        printf("Number is positive: %d\n", num);
    else if (num < 0)
        printf("Number is negative: %d\n", num);
    else
        printf("Number is zero: %d\n", num);

    // 🚘 Sensor-based driving decision
    int sensordistance = 30;
    if (sensordistance >= 100)
        printf("Drive safe, enjoy your ride\n");
    else if (sensordistance >= 50)
        printf("Drive slow, reduce speed\n");
    else
        printf("Apply brake!\n");

    // 📆 Day-based activity using switch-case
    enum Days today = TUE;
    switch (today)
    {
        case MON:
            printf("Today is Monday\n");
            break;
        case TUE:
            printf("Today is Tuesday\n");
            printf("Exercise day!\n");
            break;
        case WED:
            printf("Midweek: It's Wednesday\n");
            break;
        case THU:
            printf("It's Thursday\n");
            break;
        case FRI:
            printf("Friday vibes!\n");
            break;
        case SAT:
            printf("Weekend begins: Saturday\n");
            break;
        case SUN:
            printf("Sunday rest day\n");
            break;
        default:
            printf("Invalid day input\n");
    }

    // ➕ Switch-case for a math operation
    enum Calculation type = ADD;
    switch (type)
    {
        case ADD: {
            int a = 10, b = 20;
            int c = a + b;
            printf("Addition: %d + %d = %d\n", a, b, c);
            break;
        }
        default:
            printf("Unknown calculation type\n");
    }

    // 🏫 Division result example with if-else and switch
    int numbrs = 1;

    if (numbrs == 1)
        printf("First Division\n");
    else if (numbrs == 2)
        printf("Second Division\n");
    else if (numbrs == 3)
        printf("Third Division\n");
    else
        printf("No Division\n");

    switch (numbrs)
    {
        case 1:
            printf("First Division (switch)\n");
            break;
        case 2:
            printf("Second Division (switch)\n");
            break;
        case 3:
            printf("Third Division (switch)\n");
            break;
        default:
            printf("No Division (switch)\n");
    }

    // 🎓 Grade assessment via switch-case on character
    char ch = 'A';
    switch (ch)
    {
        case 65:  // ASCII value for 'A'
            printf("Grade A (via ASCII)\n");
            break;
        case 'B':
            printf("Grade B\n");
            break;
        default:
            printf("Grade not recognized\n");
    }

    return 0;
}