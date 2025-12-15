#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// Function to calculate sum of marks based on gender
int marks_summation(int marks[], int number_of_students, char gender) {
    int sum = 0;
    int start_index;

    // Boys are at even indices, girls at odd indices
    if (gender == 'b') {
        start_index = 0;  // boys start at index 0
    } else {
        start_index = 1;  // girls start at index 1
    }

    // Traverse array with step of 2
    for (int i = start_index; i < number_of_students; i += 2) {
        sum += marks[i];
    }

    return sum;
}

int marks() {
    int number_of_students;
    scanf("%d", &number_of_students);

    int marks[number_of_students];
    for (int i = 0; i < number_of_students; i++) {
        scanf("%d", &marks[i]);
    }

    char gender;
    scanf(" %c", &gender);  // space before %c to consume newline

    printf("%d\n", marks_summation(marks, number_of_students, gender));

    return 0;
}
int main() {
    int number_of_students;
    char gender;
    int sum;
  
    scanf("%d", &number_of_students);
    int *marks = (int *) malloc(number_of_students * sizeof (int));
 
    for (int student = 0; student < number_of_students; student++) {
        scanf("%d", (marks + student));
    }
    
    scanf(" %c", &gender);
    sum = marks_summation(marks, number_of_students, gender);
    printf("%d", sum);
    free(marks);
 
    return 0;
}
