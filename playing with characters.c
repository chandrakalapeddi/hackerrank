#include <stdio.h>

int main() {
    char ch;
    char str[100];
    char sentence[100];

    // Read a character
    scanf("%c", &ch);

    // Read a string (until space)
    scanf("%s", str);

    // Read a sentence (until newline)
    scanf("\n"); // consume leftover newline
    scanf("%[^\n]%*c", sentence);

    // Print outputs
    printf("%c\n", ch);
    printf("%s\n", str);
    printf("%s\n", sentence);

    return 0;
}
