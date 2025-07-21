/*
 ============================================================================
 File        : marksheet.h
 Author      : Sanjeet Prasad
 Date        : 06 July 2025
 Description : Header file for Student Marksheet Generator
 ============================================================================
*/

#ifndef MARKSHEET_H
#define MARKSHEET_H

// Structure to hold student information
struct Student {
    char name[50];
    int roll;
    char class_name[10];
    int marks[10];
    char subjects[10][30];
    int subject_count;
};

// Function declarations
const char* get_grade(float percentage);
void generate_marksheet(struct Student s);

#endif