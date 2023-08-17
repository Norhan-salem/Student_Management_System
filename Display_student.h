#pragma once

#define  FACULTY_MAX_ACADEMIC_YEAR 5

typedef struct Student;

/**
 * Searches for student records in the system.
 *
 * @Preconditions:
 * - The system is in a state where a student record can be searched for.
 *
 * @Postconditions:
 * - The student record(s) matching the search criteria have been retrieved and displayed.
 *
 * @Parameters: "fp" which is a pointer to a FILE object
 *
 * @Return value: nothing
 */

void display_student(FILE* fp);
