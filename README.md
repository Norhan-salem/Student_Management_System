# Student Management System

This is a final project for the C/Embedded C training provided by GARRAIO in collaboration with the Faculty of Engineering, Ain Shams University. The project is a student management system coded in C language and offers functionality such as adding a new student, modifying their data, viewing a certain student(s) data, and deleting a student's data through a menu. The IDE used for this project is Code Blocks and the compiler is GNU GCC.

## Requirements

The information for a student is stored in a `.txt` file named `db.txt` and includes the following fields:
- Student Name: A single string representing the student's first and last name.
- Student ID: A 7-digit code that is unique for each student.
- Student Gender: A single character representing the gender of the student ('M' or 'F').
- Academic Year: An integral number between 1 and `FACULTY_MAX_ACADEMIC_YEAR`.
- GPA: A positive floating-point value between 0 and 4.0.

The user can choose an operation by entering its number. If an out-of-range value is entered, an error message will be displayed and the system will ask the user to re-enter a valid number.

### Adding a New Student

When adding a new student record, the system will ask for all of the fields of information mentioned above. The system will perform error checking on the values of the entered fields. If any values are invalid, an error message will be displayed and the system will ask the user to re-enter the values starting from the error field.

Expected error checks:
- Student Name: Must consist of exactly two words (first and last name).
- Student ID: Must be a 7-digit integral code with no leading zeros. The ID must be unique.
- Student Gender: Must be either 'M' or 'F'.
- Academic Year: Must be an integral value between 1 and `FACULTY_MAX_ACADEMIC_YEAR`.
- GPA: Must be a positive number between 0 and 4.0.

If all fields are entered correctly, the system will add the new student record to its internal storage and display a message indicating that the new student was added successfully.

### Modifying a Student's Data

When modifying a student's data, the system will ask for the ID of the student whose data should be updated. Error checking will be performed on the ID. If it is correct, the system will ask which field should be updated (Academic Year or GPA). The user can enter the new value for this field and the system will perform error checking on this value before updating the student record.

### Displaying a Student(s)'s Data

When displaying student data, the user can choose to search by name or by ID. If searching by ID, at most one student record will be displayed (since IDs are unique). If searching by name, multiple students may have the same name and all of their records will be displayed.

Error checks will be performed on the search attribute before using it to search for student data. Possible outcomes include:
- Invalid ID/Name: When the search field value entered is invalid.
- Student Not Found: If there is no student with the given ID/Name.
- Operation Successful: When the system can retrieve and display information about one or more students.

### Removing a Student Record

When removing a student record, the system will ask for the ID of the student whose data should be removed. Error checking will be performed on this ID before removing the corresponding student record.
