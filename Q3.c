#include <stdio.h>
#include <stdlib.h>

//Global declarations
const int passLimit = 35;

void main () {
    int marks[5][5] = {0};
    int loopIndex = 0;

    printf("Enter student index no.");
    scanf("%d", &marks[loopIndex][0]);

    while (marks[loopIndex][0] >= 1) {
        do {
            printf("\tEnter marks: ");
            scanf("%d", &marks[loopIndex][1]);

        } while (marks[loopIndex][1] < 0 || marks[loopIndex][1] > 100);

        loopIndex++;
        printf("Enter student index no.");
        scanf("%d", &marks[loopIndex][0]);
    }

    printf("\nStudents who passed the examination:\n\t");
    int tempLoopIndex = loopIndex;

    for (--tempLoopIndex;  tempLoopIndex > -1; tempLoopIndex--) {
        if (marks[tempLoopIndex][1] >= passLimit) {
            printf("%d, ", marks[tempLoopIndex][0]);
        }
    }

    printf("\nStudents who failed the examination:\n\t");

    for (--loopIndex;  loopIndex > -1; loopIndex--) {
        if (marks[loopIndex][1] < passLimit) {
            printf("%d, ", marks[loopIndex][0]);
        }
    }
}