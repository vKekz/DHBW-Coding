// Ackermann: calculate the Ackermann function 
// The mathematical Ackermann function is defined as follows:
//
//    A(m,n) =   n+1              if m=0
//               A(m-1,1)         if m>0 and n=0
//               A(m-1, A(m,n-1)) if m>0 and n>0
//
// TO DO 1: Write a function that calculates the Ackermann function according to the definition above
//          Test the program with very small values first!
// TO DO 2: Extend the function such that it counts the number of functions calls (use a global variable counter)
//          Print the function arguments and current count every x function calls. 
// TO DO 3: Count the amount of recursively called functions (which are not yet completed) and print them as well
// TO DO 4: Use static variables in ackermann for counting rather than global variables.
// TO DO 5: Optional: Visualize the current recursion depth with bars of ascii-characters: xxxxxxxxxxxxxxxxxx
// TO DO 6: Optional: Provide values m and n via the command line
//          Allow in addition the option '-v' (verbose), to switch on output of intermediate results

#include <stdio.h>

long long function_calls = 0;
int recursion_depth = 0;

int AckermannRecursion(int m, int n);

int main()
{
   int n, m;

   printf("Value for m:\n");
   scanf("%d", &m);

   printf("Value for n:\n");
   scanf("%d", &n);

   const int result = AckermannRecursion(m, n);

   printf("\nValue for m=%d n=%d: %d\n", m, n, result);
   printf("Recursive calls: %lld", function_calls);
}

int AckermannRecursion(const int m, const int n) {
   // printf("(%lld) m=%d n=%d\n", ++function_calls, m, n);
   function_calls++;

   printf("depth: %d\n", recursion_depth);

   if (m == 0) {
      recursion_depth--;
      return n + 1;
   }

   if (m > 0) {
      if (n == 0) {
         recursion_depth++;
         return AckermannRecursion(m - 1, 1);
      }
      if (n > 0) {
         recursion_depth++;
         return AckermannRecursion(m - 1, AckermannRecursion(m, n - 1));
      }
   }

   return 1;
}
