/* floating_point.c Investigate the precision and borders of floating point numbers */
// TO DO 1: The program doesn't seem to stop. Maybe f and d should be increased faster? 
// TO DO 2: How does the 'limit behaviour' differ from integer numbers? 
// TO DO 3: Insert a comparison to check when the float and double values are different from each other,
//          print the difference 
// TO DO 4: Related to TO DO 1: How can you find the maximum number fast, but also with high precision?
// TO DO 5: (Optional) Competition: Who generates the highest float number? 
//          (But not NaN, and without using predefined limit-constants)

#include <stdio.h>

int main() {
   float f, old_f;
   double d, old_d;

   f = 1;
   d = 1;

   while (1) {
      old_f = f;
      f = f + 1;

      // printf("%f\n", f);

      if (old_f >= f) {
         printf("float limit %f -> %f \n", old_f, f);
         break;
      }
   }

   while (1) {
      old_d = d;
      d = (d + 1) * (1.00000005 + 20 / d);

      if (old_d >= d) {
         printf("double limit %lf -> %lf \n", old_d, d);
         break;
      }
   }
}
