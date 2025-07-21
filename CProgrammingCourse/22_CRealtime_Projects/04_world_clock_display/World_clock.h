/****************************************************************************
* Name        - World Clock Utility (sanjeet8.23@gmail.com)
* Description - Header file for the World Clock Utility in C.
*               Defines country structure, constants, and function prototypes.
*               Facilitates modular design by separating interface definitions
*               from implementation. Includes declarations for UTC retrieval,
*               localized time computation, and formatted display.
* Date        - 18th May 2025
****************************************************************************/

#ifndef WORLD_CLOCK_H
#define WORLD_CLOCK_H

#include <time.h>

#define NUM_COUNTRIES 5
#define MAX_NAME 50

// Structure to represent a country's time zone settings
typedef struct {
    char name[MAX_NAME];
    int utc_offset_hours;         // Hour component of UTC offset
    int utc_offset_minutes;       // Minute component of UTC offset
    int dst_active;               // Daylight Saving flag: 1 = active, 0 = inactive
} Country;

const char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
const char *months[] = {"January", "February", "March", "April", "May", "June",
                        "July", "August", "September", "October", "November", "December"};

// Time retrieval and normalization
void getCurrentUTC(struct tm **utc_time);
int normalizeMinutes(int *hour, int minute);
int normalizeHours(int *hour, int *day_offset);
int convertTo12Hour(int *hour, char *period);

// Time and date formatting
void computeLocalTime(const struct tm *utc, const Country *ctry,
                      int *hour, int *minute, int *day_offset, char *period);
void formatLocalDate(const struct tm *utc, int day_offset,
                     int *day, int *month, int *year);
void displayFormattedTime(const Country *ctry, const struct tm *utc,
                          int hour, int minute, const char *period,
                          int day, int month, int year);

// Display control
void processCountryTime(const Country *ctry, const struct tm *utc);
void displayWorldClock(void);

#endif // WORLD_CLOCK_H