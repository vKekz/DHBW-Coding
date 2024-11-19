/* Compare two strings */
// TO DO 1: This program does not always give the correct results. What is the problem? Correct it!
// TO DO 2: Adapt the comparison such that it can be used for providing an ordering e.g. for phone books

#include <stdio.h>

/// Returns 1 if the given strings are equal, otherwise 0
int CompareStrings(const char first[], const char second[]) {
   for (int i = 0; first[i] != 0 || second[i] != 0; i++) {
      if (first[i] != second[i]) {
         return 1;
      }
   }
   return 0;
}

/// 0 = equal
/// 1 = first comes before second
/// 2 = first comes after second
int CompareAlphabetically(const char first[], const char second[]) {
   for (int i = 0; first[i] != 0 || second[i] != 0; i++) {
      const unsigned char first_decimal = first[i] | 32;
      const unsigned char second_decimal = second[i] | 32;

      if (first_decimal == second_decimal) {
         continue;
      }
      return first_decimal < second_decimal ? 1 : 2;
   }
   return 0;
}

int main() {
   char first[100], second[100];

   printf("Please enter string 1:\n");
   gets(first);

   printf("Please enter string 2:\n");
   gets(second);

   if (CompareStrings(first, second)) {
      printf("Strings are different\n");
   } else {
      printf("Strings are equal\n");
   }

   printf("\n");

   const int alphabetically = CompareAlphabetically(first, second);
   printf("%s %c %s", first, "0<>"[alphabetically] ,second);
}
