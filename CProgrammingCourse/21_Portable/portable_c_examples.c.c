/*******************************************************
 * Author        : Sanjeet Prasad                      *
 * Email         : sanjeet8.23@gmail.com               *
 * Filename      : portable_c_examples.c               *
 * Description   : Demonstrates cross-platform C coding*
 *                 concepts including fixed-width types*
 *                 file path construction, sleep APIs, *
 *                 platform-specific logging, and CLI  *
 *                 parsing techniques.                 *
 * Created On    : 14th July 2025                      *
 *******************************************************/


#include <stdio.h>
#include <stdint.h>     // Fixed-width integer types
#include <inttypes.h>   // Format specifiers

#ifdef _WIN32
    #include <windows.h>
    #define PATH_SEPARATOR "\\"
    #define LOG_FILE "logs\\winlog.txt"
#else
    #include <unistd.h>
    #define PATH_SEPARATOR "/"
    #define LOG_FILE "logs/unixlog.txt"
#endif

// Function to sleep for given seconds, cross-platform
void portable_sleep(int seconds) {
#ifdef _WIN32
    Sleep(seconds * 1000);  // milliseconds
#else
    sleep(seconds);         // seconds
#endif
}

int main(int argc, char *argv[]) {
    // ✅ Example 1: Fixed-width integer and portable printf
    int32_t count = 42;
    printf("Fixed-width int32_t value: %" PRId32 "\n", count);

    // ✅ Example 2: File path construction
    char fullPath[100];
    snprintf(fullPath, sizeof(fullPath), "logs%soutput.txt", PATH_SEPARATOR);
    printf("Constructed path: %s\n", fullPath);

    // ✅ Example 3: Portable sleep demo
    printf("Sleeping for 2 seconds...\n");
    portable_sleep(2);
    printf("Awake again!\n");

    // ✅ Example 4: Platform-specific logging
    FILE *log = fopen(LOG_FILE, "w");
    if (log == NULL) {
        perror("Failed to open log file");
    } else {
        fprintf(log, "This is a platform-specific log file.\n");
        fclose(log);
        printf("Log written to: %s\n", LOG_FILE);
    }

    // ✅ Example 5: Command-line argument check
    if (argc < 2) {
        printf("Usage: %s <your_name>\n", argv[0]);
    } else {
        printf("Hello, %s\n", argv[1]);
    }

    return 0;
}