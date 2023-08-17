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

void display_student(FILE *fp) {
    int searchOption;
    bool validInput = false;
    
    system("cls");
    
    // Get search option
    while (!validInput) {
        printf("\n\n\t\tSearch by:\n\t\t1) Name\n\t\t2) ID\n\t\tEnter option: ");
        scanf("%d", &searchOption);

        // Check if search option is valid
        if (searchOption != 1 && searchOption != 2) {
            printf("!!Invalid option!!\n");
            Sleep(1000);
            continue;
        }

        validInput = true;
    }

    // Search by name
    if (searchOption == 1) {
        char tempName[50];
        printf("\n\n\t\tEnter Name: ");
        scanf(" %[^\n]", tempName);

        // Check if name consists of exactly two words
        int spaceCount = 0;
        for (int i = 0; tempName[i]; i++) {
            if (tempName[i] == ' ') spaceCount++;
        }
        if (spaceCount != 1) {
            printf("!!Invalid Name!!\n");
            Sleep(1000);
            return;
        }

        // Search for students with given name
        fseek(fp, 0, SEEK_SET);
        Student s;
        bool studentFound = false;
        while (fread(&s, sizeof(s), 1, fp)) {
            if (strcmp(tempName, s.name) == 0) {
                studentFound = true;
                printf("\nName: %s\nID: %d\nGender: %c\nAcademic Year: %d\nGPA: %.2f\n",
                       s.name, s.ID, s.Gender, s.academicYear, s.GPA);
                       Sleep(1000);
            }
        }
        if (!studentFound) {
            printf("!!Student Not Found!!\n");
            Sleep(1000);
            return;
        }
    }

    // Search by ID
    else if (searchOption == 2) {
        int tempID;
        printf("\n\n\t\tEnter ID number: ");
        scanf("%d", &tempID);

        // Check if ID is a 7-digit integral code with no leading zeros
        if (tempID < 1000000 || tempID > 9999999) {
            printf("!!Invalid ID!!\n");
            Sleep(1000);
            return;
        }

        // Search for student with given ID
        fseek(fp, 0, SEEK_SET);
        Student s;
        bool studentFound = false;
        while (fread(&s, sizeof(s), 1, fp)) {
            if (tempID == s.ID) {
                studentFound = true;
                printf("\nName: %s\nID: %d\nGender: %c\nAcademic Year: %d\nGPA: %.2f\n",
                       s.name, s.ID, s.Gender, s.academicYear, s.GPA);
                       Sleep(1000);
                break;
            }
        }
        if (!studentFound) {
            printf("!!Student Not Found!!\n");
            Sleep(1000);
            return;
        }
    }

    printf("Operation Successful!\n");
    Sleep(1000);
}

