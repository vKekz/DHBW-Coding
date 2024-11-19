/* number_puzzle.c 
   Write a number puzzle program by completing the TO DOs
   TO DO 1: Initialize the puzzle, such that the numbers 1 to 15 are randomly distributed in the array.
            -1 should mark the empty field.
   TO DO 2: get key and move pieces accordingly (if keystroke is valid)
   TO DO 3: Check, if puzzle is in correct order -> set sorted=1
   TO DO 4: Create a more fancy output, e.g. by creating frames around the numbers
                (Use a special character e.g. a block rather than '*')
                (Also, mark the empty field rather than showing -1)

            *********************
            *  1 *  2 *  3 *  4 *
            *********************
            *  5 *  6 *  7 *  8 *
            *********************
            *  9 * 10 * 11 * 12 *
            *********************
            * 13 * 14 * 15 ******
            *********************

   TO DO 5, optional: created an automatic, intelligent puzzle solver, which solves the puzzle without user interaction.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InitPuzzle(int puzzle[4][4]);

int IsSorted(const int puzzle[4][4]);

void ShufflePuzzle(int puzzle[4][4], int current_position[2]);

void PrintPuzzle(const int puzzle[4][4]);

void MovePuzzle(int puzzle[4][4], int current_position[2], char direction);

int main() {
   int puzzle[4][4];

   InitPuzzle(puzzle);
   // printf("%d\n", IsSorted(puzzle));

   int current_position[2];
   ShufflePuzzle(puzzle, current_position);
   PrintPuzzle(puzzle);

   while (!IsSorted(puzzle)) {
      printf("Choose a direction: w=up, a=left, s=down, d=right\n");

      const char direction = getchar();
      MovePuzzle(puzzle, current_position, direction);
      PrintPuzzle(puzzle);

      printf("\n");
   }
}

void InitPuzzle(int puzzle[4][4]) {
   for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
         puzzle[i][j] = i == 3 && j == 3 ? -1 : j + 4 * i + 1;
      }
   }
}

int IsSorted(const int puzzle[4][4]) {
   for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
         const int expected = i == 3 && j == 3 ? -1 : j + 4 * i + 1;
         if (puzzle[i][j] != expected) {
            return 0;
         }
      }
   }
   return 1;
}

void ShufflePuzzle(int puzzle[4][4], int current_position[2]) {
   // srand(time(0));

   for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
         const int x = rand() % 4;
         const int y = rand() % 4;

         const int temp = puzzle[i][j];
         puzzle[i][j] = puzzle[x][y];
         puzzle[x][y] = temp;

         if (temp == -1) {
            current_position[0] = x;
            current_position[1] = y;

            printf("%d %d %d\n", x, y, temp);
         }
      }
   }
}

void PrintPuzzle(const int puzzle[4][4]) {
   // system("cls");

   for (int i = 0; i < 4; i++) {
      printf("*********************\n");
      printf("*");
      for (int j = 0; j < 4; j++) {
         if (puzzle[i][j] == -1) {
            printf("    *");
         } else {
            printf(" %2d *", puzzle[i][j]);
         }
      }
      printf("\n");
   }
   printf("*********************\n");
}

void MovePuzzle(int puzzle[4][4], int current_position[2], const char direction) {
   int direction_vector[2];
   switch (direction) {
      case 'w':
      case 'W':
         direction_vector[0] = -1;
         direction_vector[1] = 0;
         break;
      case 'a':
      case 'A':
         direction_vector[0] = 0;
         direction_vector[1] = -1;
         break;
      case 's':
      case 'S':
         direction_vector[0] = 1;
         direction_vector[1] = 0;
         break;
      case 'd':
      case 'D':
         direction_vector[0] = 0;
         direction_vector[1] = 1;
         break;
      default:
         return;
   }

   const int old_x = current_position[0];
   const int old_y = current_position[1];

   const int new_x = current_position[0] + direction_vector[0];
   const int new_y = current_position[1] + direction_vector[1];

   if (new_x < 0 || new_x > 3 || new_y < 0 || new_y > 3) {
      return;
   }

   const int temp = puzzle[old_x][old_y];
   puzzle[old_x][old_y] = puzzle[new_x][new_y];
   puzzle[new_x][new_y] = temp;

   current_position[0] = new_x;
   current_position[1] = new_y;
}
