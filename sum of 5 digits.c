#include <stdio.h>

int main() {
    int n, sum = 0;

    // Input: a five-digit number
    scanf("%d", &n);

    // Extract digits and add them
    sum += n % 10;  // last digit
    n = n / 10;

    sum += n % 10;
    n = n / 10;

    sum += n % 10;
    n = n / 10;

    sum += n % 10;
    n = n / 10;

    sum += n % 10;  // first digit

    // Output: sum of digits
    printf("%d\n", sum);

    return 0;
}

