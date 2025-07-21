/*
 * Word Counter Project
 *
 * Description:
 * This program reads input text from a file or standard input and counts the 
 * number of words contained in the text. It demonstrates basic string parsing, 
 * file handling, and character classification techniques in C.
 *
 * Key Features:
 * - Counts words separated by spaces, tabs, or newline characters
 * - Handles punctuation and multiple whitespace characters gracefully
 * - Offers a simple and portable structure for educational use
 *
 * Author: Sanjeet Prasad(sanjeet8.23@gmail.com)
 * Date: 12th July 2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

#define FILE_PATH "input.txt"
#define POLL_INTERVAL 2  // seconds
#define MAX_TOKEN_SIZE 100

// Delimiter logic updated to preserve '.' for float detection
int is_delimiter(char ch) {
    return isspace((unsigned char)ch) || (ispunct((unsigned char)ch) && ch != '.');
}

int is_integer(const char *token) {
    if (*token == '+' || *token == '-') token++;
    if (!*token) return 0;
    while (*token) {
        if (!isdigit(*token)) return 0;
        token++;
    }
    return 1;
}

int is_float(const char *token) {
    int dot_seen = 0;
    int digit_seen = 0;
    if (*token == '+' || *token == '-') token++;
    if (!*token) return 0;

    while (*token) {
        if (*token == '.') {
            if (dot_seen) return 0;
            dot_seen = 1;
        } else if (isdigit(*token)) {
            digit_seen = 1;
        } else {
            return 0;
        }
        token++;
    }
    return dot_seen && digit_seen;
}

// Removes trailing punctuation like '%' or ':' from end of token
void strip_trailing_punct(char *token) {
    size_t len = strlen(token);
    while (len > 0 && ispunct(token[len - 1]) && token[len - 1] != '.') {
        token[len - 1] = '\0';
        len--;
    }
}

void classify_tokens(FILE *fp, int *word_count, int *int_count, int *float_count) {
    char ch;
    char token[MAX_TOKEN_SIZE];
    int index = 0;

    while ((ch = fgetc(fp)) != EOF) {
        if (is_delimiter(ch)) {
            if (index > 0) {
                token[index] = '\0';
                strip_trailing_punct(token);

                if (strcmp(token, "exit") == 0) {
                    printf("[Stop] 'exit' keyword found. Terminating...\n");
                    exit(0);
                } else if (is_float(token)) {
                    (*float_count)++;
                } else if (is_integer(token)) {
                    (*int_count)++;
                } else {
                    (*word_count)++;
                }

                index = 0;
            }
        } else {
            if (index < MAX_TOKEN_SIZE - 1)
                token[index++] = ch;
        }
    }

    if (index > 0) {
        token[index] = '\0';
        strip_trailing_punct(token);

        if (strcmp(token, "exit") == 0) {
            printf("[Stop] 'exit' keyword found. Terminating...\n");
            exit(0);
        } else if (is_float(token)) {
            (*float_count)++;
        } else if (is_integer(token)) {
            (*int_count)++;
        } else {
            (*word_count)++;
        }
    }
}

int main() {
    long prev_size = 0;
    int iteration = 0;

    printf("[Start] Real-Time Word Counter Initialized\n");
    printf("[Monitor] Watching file: '%s'\n", FILE_PATH);
    printf("[Hint] Add the word 'exit' to the file to stop execution.\n");

    while (1) {
        iteration++;
        printf("\n[Poll #%d] Checking for file updates...\n", iteration);

        FILE *fp = fopen(FILE_PATH, "r");
        if (!fp) {
            perror("[Error] Unable to open file");
            return 1;
        }

        fseek(fp, 0, SEEK_END);
        long curr_size = ftell(fp);
        rewind(fp);

        if (curr_size != prev_size) {
            printf("[Update] File size changed (%ld -> %ld). Reprocessing...\n", prev_size, curr_size);

            int words = 0, ints = 0, floats = 0;
            classify_tokens(fp, &words, &ints, &floats);

            printf("[Result] Words: %d | Integers: %d | Floats: %d | Total Tokens: %d\n",
                   words, ints, floats, words + ints + floats);

            prev_size = curr_size;
        } else {
            printf("[Status] No changes detected. Skipping update.\n");
        }

        fclose(fp);
        sleep(POLL_INTERVAL);
    }

    return 0;
}