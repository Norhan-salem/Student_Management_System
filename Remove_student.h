#pragma once

#define  FACULTY_MAX_ACADEMIC_YEAR 5

typedef struct Student;

/**
 * Removes a student record from the system.
 *
 * @Preconditions:
 * - The system is in a state where a student record can be removed.
 *
 * @Postconditions:
 * - The student record with the given ID has been removed from the system's internal storage.
 * - A success message is displayed indicating that the student was removed successfully.
 *
 * @Parameters: "fp" which is a pointer to a FILE object
 *
 * @Return value: A pointer to a FILE object
 */

FILE* del_student(FILE* fp);
