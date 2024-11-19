/* Shuffles a string */
// TO DO 1: Extend the program such that spaces in the strings are not moved/shuffled.
// TO DO 2: Extend the program such that the first characters of names are not shuffled 
//          (a name may consist of several parts separated by spaces).
// TO DO 3: Extend the program such that two names can be entered and shuffling happens between these two 
// TO DO 4: How can a user make the program crash? What could be done against that problem?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 100

int main() {
   char name[NAME_LENGTH];
   char second_name[NAME_LENGTH];

   printf("Please enter your name:\n");
   // fgets(name, NAME_LENGTH, stdin);
   gets(name);

   // printf("Please enter your second name:\n");
   // fgets(second_name, NAME_LENGTH, stdin);

   if (strlen(name) > NAME_LENGTH || strlen(second_name) > NAME_LENGTH) {
      printf("The length of your name cannot be longer than %d", NAME_LENGTH);
      return 0;
   }

   for (int i = 0; i < 10; i++) {
      const int p1 = rand() % strlen(name);
      const int p2 = rand() % strlen(name);

      const char first_char = name[p1];
      if (first_char == ' ' || p1 == 0 || p2 == 0) {
         continue;
      }

      const char second_char = name[p2];
      if (second_char == ' ') {
         continue;
      }

      // Check if character is separated by white space
      if (name[p1 - 1] == ' ' || name[p2 - 1] == ' ') {
         continue;
      }

      name[p1] = second_char;
      name[p2] = first_char;

      printf("Hello %s\n", name);
   }
}  