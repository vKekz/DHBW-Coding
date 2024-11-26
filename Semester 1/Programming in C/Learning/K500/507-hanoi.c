// hanoi.c Towers of hanoi
// TO DO: Extend the programm such that it creates a graphical output of the disks on the three rods
//        introduce a function display(), which is called from hanoi()
//        Use global or static variables to keep the status of the disk towers.

#include <stdio.h>
#include <stdlib.h>

int status[3] = { 0 };

void InitTowerStatus(const int n) {
   status[0] = n;
}

void Display() {
   // char output[n][3];
   //
   // // Init
   // for (int i = 0; i < n; i++) {
   //    for (int j = 0; j < 3; j++) {
   //       output[i][j] = 0;
   //    }
   // }
   //
   // for (int i = 0; i < n; i++) {
   //    for (int j = 0; j < 3; j++) {
   //       const int tower_status = status[j];
   //
   //       for (int k = 0; k < tower_status; k++) {
   //          printf("-- | \n");
   //       }
   //    }
   // }

   for (int i = 0; i < 3; i++) {
      const int tower_status = status[i];

      for (int j = 0; j < tower_status; j++) {
         printf("x");
      }

      if (i != 2) {
         printf(" | ");
      }
   }
   printf("\n\n");
}

void Hanoi(const int n, const int start, const int goal, const int helper) {
   if (n > 0) {
      Hanoi(n - 1, start, helper, goal);

      Display();
      printf("Moving disk from %d to %d\n", start, goal);

      status[start - 1] = status[start - 1] - 1;
      status[goal - 1] = status[goal - 1] + 1;

      Hanoi(n - 1, helper, goal, start);
   }
}

int main() {
   int n;
   printf("How many disks?\n");

   scanf("%d", &n);

   InitTowerStatus(n);
   Hanoi(n, 1, 3, 2);

   Display();

   return EXIT_SUCCESS;
}
