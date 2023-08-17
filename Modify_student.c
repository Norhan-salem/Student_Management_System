#include <stdio.h>
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



void modify_student(FILE *fp) {


    int tempID;
    bool validInput = false;

    system("cls");


    // Get student ID
    while (!validInput) {
        printf("\n\n\t\tEnter ID number: ");
        scanf("%d", &tempID);

        // Check if ID is a 7-digit integral code with no leading zeros
        if (tempID < 1000000 || tempID > 9999999) {
            printf("!!Invalid ID!!\n");
            Sleep(1000);
            continue;
        }

        validInput = true;
    }




    // Check if student with given ID exists
    fseek(fp, 0, SEEK_SET);
    Student s;
    bool studentFound = false;
    while (fread(&s, sizeof(s), 1, fp)) {
        if (tempID == s.ID) {
            studentFound = true;
            break;
        }
    }
    if (!studentFound) {
        printf("!!Student Not Found!!\n");
        Sleep(1000);
        return;
    }




    // Get field to update
    int updateOption;
    validInput = false;
    while (!validInput) {
        printf("\n\n\t\tUpdate:\n\t\t1) Academic Year\n\t\t2) GPA\n\t\tEnter option: ");
        scanf("%d", &updateOption);


        // Check if update option is valid
        if (updateOption != 1 && updateOption != 2) {
            printf("!!Invalid option!!\n");
            Sleep(1000);
            continue;
        }

        validInput = true;
    }




    // Update academic year
    if (updateOption == 1) {
        printf("\n\n\t\tEnter Academic Year: ");
        scanf("%d", &s.academicYear);

        // Check if academic year is between 1 and FACULTY_MAX_ACADEMIC_YEAR
        if (s.academicYear < 1 || s.academicYear > FACULTY_MAX_ACADEMIC_YEAR) {
            printf("!!Invalid Academic Year!!\n");
            Sleep(1000);
            return;
        }
    }




    // Update GPA
    else if (updateOption == 2) {
        printf("\n\n\tEnter GPA: \n");
        scanf("%f", &s.GPA);


        // Check if GPA is between 0.0 and 4.0
        if (s.GPA < 0.0 || s.GPA > 4.0) {
            printf("!!Invalid GPA!!\n");
            Sleep(1000);
            return;
        }
    }




    // Update student record in file
    fseek(fp, -sizeof(s), SEEK_CUR);
    fwrite(&s, sizeof(s), 1, fp);


    printf("Operation Successful: Student record updated!\n");
    Sleep(1000);
}

