/* check_int_overflow.c Check when integer numbers are overflowing */
// TO DO 1: complete the overflow detecion for other types 
// TO DO 2: extend this to unsigned integers 
// TO DO 3: stop counting after first overflow 
// TO DO 4: estimate how many operations are performed per second.
// TO DO 5 (optional): Use this program as benchmark for your CPU performance and compare it with other students' computers,
// TO DO 6 (optional): Check the CPU load when running the programm. What do you observe? 

#include <stdio.h>

int char_overflow() {
   char c, old_c;
   c = 0;

   while (1) {
      old_c = c;
      c = c + 1;
      if (old_c > c) {
         printf("char  overflow %d -> %d \n", old_c, c);
         break;
      }
   }
}

int short_overflow() {
   short s, old_s;
   s = 0;

   while (1) {
      old_s = s;
      s = s + 1;
      if (old_s > s) {
         printf("short  overflow %hd -> %hd \n", old_s, s);
         break;
      }
   }
}

int int_overflow() {
   int i, old_i;
   i = 0;

   while (1) {
      old_i = i;
      i = i + 1;
      if (old_i > i) {
         printf("int  overflow %d -> %d \n", old_i, i);
         break;
      }
   }
}

int long_overflow() {
   long l, old_l;
   l = 0;

   while (1) {
      old_l = l;
      l = l + 1;
      if (old_l > l) {
         printf("long  overflow %ld -> %ld \n", old_l, l);
         break;
      }
   }
}

int unsigned_int_overflow() {
   unsigned int ui, old_ui;
   ui = 0;

   while (1) {
      old_ui = ui;
      ui = ui + 1;
      if (old_ui > ui) {
         printf("unsinged int  overflow %u -> %u \n", old_ui, ui);
         break;
      }
   }
}

int main() {
   char_overflow();
   short_overflow();
   int_overflow();
   long_overflow();
   unsigned_int_overflow();
}
