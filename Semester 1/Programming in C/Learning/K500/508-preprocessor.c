/*
TO DO 1: Use the preprocessor #define directive and modify your previous programs, 
         - e.g. define constants such as maximum values / array sizes, shortcuts for special ascii characters etc.
         - Optionally, try to define macros by using parameters with #define.
         - What problems might occur with such macros (and how can they be solved?):
           example: #define square(x)  x*x
                    result=square(5+3);
                    result=square(++y); 

TO DO 2: Have a look at <stdio.h> and other standard header files and see how preprocessor directives are used there


Preprocessor directives:
# include  	include a source file
# define 	define a macro
# undef 	undefine a macro
# if		  conditional compilation
# ifdef 	conditional compilation
# ifndef 	conditional compilation
# elif 	 	conditional compilation
# else 	 	conditional compilation
# endif 	conditional compilation

*/

#define sq(x) ((x)*(x))
#include <stdio.h>

struct date {
    unsigned char day;
    unsigned char month;
    int year;
} Date;

int square(const int x) {
    return x * x;
}

int main() {
    int y = 1;
    int z = square(++y);

    printf("%d %d\n", y, z);

    return 0;
}
