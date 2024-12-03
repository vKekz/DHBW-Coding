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
#include <Windows.h>

#define HEIGHT 30
#define WIDTH 100

#define DELAY 10

#define DEAD_PROBABILITY 85

#define ALIVE 1
#define DEAD 0

#define ALIVE_SYMBOL '#'
#define DEAD_SYMBOL '-'

// Global 2-dim-array which contains the cells
// int cells[HEIGHT][WIDTH];

// +1 for null-byte and new-line
char string_buffer[HEIGHT * (WIDTH + 1) + 1] = { "0" };

void InitCells(int * cells);

void DisplayCells(const int * cells);

void GenerationStep(int * cells);

int CountLivingCells(const int * cells);

int CountLivingNeighbours(const int prev_cells[HEIGHT][WIDTH], int x, int y);

// Main program
int main() {
   int * cells = malloc(HEIGHT * WIDTH * sizeof(int));

   if (cells == NULL) {
      printf("Failed to allocate memory\n");
      return 1;
   }

   InitCells(cells);
   DisplayCells(cells);

   // One clear is needed to remove any weird console bugs
   system("cls");

   int generation = 0;
   while (1) {
      DisplayCells(cells);

      // Leave loop if there are no more occupied cells
      const int living_cells = CountLivingCells(cells);
      if (living_cells == 0) {
         break;
      }

      printf("Population: %d\n", living_cells);
      printf("Generation: %d\n\n", generation++);

      GenerationStep(cells);
      Sleep(DELAY);
   }

   free(cells);
}

void InitCells(int * cells) {
   srand(time(0));

   for (int i = 0; i < HEIGHT; i++) {
      for (int j = 0; j < WIDTH; j++) {
         const int percentage = rand() % 100;
         cells[i + j * HEIGHT] = percentage > DEAD_PROBABILITY ? ALIVE : DEAD;
      }
   }
}

void DisplayCells(const int * cells) {
   int index = 0;

   for (int i = 0; i < HEIGHT; i++) {
      for (int j = 0; j < WIDTH; j++) {
         const int cell = cells[i + j * HEIGHT];
         string_buffer[index++] = cell == ALIVE ? ALIVE_SYMBOL : DEAD_SYMBOL;
      }
      string_buffer[index++] = '\n';
   }
   string_buffer[index] = '\0';

   // system("cls") still caused flickering
   printf("\033[H");
   printf("%s", string_buffer);
}

void GenerationStep(int * cells) {
   int cells_helper[HEIGHT][WIDTH];

   for (int i = 0; i < HEIGHT; i++) {
      for (int j = 0; j < WIDTH; j++) {
         cells_helper[i][j] = cells[i + j * HEIGHT];
      }
   }

   for (int i = 0; i < HEIGHT; i++) {
      for (int j = 0; j < WIDTH; j++) {
         const int cell = cells_helper[i][j];
         const int neighbours = CountLivingNeighbours(cells_helper, i, j);

         if (cell == ALIVE) {
            switch (neighbours) {
               // First rule
               case 0:
               case 1:
                  cells[i + j * HEIGHT] = DEAD;
                  break;
               // Second rule
               case 2:
               case 3:
                  cells[i + j * HEIGHT] = ALIVE;
                  break;
               // Third rule
               default:
                  cells[i + j * HEIGHT] = DEAD;
                  break;
            }
         } else {
            // Fourth rule
            if (neighbours == 3) {
               cells[i + j * HEIGHT] = ALIVE;
            }
         }
      }
   }
}

int CountLivingCells(const int * cells) {
   int count = 0;

   for (int i = 0; i < HEIGHT; i++) {
      for (int j = 0; j < WIDTH; j++) {
         const int cell = cells[i + j * HEIGHT];

         if (cell == ALIVE) {
            count++;
         }
      }
   }

   return count;
}

int CountLivingNeighbours(const int prev_cells[HEIGHT][WIDTH], const int x, const int y) {
   int count = 0;

   for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
         if (i == 0 && j == 0) {
            continue;
         }

         // + HEIGHT or WIDTH to prevent negative index results
         const int row = (x + i + HEIGHT) % HEIGHT;
         const int colum = (y + j + WIDTH) % WIDTH;

         const int neighbour_cell = prev_cells[row][colum];
         if (neighbour_cell == ALIVE) {
            count++;
         }
      }
   }

   return count;
}
