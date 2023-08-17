#include<stdio.h>
#include <windows.h>
#include"Add_new_student_mod.h"
#include"Remove_student.h"
#include"Modify_student.h"
#include"Display_student.h"

FILE* tp; // Global variable for file pointer

int main()
{
    SetConsoleTitle("Student Management System | GARRAIO"); // Set the console title
    FILE* fp; // File pointer for database file
    int option; // Variable to store user's option



    // Try to open the database file in read and write mode
    if ((fp = fopen("db.txt", "rb+")) == NULL)
    {
        // If the file does not exist, create a new file in write mode
        if ((fp = fopen("db.txt", "wb+")) == NULL)
        {
            printf("Can't create or open Database!!");
            return 0;
        }
    }



    while (1) // Infinite loop to keep the program running
    {
        title(); // Call the title function to display the title
        printf("\n\t");



        // Display the menu options
        printf("\n\n\t");
        printf(" Student Management System ");
        printf("\n");
        printf("\n\n\n\n\t\tChoose The Desired Option: ");
        printf("\n\n\t\t\t\t1. Add New Student");
        printf("\n\n\t\t\t\t2. Modify Student Data");
        printf("\n\n\t\t\t\t3. View Record");
        printf("\n\n\t\t\t\t4. Remove Student Record");
        printf("\n\n\t\t\t\tEnter Your Option : ");
        scanf("%d", &option);



        switch (option)
        {
            case 1:
                add_student(fp); // Call the add_student function to add a new student
                break;
            case 2:
                modify_student(fp); // Call the modify_student function to modify student data
                break;
            case 3:
                display_student(fp); // Call the display_student function to view student records
                break;
            case 4:
                fp = remove_student(fp); // Call the remove_student function to remove a student record
                break;

            default:
                printf("\n\t\t!!Please Enter a Valid Value!!");
                Sleep(1000);
                scanf("%d", &option);
        }

    }

}












