/*
 ============================================================================
 File        : main.c
 Author      : Sanjeet Prasad
 Date        : 06 July 2025
 Description : Main driver for Student Marksheet Generator
 ============================================================================
*/

#include <stdio.h>
#include <string.h>
#include "marksheet.h"

int main() {
    struct Student s;
    char choice;

    do {
        printf("\n===== STUDENT MARKSHEET GENERATOR =====\n");

        printf("Enter student name: ");
        fgets(s.name, sizeof(s.name), stdin);
        s.name[strcspn(s.name, "\n")] = 0;

        printf("Enter roll number: ");
        scanf("%d", &s.roll);
        getchar();

        printf("Enter class: ");
        fgets(s.class_name, sizeof(s.class_name), stdin);
        s.class_name[strcspn(s.class_name, "\n")] = 0;

        printf("Enter number of subjects: ");
        scanf("%d", &s.subject_count);
        getchar();

        for (int i = 0; i < s.subject_count; i++) {
            printf("Enter subject %d name: ", i + 1);
            fgets(s.subjects[i], sizeof(s.subjects[i]), stdin);
            s.subjects[i][strcspn(s.subjects[i], "\n")] = 0;

            printf("Enter marks in %s: ", s.subjects[i]);
            scanf("%d", &s.marks[i]);
            getchar();
        }

        generate_marksheet(s);

        printf("\nDo you want to enter another student? (y/n): ");
        scanf(" %c", &choice);
        getchar();

    } while (choice == 'y' || choice == 'Y');

    return 0;
}