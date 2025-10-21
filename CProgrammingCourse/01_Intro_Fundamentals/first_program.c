/*******************************************************
*                                                     *
* Author       : Sanjeet Prasad                       *
* Email        : sanjeet8.23@gmail.com                *
* Description  : Demonstrates a simple C program      *
*                using main() and printf()            *
* Created On   : 2nd May 2025                         *
* Compiler     : GCC 14.2.0                           *
* Standard     : C99                                  *
*                                                     *
*******************************************************/
#include <stdio.h>

int main() {
    FILE *fp = fopen("output.txt", "w");
    if (!fp) {
        perror("File open failed");
        return 1;
    }

    fprintf(fp, "This is a buffered line.");
    
    // Comment out this line to observe delayed file write
    fflush(fp);

    printf("Done writing to file.\n");

    getchar();  // Pause so you can inspect the file before fclose

    fclose(fp);
    return 0;
}