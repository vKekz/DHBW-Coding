// command line args 
// TO DO: Use the command line arguments to modify previous programs from the lecture, e.g. 
//        devowelizer: provide a string to be "devowelized"
//        ascii-art: provide x and y 
// TO DO: parse the command line arguments: If there is a string "-h" or "-help" 
//        print a small help text 


#include <stdlib.h>
#include <stdio.h>

int main(const int argc, char *argv[])
{
    for(int n = 0; n < argc; n++) {
	   printf("Command line argument %d is %s\n", n, argv[n]);
    }
    return EXIT_SUCCESS;
}