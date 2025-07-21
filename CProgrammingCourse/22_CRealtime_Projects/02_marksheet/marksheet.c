/*
 ============================================================================
 File        : marksheet.c
 Author      : Sanjeet Prasad
 Date        : 06 July 2025
 Description : Function definitions for Student Marksheet Generator
 ============================================================================
*/

#include <stdio.h>
#include <string.h>
#include "marksheet.h"

/*
 * Returns the grade as a string based on the percentage.
 */
const char* get_grade(float percentage) {
    if (percentage >= 90) return "A+";
    else if (percentage >= 80) return "A";
    else if (percentage >= 70) return "B";
    else if (percentage >= 60) return "C";
    else if (percentage >= 50) return "D";
    else return "F";
}

/*
 * Calculates total marks, percentage, and grade.
 * Displays and stores the formatted marksheet.
 */
void generate_marksheet(struct Student s) {
    int total = 0;
    for (int i = 0; i < s.subject_count; i++) {
        total += s.marks[i];
    }
    float percentage = (float)total / s.subject_count;
    const char* grade = get_grade(percentage);

    FILE *fp = fopen("marksheets.txt", "a");
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    // Console Output
    printf("\n----------- MARKSHEET -----------\n");
    printf("Name       : %s\n", s.name);
    printf("Roll No.   : %d\n", s.roll);
    printf("Class      : %s\n\n", s.class_name);
    printf("Subject         Marks\n");
    printf("-----------------------\n");

    // File Output
    fprintf(fp, "\n----------- MARKSHEET -----------\n");
    fprintf(fp, "Name       : %s\n", s.name);
    fprintf(fp, "Roll No.   : %d\n", s.roll);
    fprintf(fp, "Class      : %s\n\n", s.class_name);
    fprintf(fp, "Subject         Marks\n");
    fprintf(fp, "-----------------------\n");

    for (int i = 0; i < s.subject_count; i++) {
        printf("%-15s %d\n", s.subjects[i], s.marks[i]);
        fprintf(fp, "%-15s %d\n", s.subjects[i], s.marks[i]);
    }

    // Summary
    printf("\nTotal Marks : %d\n", total);
    printf("Percentage  : %.2f%%\n", percentage);
    printf("Grade       : %s\n", grade);
    printf("---------------------------------\n");

    fprintf(fp, "\nTotal Marks : %d\n", total);
    fprintf(fp, "Percentage  : %.2f%%\n", percentage);
    fprintf(fp, "Grade       : %s\n", grade);
    fprintf(fp, "---------------------------------\n");

    fclose(fp);
    printf("\nMarksheet saved to 'marksheets.txt'\n");
}