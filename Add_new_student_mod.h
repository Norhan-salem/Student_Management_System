#pragma once

#define  FACULTY_MAX_ACADEMIC_YEAR 5

typedef struct Student;

/**
 * Adds a new student record to the system.
 *
 * @Preconditions: The system is in a state where a new student record can be added.
 *
 * @Postconditions: A new student record has been added to the system's internal storage.
 *                  A success message is displayed indicating that the new student was added successfully.
 *
 * @Parameters: "fp" which is a pointer to a FILE object
 *
 * @Return value: nothing
 *
 */

void add_student(FILE* fp);
