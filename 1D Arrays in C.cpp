#include <stdio.h>
#include <stdlib.h>  // for malloc and free

int main() {
    int n;
    scanf("%d", &n);

    // Dynamically allocate memory for n integers
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1; // exit if malloc fails
    }

    // Read n integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate sum
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // Print result
    printf("%d\n", sum);

    // Free allocated memory
    free(arr);

    return 0;
}

