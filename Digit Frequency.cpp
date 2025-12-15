#include <stdio.h>
#include <string.h>
#include <ctype.h>  // for isdigit()

int main() {
    char str[1000];
    scanf("%s", str);   // read the string (no spaces in input)

    int freq[10] = {0}; // frequency array for digits 0-9

    // Traverse the string
    for (int i = 0; i < strlen(str); i++) {
        if (isdigit(str[i])) {
            freq[str[i] - '0']++;  // convert char digit to int index
        }
    }

    // Print frequencies
    for (int i = 0; i < 10; i++) {
        printf("%d", freq[i]);
        if (i < 9) printf(" ");  // space between numbers
    }
    printf("\n");

    return 0;
}

