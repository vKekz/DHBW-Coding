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

#define VERBOSE 1

unsigned int max_recursion_depth = 0;
long function_calls = 0;

int AckermannRecursion(int m, int n);

void Verbose(unsigned int depth, int m, int n);

int main()
{
   int n, m;

   printf("Value for m:\n");
   scanf("%d", &m);

   printf("Value for n:\n");
   scanf("%d", &n);

   const int result = AckermannRecursion(m, n);

   printf("\nMaximum depth: %u\n", max_recursion_depth);
   printf("Amount of function calls: %ld\n", function_calls);
   printf("A(m=%d, n=%d) = %d", m, n, result);
}

int AckermannRecursion(const int m, const int n) {
   static int recursion_depth = 0;

   function_calls++;
   recursion_depth++;

   if (recursion_depth > max_recursion_depth) {
      max_recursion_depth = recursion_depth;
   }

   if (VERBOSE) {
      Verbose(recursion_depth, m, n);
   }

   int result = 1;
   if (m == 0) {
      result = n + 1;
   }

   if (m > 0) {
      if (n == 0) {
         result = AckermannRecursion(m - 1, 1);
      }
      if (n > 0) {
         result = AckermannRecursion(m - 1, AckermannRecursion(m, n - 1));
      }
   }

   if (VERBOSE) {
      Verbose(recursion_depth, m, n);
   }

   recursion_depth--;
   return result;
}

void Verbose(const unsigned int depth, const int m, const int n) {
   printf("(depth=%u m=%d n=%d) ", depth, m, n);
   for (int i = 0; i < depth; i++) {
      printf("x");
   }
   printf("\n");
}
