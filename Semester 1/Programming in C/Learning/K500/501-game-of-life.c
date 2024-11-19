/* Game of life
The "game of life" is an old and very simple approach of simulating evolution 
A 2-dimensional field of cells is regarded with a cell being either empty/dead (0) or occupied/alive (1)
The intial state can be chosen e.g. manually or using some random operations.

The further evolution is governed by the following rules:

Every cell interacts with its eight neighbours, which are the cells that are directly horizontally, vertically, or diagonally adjacent. 
At each step in time, the following transitions occur:
   1. Any live cell with fewer than two live neighbours dies, as if by needs caused by underpopulation.
   2. Any live cell with more than three live neighbours dies, as if by overcrowding.
   3. Any live cell with two or three live neighbours lives, unchanged, to the next generation.
   4. Any empty/dead cell with exactly three live neighbours cells will be populated with a living cell.

The initial pattern constitutes the 'seed' of the system. The first generation is created by applying the above rules simultaneously to every cell in the seed � births and deaths happen simultaneously, and the discrete moment at which this happens is sometimes called a tick. (In other words, each generation is a pure function of the one before.)  The rules continue to be applied repeatedly to create further generations.

see: http://en.wikipedia.org/wiki/Conway's_Game_of_Life
*/

// TO DO: Complete the programm such that it simulates the game of life. 
//        Do it as teamwork (e.g. in teams with 2 or 3) 
//        and benefit from being able to develop functions independently and integrate them into the final program.
// TO DO optional 1: extend the program, such that it detects 'stable states', i.e. the system is oscillating between a few states. 
// TO DO optional 2: let the program find a start state such that the system stays alive and unstable for as long as possible
// TO DO optional 3: Create a flicker-free output: Do not print each character separately, but write the output into a string, which is printed all at once
// TO DO optional 4: extend the program such that the content of the cells can be edited by the user. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEAD_PROBABILITY 85
#define ALIVE '1'
#define DEAD '0'

// Global 2-dim-array which contains the cells
char cells[30][50];

void InitCells();

void DisplayCells();

void EvolutionStep();

int CountLivingCells();

int CountLivingNeighbours(const char prev_cells[30][50], int x, int y);

// Main program
int main() {
   InitCells();
   DisplayCells();

   while (1) {
      DisplayCells();

      // Leave loop if there are no more occupied cells
      const int living_cells = CountLivingCells();
      if (living_cells == 0)
         break;

      printf("Press enter\n");
      printf("Anzahl der Lebenden: %d", living_cells);
      getchar();

      EvolutionStep();
   }
}

void InitCells() {
   srand(time(0));

   for (int i = 0; i < 30; i++) {
      for (int j = 0; j < 50; j++) {
         const int percentage = rand() % 100;
         cells[i][j] = percentage > DEAD_PROBABILITY ? ALIVE : DEAD;
      }
   }
}

void DisplayCells() {
   system("cls");

   for (int i = 0; i < 30; i++) {
      for (int j = 0; j < 50; j++) {
         printf("%c", cells[i][j]);
      }
      printf("\n");
   }
}

void EvolutionStep() {
   char cells_helper[30][50];

   for (int i = 0; i < 30; i++) {
      for (int j = 0; j < 50; j++) {
         cells_helper[i][j] = cells[i][j];
      }
   }

   for (int i = 0; i < 30; i++) {
      for (int j = 0; j < 50; j++) {
         const char cell = cells_helper[i][j];
         const int neighbours = CountLivingNeighbours(cells_helper, i, j);

         if (cell == ALIVE) {
            // First rule
            if (neighbours < 2) {
               cells[i][j] = DEAD;
            }

            // Second rule
            if (neighbours == 2 || neighbours == 3) {
               cells[i][j] = ALIVE;
            }

            // Third rule
            if (neighbours > 3) {
               cells[i][j] = DEAD;
            }
         }

         // Fourth rule
         if (cell == DEAD) {
            if (neighbours == 3) {
               cells[i][j] = ALIVE;
            }
         }
      }
   }
}

int CountLivingCells() {
   int count = 0;

   for (int i = 0; i < 30; i++) {
      for (int j = 0; j < 50; j++) {
         const char cell = cells[i][j];

         if (cell == ALIVE) {
            count++;
         }
      }
   }

   return count;
}

int CountLivingNeighbours(const char prev_cells[30][50], const int x, const int y) {
   int count = 0;

   for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
         if (i != 0 && j != 0) {
            const char neighbour_cell = prev_cells[x + i][y + j];

            if (neighbour_cell == ALIVE) {
               count++;
            }
         }
      }
   }

   return count;
}
