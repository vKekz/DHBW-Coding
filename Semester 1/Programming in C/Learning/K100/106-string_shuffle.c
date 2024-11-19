/* Shuffles a string */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char name[5], c;
	int i, p1, p2;

	printf("Please enter your name:\n");
	const char* input = gets(name);

	const int len = strlen(input);
	printf("%d %d", len, rand());

	if (len > 5) {
		exit(0);
	}

	for (i = 0; i < 10; i++) {
		p1 = rand() % strlen(name);
		p2 = rand() % strlen(name);
		c = name[p1];
		name[p1] = name[p2];
		name[p2] = c;
		printf("Hello %s\n", name);
	}
	return 0;
}
