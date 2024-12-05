#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ExerciseOne() {
    // char pattern[6] = { 'k', 'u', 'e', 'r', 'z', 'e' };
    int c = 9999;

    char pattern[c];
    printf("Word: \n");
    scanf("%s", pattern);

    c = strlen(pattern);

    for (int i = c; i > 0; i--) {
        for (int j = i; j > 0; j--) {
            char word[i];
            for (int k = 0; k < i; k++) {
                word[k] = pattern[k];
            }
            word[i] = '\0';

            printf("%s%d!", word, j);
        }
        printf("\n");
    }
}

void DecimalToBinary(int number) {
	unsigned int m = 0, size = number;
	while (number > 0) {
		const int binary = number & 1;
		// printf("%d", binary);

		m <<= 1;
		m |= binary;
		number >>= 1;
	}

	do {
		printf("%d", m & 1);
		m >>= 1;
		size >>= 1;
	} while (size > 0);
}

// 2.) a)
int laenge(int n) {
	unsigned int m = 0;
    int counter = 0;

	while (n > 0) {
		const int binary = n & 1;

		m <<= 1;
		m |= binary;
		n >>= 1;

        // 2.) b) nur counter++ für 0 und 1 bits
        if (binary == 1) {
            counter++;
        }
	}

    return counter;
}

// 3.)
int kleiner(int a[], int cnt, int max) {
    int counter = 0;

    for (int i = 0; i < cnt; i++) {
        if (a[i] > max) {

            for (int j = i; j < cnt; j++) {
                a[j] = a[j + 1];
                a[cnt] = -1;
            }
            
            counter++;
        }
    }

    return cnt - counter;
}

// 4.)
short * Pointer(int n) {
    return malloc(n * sizeof(short));
}
// 5.) a)
enum Gender{
    male,female
};

struct Person{
    int jahre[3];
    enum Gender gender;
};
// 2017 3.) b)
int length(char s[]){
    int i = 0;
    while(s[i] != '\0'){
        i++;
    } 
    return i;
}

// 2017 4.) a)
struct Person2{
    enum Gender gender;
    int jahre[2];
};

typedef union t_mytype{
    int t_int;
} MyType;

union t_mytype* getmemory(int n){
    // union t_mytype* pointer = malloc(n * sizeof(union t_mytype));
    // return pointer;
    return malloc(n * sizeof(union t_mytype));
}

void doubleFunction(int n){
    union t_mytype* pointer = getmemory(n);
    if (pointer == NULL) {
        prinft("Konnte nicht Speicher besetzten");
    } else {
        usememory();
        free(pointer);
    }
}

int main() {
    char str[] = "Test2";
    char str2[] = { 'T', 'e', 's', 't' };

    printf("%s\n", str);
    printf("%s", str2);

    //ExerciseOne();
    // printf("Länge: %d", laenge(31));

    // Zu 3.)
    int array[5] = { 10, 23, 4, 95, 13};
    int result = kleiner(array, 5, 20);
    printf("%d\n", result);

    for(int k = 0; k < 5; k++) {
        printf("%d ", array[k]);
    }

    // Zu 4.) b)
    int n = 1000;
    short * pointer = Pointer(n);

    for (int i = 0; i < n; i++) {
        int rnd = 0;
        while (rnd < 11) {
            rnd = (rand() % 100) + 1;
        }

        pointer[i] = rnd;
        printf("%d ", pointer[i]);
    }

    // Zu 4.) c)
    free(pointer);

    // Zu 5.) b)
   struct Person Persons[12];
   // Zu 5.) c)
   struct Person * pointer2 = Persons + 2;
   pointer2 ->gender = female;
   printf("%d", pointer2->gender);

   char Name[]= { 'V', 'i', 'g', 'a', 'n', '\0' };
   char Name2[] = "Vigan";

   printf("%d", length(Name2));

   struct Person2 students[10];
   for(int i = 0; i < 10; i++)
   {
        students[i].gender = male;

        for (int j = 0; j < 2; j++) {
            students[i].jahre[j] = 0;
        }
   }
}
