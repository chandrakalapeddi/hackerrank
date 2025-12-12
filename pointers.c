#include <stdio.h>

// Helper function to return maximum of two integers
int max(int x, int y) {
    return (x > y) ? x : y;
}

// Function to return maximum of four integers
int max_of_four(int a, int b, int c, int d) {
    return max(max(a, b), max(c, d));
}

int main() {
    int a, b, c, d;
    
    // Reading four integers (I/O handled automatically in some platforms)
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    // Printing the greatest of the four
    printf("%d\n", max_of_four(a, b, c, d));
    
    return 0;
}


