/* devowelizer / revowelizer 
 TO DO 1: Extend the program such that it replaces all vowels in the text with other vowels.
 TO DO 2: Extend the program such that the replacement vowel is chosen randomly.
          Hint: List the vowels in an additional array ...
                Use rand() to generate random numbers
 TO DO 3: Modify the program such that it removes all vowels (and shortens the text accordingly)
 TO DO 4 (optional): Write an encryption/decryption program which encodes texts by defining
         in a table how each character shall be replaced by another one. 
*/ 

#include <stdio.h>

int IsVowel(const char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
    || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
}

char* Encrypt(char input[]) {
    const char encodings[2][26] = {
        {
            'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
            'w', 'x', 'y', 'z'
        },
        {
            'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f',
            'e', 'd', 'c', 'b', 'a'
        }
    };

    for (int i = 0; input[i]; i++) {
        const unsigned char c = input[i];
        for (int j = 0; j < 26; j++) {
            if (c == encodings[0][j]) {
                input[i] = encodings[1][j];
            }
        }
    }

    return input;
}

char* Decrypt(char input[]) {
    const char encodings[2][26] = {
        {
            'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
            'w', 'x', 'y', 'z'
        },
        {
            'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f',
            'e', 'd', 'c', 'b', 'a'
        }
    };

    for (int i = 0; input[i]; i++) {
        const unsigned char c = input[i];
        for (int j = 0; j < 26; j++) {
            if (c == encodings[1][j]) {
                input[i] = encodings[0][j];
            }
        }
    }

    return input;
}

int main() {
    char text[1000];
    const char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    printf("Please enter your text:");
    gets(text);

    char* encrypted = Encrypt(text);
    printf("Encrypted: %s\n", encrypted);

    char* decrypted = Decrypt(encrypted);
    printf("Decrypted: %s\n", decrypted);

    // int i = 0;
    // while (text[i] != 0) {
    //     const char c = text[i];
    //     if (IsVowel(c)) {
    //         const char replacement_vowel = vowels[rand() % sizeof(vowels)];
    //         text[i] = replacement_vowel;
    //     }
    //     i += 1;
    // }
    // printf("%s\n", text);
    //
    // i = 0;
    // char clean_text[10000];
    // int j = 0;

    // while (text[i] != 0) {
    //     const char c = text[i];
    //     if (IsVowel(c)) {
    //         text[i] = ' ';
    //
    //         for (int j = 0; j < i; j++) {
    //             char first = text[j];
    //             char compare = text[j + 1];
    //             if (first <= compare) {
    //                 char temp = text[j];
    //                 text[j] = text[j + 1];
    //                 text[j + 1] = temp;
    //             }
    //         }
            // clean_text[j] = c;
            // j++;
        // }

        // i++;
    // }
    // Null-byte
    // clean_text[j] = 0;

    // printf("%s\n", text);
}
