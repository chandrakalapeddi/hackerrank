#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];   // buffer size large enough for input

    // Read the sentence (including spaces)
    fgets(sentence, sizeof(sentence), stdin);

    // Remove trailing newline if present
    sentence[strcspn(sentence, "\n")] = '\0';

    // Tokenize by space
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        printf("%s\n", word);
        word = strtok(NULL, " ");
    }

    return 0;
}

