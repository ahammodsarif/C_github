#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* countAndSay(int n) {
    char *current = malloc(100000 * sizeof(char));
    char *next = malloc(100000 * sizeof(char));

    strcpy(current, "1");

    for (int i = 1; i < n; i++) {
        int j = 0, k = 0;

        while (current[j] != '\0') {
            char digit = current[j];
            int count = 0;

            while (current[j] != '\0' &&
                   current[j] == digit) {
                count++;
                j++;
            }

            k += sprintf(next + k, "%d%c", count, digit);
        }

        next[k] = '\0';

        char *temp = current;
        current = next;
        next = temp;
    }

    free(next);
    return current;
}

int main() {
    int n;
    scanf("%d", &n);

    char *result = countAndSay(n);

    printf("%s\n", result);

    free(result);

    return 0;
}
