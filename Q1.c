#include <stdio.h>
#include <stdlib.h>

//Function declarations
float returnAverage(int marksArray[10]);

//Functions
float returnAverage(int marksArray[10]) {
    int total = 0;
    int studentIndex = 0;

    for (studentIndex; studentIndex < 10; studentIndex++) {
        total += marksArray[studentIndex];
    }

    return total / 10.0;
}

void main () {
    int studentIndex = 0;
    int marksArray[10] = {0};

    for (studentIndex; studentIndex < 10; studentIndex++) {
        printf("Enter marks of student %d: ", studentIndex + 1);
        scanf("%d", &marksArray[studentIndex]);

        if (marksArray[studentIndex] > 100 || marksArray[studentIndex] < 0) {
            printf("%d not in range 0 - 100. Re-enter marks for student-%d.\n\n", marksArray[studentIndex], studentIndex + 1);
            studentIndex--;
        }
    }

    printf("Student Marks: ");
    studentIndex = 0;
    for (studentIndex; studentIndex < 10; studentIndex++) {
        printf("%d, ", marksArray[studentIndex]);
    }

    printf("\n\nThe average of the student marks is = %.2f", returnAverage(marksArray));
}