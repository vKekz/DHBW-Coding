/* address_list.c */
// This program should be completed such that it maintains a list of students
// TO DO 1: Write a function inputStudent(int i), which allows the user to enter first name and last name and stores it at position i in the array.
// TO DO 2: Use a variable to count the number of students stored in the array.
// TO DO 3: Write a function printStudent(i), which prints student i stored in the array
// TO DO 4: Write functions addStudent(), for adding a student at the first free position, and printAllStudents() for printing all students stored.
// TO DO 5: Write a function menu(), which allows the user to select one of the actions
//            - add Student
//            - print all students
//            - quit program
// TO DO 6: Extend the student data and the corresponding functions with the gender male/female (using "enum").
// TO DO 7: Create a structure for handling dates (day, month, year) and use it for birth date, date of enrollment etc. 
// TO DO 8: Extend the program such it also handles address information (street, number, zip-code and city).
// TO DO 9: optional: Add a function and menu item for deleting a selected student.
// TO DO 10: optional: Add a function to sort the data according to given criteria

#include <stdio.h>
#include <Windows.h>

#define MAX_STUDENTS 100

enum Action {
   ADD_STUDENT,
   PRINT_STUDENTS,
   QUIT,
};

enum Gender {
   MALE,
   FEMALE,
};
char * genders[] = { "Male", "Female" };

typedef struct date {
   int year;
   int month;
   int day;
} Date;

typedef struct person {
   char first_name[30];
   char last_name[30];
   enum Gender gender;
   char street[30];
   int number;
   int zip_code;
   char city[30];
   Date birth_date;
   Date date_of_enrollment;
} Person;

int students_count = 0;

void InputStudent(Person students[100], const int i) {
   char first_name[30];
   printf("Enter First Name: \n");
   scanf("%s", first_name);

   char last_name[30];
   printf("Enter Last Name: \n");
   scanf("%s", last_name);

   int gender;
   printf("Enter Gender (0=Male/1=Female): \n");
   scanf("%d", &gender);

   strcpy(students[i].first_name, first_name);
   strcpy(students[i].last_name, last_name);
   students[i].gender = gender;
}

void AddStudent(Person students[100]) {
   InputStudent(students, students_count++);
}

void DeleteStudent(int i) {

}

void PrintStudent(Person *student) {
   const Date birth_date = student -> birth_date;

   printf("- %s, %s (%s) (%d.%d.%d)\n",
      student -> last_name,
      student -> first_name,
      genders[student -> gender],
      birth_date.day,
      birth_date.month,
      birth_date.year
   );
}

void PrintAllStudents(Person students[100]) {
   if (students_count == 0) {
      printf("No Students Found\n");
      return;
   }

   printf("Students List: %d\n", students_count);
   for (int i = 0; i < students_count; i++) {
      PrintStudent(students + i);
   }
}

void Menu(Person students[100]) {
   while (1) {
      printf("\n");
      printf("Select an action:\n");
      printf("- Add student (0)\n");
      printf("- Print all students (1)\n");
      printf("- Quit (2)\n");

      int action;
      scanf("%d", &action);

      switch (action) {
         case ADD_STUDENT:
            AddStudent(students);
            break;
         case PRINT_STUDENTS:
            PrintAllStudents(students);
            break;
         case QUIT:
            return;
         default:
            break;
      }
   }
}

int main() {
   Person *students = malloc(MAX_STUDENTS * sizeof(Person));

   if (students == NULL) {
      printf("Memory Error\n");
      return -1;
   }

   Menu(students);
   free(students);

   return 0;
}