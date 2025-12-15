#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int a, b;
    float x, y;

    // Read two integers
    scanf("%d %d", &a, &b);

    // Read two floats
    scanf("%f %f", &x, &y);

    // Integer operations
    int int_sum = a + b;
    int int_diff = a - b;

    // Float operations
    float float_sum = x + y;
    float float_diff = x - y;

    // Print results
    printf("%d %d\n", int_sum, int_diff);
    printf("%.1f %.1f\n", float_sum, float_diff);

    return 0;
}

