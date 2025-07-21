/*******************************************************
*                                                     *
* Author       : Sanjeet Prasad                       *
* Email        : sanjeet8.23@gmail.com                *
* Description  : Demonstrates C control flow           *
*                including if-else, switch, loops,     *
*                break, continue, and goto             *
* Created On   : 2nd May 2025                         *
* Compiler     : GCC 14.2.0                           *
* Standard     : C99                                  *
*                                                     *
*******************************************************/

#include<stdio.h>

enum Days 
{ 
MON, //by default 0 
TUE, 
WED, 
THU, 
FRI, 
SAT, 
SUN 
};

int main(int argc,char *argv[])
{
	
	//Control statement 1 
	int temp = 45 ;//degree
	
	if (temp >= 40) {
		printf("Summer weather \n");
	}
	
	int num = 200;
	
	if (num % 2 == 0) {
		printf("Even Number \n");
	}
	else{
		printf("Odd Number \n");
	}
	
	int percentage = 67;
	
	if (percentage > 60) {
		printf("First Division \n");
	}
	else if(percentage >=45 && percentage <=60){
		printf("Second Division \n");
	}
	else 
	{
	    printf("Fail  \n");
	}

    //Switch case 
	enum Days today = MON;//Assign a value from enum 
	
    switch (today) {
        case MON:
            printf("It's Monday, start of the workweek!\n");
            break;
        case TUE:
            printf("It's Tuesday, let's keep going!\n");
            break;
        case WED:
            printf("It's Wednesday, midweek progress!\n");
            break;
        case THU:
            printf("It's Thursday, weekend is near!\n");
            break;
        case FRI:
            printf("It's Friday, almost there!\n");
            break;
        case SAT:
            printf("It's Saturday, time to relax!\n");
            break;
        case SUN:
            printf("It's Sunday, recharge for the week ahead!\n");
            break;
        default:
            printf("Invalid day!\n");
    }
	
    enum TrafficLight { RED, YELLOW, GREEN };
    enum TrafficLight signal = YELLOW;
    int temperature = 30;

    // Switch-case example
    switch (signal) {
        case RED:
            printf("Traffic Light: Stop!\n");
            break;
        case YELLOW:
            printf("Traffic Light: Get Ready!\n");
            break;
        case GREEN:
            printf("Traffic Light: Go!\n");
            break;
        default:
            printf("Traffic Light: Invalid signal!\n");
    }

    // If-else example
    if (signal == RED) {
        printf("Caution: Stop immediately!\n");
    } else {
        printf("Caution: Proceed carefully!\n");
    }

    // If-else if example
    if (temperature > 35) {
        printf("Weather: It's too hot!\n");
    } else if (temperature >= 25) {
        printf("Weather: Nice warm weather!\n");
    } else {
        printf("Weather: It's cold outside!\n");
    }


	//Control statement 2 
	printf("Control Statement 2\n");
	printf("for loop example print 1-100 \n");
	for (int i = 1; i <= 10; i++) {
        printf("%d\n", i);
    }
	
	printf("for loop example multiplication \n");
	int number = 5; // Change this to any number

    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", number, i, number * i);
    }


    printf("while examples \n");
	printf("Water Tank examples \n");
	
    int waterLevel = 0;  // Initially empty
    int maxCapacity = 100;  // Tank capacity in liters

    while (waterLevel < maxCapacity) {
        printf("Water filling... Current level: %d liters\n", waterLevel);
        waterLevel = waterLevel + 10;  // Simulating water flow
    }

    printf("Tank is full! Stopping water flow.\n");
	

    //printf("Too many incorrect attempts. Access locked!\n");
	
	int fuel = 50;  // Fuel level in liters

    while (fuel > 0) {
        printf("Driving... Fuel left: %d liters\n", fuel);
        fuel -= 5;  // Simulating fuel consumption
    }

    printf("Out of fuel! Car stops.\n");
	

    int correctPassword = 1234;
    int enteredPassword;

    do {
        printf("Enter your password: ");
        scanf("%d", &enteredPassword);
    } while (enteredPassword != correctPassword);

    printf("Access granted!\n");
	
	char confirm;

    do {
        printf("Are you sure you want to delete all files? (y/n): ");
        scanf(" %c", &confirm);
    } while (confirm != 'y');

    printf("Files deleted successfully.\n");

    //break, continue, goto (with a note on when to avoid goto),return 
		
	int items[] = {1, 1, 0, 1, 1};  // 0 = Defective item
    int totalItems = 5;

    for (int i = 0; i < totalItems; i++) {
        if (items[i] == 0) {
            printf("Fault detected! Stopping production at item %d.\n", i);
            break;  // Stop the assembly line
        }
        printf("Producing item %d\n", i);
    }
	
	int seats[] = {1, 0, 1, 0, 1};  // 0 = Occupied, 1 = Available
    int totalSeats = 5;

    printf("Available seats for booking:\n");

    for (int i = 0; i < totalSeats; i++) {
        if (seats[i] == 0) {
            continue;  // Skip occupied seats
        }
        printf("Seat %d is available\n", i);
    }

    int smokeDetected = 1;  // 1 = Yes, 0 = No

    if (smokeDetected) {
        goto emergency;
    }

    printf("Normal operation.\n");
    return 0;

//Label 
emergency:
    printf("WARNING: Fire detected! Evacuate immediately!\n");
   	return 0;
}
