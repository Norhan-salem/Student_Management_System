#pragma once

#define  FACULTY_MAX_ACADEMIC_YEAR 5

typedef struct Student;

/**
 * Updates a student record in the system.
 *
 * @Preconditions:
 * - The system is in a state where a student record can be updated.
 *
 * @Postconditions:
 * - The specified field of the student record with the given ID has been updated with the new value.
 *
 * @Parameters: "fp" which is a pointer to a FILE object
 *
 * @Return value: nothing
 */


void modify_student(FILE* fp);
