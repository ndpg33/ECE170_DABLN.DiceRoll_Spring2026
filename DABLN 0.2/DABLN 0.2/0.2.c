#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(void) {
    printf("-------------- D & D Dice Roller --------------\n");
    printf("By: Nick D, Ben B, Dylan C, Logan E, Andrew C\n");

    printf("\n");
    printf("Any combination of dice are available to roll:\n");
    printf("Ex: d2, d3, d4, etc... (# has to be positive)\n");

    printf("\n");
    printf("*input \"end\" to stop the program*\n");
    printf("*If you wish to roll more than one die at a time, add a number before the die\n");
    printf("Ex: \"2d6\" will roll 2 6-sided dice\n");
    printf("\n\n\n");

    srand((unsigned)time(NULL));

    char input[20];
    char dieChar;
    int sides;
    int numberOf;
    int output;
    int multiRoll;
    int sum;

    while (1) {
        printf("Enter dice: ");
        scanf_s("%19s", input, (unsigned)_countof(input));

        if (strcmp(input, "end") == 0) {
            printf("Exiting Dice Roller...");
            break;
        }

        if (sscanf_s(input, "%d%c%d", &numberOf, &dieChar, 1, &sides) == 3 &&
            (dieChar == 'd' || dieChar == 'D') &&
            numberOf > 0 && sides > 0) {

            sum = 0;
            printf("Your rolls:\n");

            for (int i = 0; i < numberOf; i++) {
                multiRoll = rand() % sides + 1;
                sum += multiRoll;
                printf("%d ", multiRoll);
            }

            printf("\nTotal: %d\n\n", sum);
        }
        else if (sscanf_s(input, "%c%d", &dieChar, 1, &sides) == 2 &&
            (dieChar == 'd' || dieChar == 'D') &&
            sides > 0) {

            output = rand() % sides + 1;
            printf("You rolled a: %d\n\n", output);
        }
        else {
            printf("Invalid input!\n\n");
        }
    }

    return 0;
}