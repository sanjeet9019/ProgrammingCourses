/****************************************************************************
* Name - World Clock Utility (sanjeet8.23@gmail.com)
* Description - This C-based World Clock Utility provides a real-time display
*               of the current time across multiple global time zones.
*               Leveraging UTC as a central reference, the program employs
*               control flow and looping structures to continuously update
*               and present the time in a clear and formatted manner. Its
*               modular design allows for easy addition of new time zones,
*               making it suitable for both practical real-time monitoring
*               and educational demonstrations of time zone calculations.
* Date - 18th May 2025
****************************************************************************/

#include "world_clock.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// Global list of countries with time zone configurations
Country countries[NUM_COUNTRIES] = {
    {"China", 8, 0, 0},
    {"India", 5, 30, 0},
    {"United Kingdom", 0, 0, 1},
    {"Argentina", -3, 0, 0},
    {"Saudi Arabia", 3, 0, 0}
};

/**
 * Fetches the current UTC system time.
 */
void getCurrentUTC(struct tm **utc_time) {
    time_t rawtime = time(NULL);
    *utc_time = gmtime(&rawtime);
}

/**
 * Normalizes minutes into [0–59] and adjusts hour if overflow or underflow occurs.
 */
int normalizeMinutes(int *hour, int minute) {
    if (minute >= 60) {
        (*hour)++;
        minute -= 60;
    } else if (minute < 0) {
        (*hour)--;
        minute += 60;
    }
    return minute;
}

/**
 * Normalizes hour into [0–23] and calculates day transition (±1).
 */
int normalizeHours(int *hour, int *day_offset) {
    if (*hour >= 24) {
        *hour -= 24;
        *day_offset = 1;
    } else if (*hour < 0) {
        *hour += 24;
        *day_offset = -1;
    } else {
        *day_offset = 0;
    }
    return *hour;
}

/**
 * Converts 24-hour time to 12-hour format and sets AM/PM label.
 */
int convertTo12Hour(int *hour, char *period) {
    if (*hour >= 12) {
        strcpy(period, "PM");
        if (*hour > 12) *hour -= 12;
    } else {
        strcpy(period, "AM");
        if (*hour == 0) *hour = 12;
    }
    return *hour;
}

/**
 * Computes local time for a country from UTC using offset and DST,
 * then normalizes for overflow and 12-hour formatting.
 */
void computeLocalTime(const struct tm *utc, const Country *ctry,
                      int *hour, int *minute, int *day_offset, char *period) {
    *hour = utc->tm_hour + ctry->utc_offset_hours + ctry->dst_active;
    *minute = utc->tm_min + ctry->utc_offset_minutes;

    *minute = normalizeMinutes(hour, *minute);
    *hour = normalizeHours(hour, day_offset);
    convertTo12Hour(hour, period);
}

/**
 * Computes calendar date after applying day transition (next, prev, or none).
 * Simplified to assume each month has 30 days.
 */
void formatLocalDate(const struct tm *utc, int day_offset,
                     int *day, int *month, int *year) {
    *day = utc->tm_mday + day_offset;
    *month = utc->tm_mon;
    *year = utc->tm_year + 1900;

    // Basic rollover logic
    if (*day <= 0) {
        (*month)--;
        if (*month < 0) {
            *month = 11;
            (*year)--;
        }
        *day = 30;
    } else if (*day > 30) {
        (*month)++;
        if (*month > 11) {
            *month = 0;
            (*year)++;
        }
        *day = 1;
    }
}

/**
 * Displays the final formatted string for a country's local time.
 */
void displayFormattedTime(const Country *ctry, const struct tm *utc,
                          int hour, int minute, const char *period,
                          int day, int month, int year) {
    printf("%-15s: %s, %02d %s %d - %02d:%02d %s (%s, %s)\n",
           ctry->name,
           days[utc->tm_wday],
           day, months[month], year,
           hour, minute, period,
           "Today",  // Could dynamically show "Next Day" or "Previous Day"
           ctry->dst_active ? "DST Active" : "Standard Time");
}

/**
 * Coordinates time computation, date formatting, and display for a single country.
 */
void processCountryTime(const Country *ctry, const struct tm *utc) {
    int hour, minute, day_offset;
    char period[3];
    computeLocalTime(utc, ctry, &hour, &minute, &day_offset, period);

    int day, month, year;
    formatLocalDate(utc, day_offset, &day, &month, &year);

    displayFormattedTime(ctry, utc, hour, minute, period, day, month, year);
}

/**
 * Iterates through all countries and prints their current local time.
 */
void displayWorldClock(void) {
    struct tm *utc_time;
    getCurrentUTC(&utc_time);
    printf("\nWorld Clock:\n");
    for (int i = 0; i < NUM_COUNTRIES; i++) {
        processCountryTime(&countries[i], utc_time);
    }
}

/**
 * Application entry point – updates the world clock display every second.
 */
int main(void) {
    while (1) {
        displayWorldClock();
        printf("\nUpdating in 1 second...\n");
        sleep(1);
    }
    return 0;
}