#include <stdio.h>
#include <stdbool.h>
#include <windows.h>



typedef struct {
    char name[50];
    int ID;
    char Gender;
    int academicYear;
    float GPA;
} Student;



void remove_student(FILE *fp) {


    int tempID;
    bool validInput = false;


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
        printf("!!ID Not Found!!\n");
        Sleep(1000);
        return;
    }




    // Create temporary file to store remaining students
    FILE *tempFile = tmpfile();
    fseek(fp, 0, SEEK_SET);
    while (fread(&s, sizeof(s), 1, fp)) {
        if (tempID != s.ID) {
            fwrite(&s, sizeof(s), 1, tempFile);
        }
    }




    // Copy remaining students from temporary file to original file
    fseek(fp, 0, SEEK_SET);
    fseek(tempFile, 0, SEEK_SET);
    while (fread(&s, sizeof(s), 1, tempFile)) {
        fwrite(&s, sizeof(s), 1, fp);
    }
    ftruncate(fileno(fp), ftell(fp));




    printf("Operation Successful: Student record removed!\n");
    Sleep(1000);
}

