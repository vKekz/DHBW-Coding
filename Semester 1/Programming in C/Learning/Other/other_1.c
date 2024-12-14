#include <stdio.h>

void A2() {
    int k = 2;
    for (int i = 1; i <= 5; i++) {
        printf("%d-", i);

        for (int j = i + 1; j <= i + 8; j++) {
            for (int l = 1; l <= k; l++) {
                printf("%d", j % 10);
            }

            k++;
            printf("-");
        }

        k = 2;
        printf("\n");
    }
}

void A2_2() {
    for (int i = 0; i < 6; i++) {
        printf("0");

        for (int j = 1; j < 50 / (i + 1); j++) {
            for (int l = 0; l < i; l++) {
                printf("-");
            }
            printf("%d", j % 10);
        }

        printf("\n");
    }
}

struct item {
    float data;
    struct item * next;
};

struct item * item_list;

float min_gerade(struct item * list) {
    if (list == NULL) {
        return 0;
    }

    struct item * temp = list;
    float data = temp -> data;

    while (temp != NULL) {
        struct item * next = temp -> next;
        float next_data = next -> data;

        if (next_data / 2 == 0 && next_data < data) {
            data = next_data;
        }

        temp = next;
    }

    return data;
}

int main() {
    // A2();
    A2_2();
    return 0;
}