// Generate 'bullshit sentences'
// TO DO 1: In lines v=, n=, a=, ... rand%12? Why always 12?
// TO DO 2: Create more complex sentences e.g. by using more adjectives together or by concatenating several phrases.
// TO DO 3: Generalize the 'You should' by allowing other random introductions, e.g. "we have to", "our company must"
// TO DO 4: Don't write the output to the screen but copy the whole phrase into a separate string (without using library functions)
// Source of words see: http://dack.com/web/bullshit.html

#include <stdio.h> 
#include <stdlib.h>

char * CopySentence(const char * introduction, const char * noun, const char * verb, const char * adjective) {
	static char sentence[9999];

	int len = 0;
	for (int i = len; introduction[i] != 0; i++) {
		sentence[i] = introduction[i];
		len = i;
	}

	printf("%d\n", len);

	for (int i = 0; verb[i] != 0; i++) {
		sentence[len + i] = verb[i];
		len = len + i;
	}

	for (int i = 0; adjective[i] != 0; i++) {
		sentence[len + i] = adjective[i];
		len = i;
	}

	for (int i = len; noun[i] != 0; i++) {
		sentence[i] = noun[i];
		len = i;
	}

	return sentence;
}

int main() {
	char verbs[][20] = {
		"benchmark", "exploit", "facilitate", "generate", "implement", "leverage", "maximize",
		"mesh", "monetize", "optimize", "orchestrate", "redefine"
	};
	char nouns[][20] = {
		"action-items", "applications", "bandwidth", "communities", "e-business", "experiences",
		"infrastructures", "methodologies", "partnerships", "synergies", "solutions", "technologies"
	};
	char adjectives[][20] = {
		"bleeding-edge", "collaborative", "cross-platform", "distributed", "efficient",
		"global", "holistic", "innovative", "mission-critical", "next-generation", "out-of-the-box", "user-centric"
	};
	char introductions[][20] = {
		"You should", "Our company must", "We have to"
	};
	int number, i, v, n, a;

	printf("How much bullshit do you need?");
	scanf("%d", &number);

	while (number > 0) {
		// 12, because there 12 elements in each array of verbs, nouns and adj.
		i = rand() % 3;
		v = rand() % 12;
		n = rand() % 12;
		a = rand() % 12;

		printf("Your boss says: %s %s %s %s!\n", introductions[i], verbs[v], adjectives[a], nouns[n]);
		// printf("\n%s", CopySentence(introductions[i], nouns[n], verbs[v], adjectives[a]));
		number--;
	}
}
