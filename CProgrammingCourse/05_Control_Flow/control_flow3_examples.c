/*******************************************************
*                                                     *
* Author       : Sanjeet Prasad                       *
* Email        : sanjeet8.23@gmail.com                *
* Description  : Demonstrates control flow using loops *
*                in C, including for, while, do-while, *
*                with examples of break and continue   *
* Created On   : 16th May 2025                        *
* Compiler     : GCC 14.2.0                           *
* Standard     : C99                                  *
*                                                     *
*******************************************************/

#include <stdio.h>

int main(int argc ,char *argv[])
{
    // 🚀 Print numbers from 1 to 5 using a for loop
    printf("Counting from 1 to 5 using for loop:\n");
    for(int i = 1; i <= 5; i++)
    {
        printf("i = %d\n", i);
    }

    // ✖️ Multiplication table using for loop
    int number = 9;
    printf("\nMultiplication table of %d:\n", number);
    for(int factor = 1; factor <= 10; factor++)
    {
        printf("%d x %d = %d\n", number, factor, number * factor);
    }

    // 💧 Water tank fill simulation using while loop
    int watertankcapacity = 100;
    int waternow = 0;
    printf("\nWater tank filling status:\n");
    while(waternow <= watertankcapacity)
    {
        printf("Water level: %d liters\n", waternow);
        waternow += 10;
    }
    printf("Tank is full!\n");

    // ⛽ Fuel consumption simulation using while loop
    int fuel = 50;
    printf("\nFuel status while driving:\n");
    while(fuel >= 0)
    {
        printf("Fuel remaining: %d liters\n", fuel);
        fuel -= 5;
    }
    printf("Out of fuel! Time to refill.\n");

    // 🔐 Password validation using do-while loop
    int correctpass = 1234;
    int enterpass = 0;
    do {
        printf("\nEnter your laptop password: ");
        scanf("%d", &enterpass);
    } while(enterpass != correctpass);
    printf("Access granted.\n");

    // 🛑 Break statement demonstration
    printf("\nBreak at value 5 in for loop:\n");
    for (int i = 1; i <= 10; i++)
    {
        if (i == 5)
        {
            printf("Break condition met at i = %d\n", i);
            break;
        }
        printf("i = %d\n", i);
    }

    // 🧾 Running total using break in infinite while loop
    int price = 0, total = 0;
    printf("\nEnter item prices. Enter negative value to stop:\n");
    while(1)
    {
        scanf("%d", &price);
        if(price < 0)
        {
            printf("Negative price entered. Stopping input.\n");
            break;
        }
        total += price;
    }
    printf("Total price of items: %d\n", total);

    // 🔁 Continue statement to skip even numbers
    printf("\nPrinting odd numbers from 1 to 10:\n");
    for(int i = 1; i <= 10; i++)
    {
        if(i % 2 == 0)
            continue;
        printf("Odd number: %d\n", i);
    }

    return 0;
}