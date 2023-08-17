#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

#define FACULTY_MAX_ACADEMIC_YEAR 5



typedef struct {
    char name[50];
    int ID;
    char Gender;
    int academicYear;
    float GPA;
} Student;



void add_student(FILE *fp) {

    Student s;
    int tempID;
    bool validInput = false;



    // Get student name
    while (!validInput) {
        printf("\n\n\t\tEnter Full Name of Student: ");
        fgets(s.name, 50, stdin);
        s.name[strcspn(s.name, "\n")] = '\0';

        // Check if name consists of exactly two words
        int spaceCount = 0;
        for (int i = 0; s.name[i]; i++) {
            if (s.name[i] == ' ') spaceCount++;
        }
        if (spaceCount != 1) {
            printf("!!Enter First and Last Name Only!!\n");
            Sleep(1000);
        } else {
            validInput = true;
        }
    }



    // Get student ID
    validInput = false;
    while (!validInput) {
        printf("\n\n\t\tEnter ID number: ");
        scanf("%d", &tempID);

        // Check if ID is a 7-digit integral code with no leading zeros
        if (tempID < 1000000 || tempID > 9999999) {
            printf("!!Enter a 7-digit integral code with no leading zeros!!\n");
            Sleep(1000);
            continue;
        }

        // Check if ID is unique
        fseek(fp, 0, SEEK_SET);
        bool duplicateID = false;
        while (fread(&s, sizeof(s), 1, fp)) {
            if (tempID == s.ID) {
                duplicateID = true;
                break;
            }
        }
        if (duplicateID) {
            printf("!!ID must be unique, try again!!\n");
            Sleep(1000);
            continue;
        }

        validInput = true;
    }
    s.ID = tempID;



    // Get student gender
    validInput = false;
    while (!validInput) {
        printf("\n\n\t\tEnter Gender: ");
        scanf(" %c", &s.Gender);

        // Check if gender is either 'M' or 'F'
        if (s.Gender != 'M' && s.Gender != 'F') {
            printf("!!Enter M for male and F for female!!\n");
            Sleep(1000);
            continue;
        }

        validInput = true;
    }



    // Get student academic year
    validInput = false;
    while (!validInput) {
        printf("\n\n\t\tEnter Academic Year: ");
        scanf("%d", &s.academicYear);

        // Check if academic year is between 1 and FACULTY_MAX_ACADEMIC_YEAR
        if (s.academicYear < 1 || s.academicYear > FACULTY_MAX_ACADEMIC_YEAR) {
            printf("!!Enter an Academic Year from 1 to %d!!\n", FACULTY_MAX_ACADEMIC_YEAR);
            Sleep(1000);
            continue;
        }

        validInput = true;
    }



    // Get student GPA
    validInput = false;
    while (!validInput) {
        printf("\n\n\tEnter GPA: \n");
        scanf("%f", &s.GPA);

        // Check if GPA is between 0.0 and 4.0
        if (s.GPA < 0.0 || s.GPA > 4.0) {
            printf("!!Enter GPA between 0.0 and 4.0!!\n");
            Sleep(1000);
            continue;
        }

        validInput = true;
    }



    // Add new student record to file
    fseek(fp, 0, SEEK_END);
    fwrite(&s, sizeof(s), 1, fp);
    printf("Student was successfully added!\n");
    Sleep(1000);
}


