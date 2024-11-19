// Switch case: Order your burger...
// TO DO 1: Replace the if-statements with switch case and add a default case for invalid input
// TO DO 2: Add support for extra-large and fish burgers
// TO DO 3: Extend the program such that is executed in a loop, which can be aborted by entering 'q' as size
// TO DO 4: If there is a much longer list of options: How can long if-else-chains / switch-case-statements be avoided?
// TO DO 5: Optional: Any further ideas for additional sizes and options?

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	while (1) {
		char size, specials;
		int height = 0;
		float price = 0;

		printf("\nWhich size you want your burger (s=small, m=medium, l=large, x=extra-large)?");
		scanf(" %c", &size);

		switch (size) {
			case 's':
				height = 1;
				price = 2.5f;
				break;
			case 'm':
				height = 2;
				price = 3.5f;
				break;
			case 'l':
				height = 4;
				price = 5.9f;
				break;
			case 'x':
				height = 5;
				price = 7.5f;
				break;
			case 'q':
				exit(0);
			default:
				break;
		}

		printf("Any specials (r=regular: beef, f=fish, v=veggie, c=cheese)?");
		scanf(" %c", &specials);

		printf("\n\n.-\"\"\"\"-.\n");
		while (height--) {
			switch (specials) {
				case 'v':
					printf("(vvvvvv)\n");
				case 'f':
					printf("(ffffff)\n");
				case 'c':
					printf(" ------ \n");
				case 'q':
					exit(0);
				default:
					printf("(mmmmmm)\n");
					break;
			}
		}

		printf("\\______/\n");
		printf("\n\n%.2f Euro - Enjoy!", price);
	}
}
