#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Get modifier Function -> Makes sure each input it formatted correctly
int getModifier(const char abilityName[]) {
    char input[20];
    int mod;
    char extra;

    while (1) {
        printf("Enter %s modifier: ", abilityName);
        scanf_s("%19s", input, (unsigned)_countof(input));

        if (sscanf_s(input, "%d%c", &mod, &extra, 1) == 1 && mod >= -5 && mod <= 5) {
            return mod;
        }
        else {
            printf("Invalid input! Please enter a whole number from -5 to 5.\n");
        }
    }
}


int main(void) {
    printf("-------------- D & D Dice Roller --------------\n");
    printf("By: Nick D, Ben B, Dylan C, Logan E, Andrew C\n");
    printf("\n");

    printf("----------------------------------------------------\n");

    printf("Please input your ability modifiers: \n");
    printf("(these will add/subtract to your ability checks)\n");
    printf("Formatted as \"-5\" to \"+5\"\n");
    printf("\n");

    int strMod, dexMod, conMod, intMod, wisMod, chaMod;

    printf("Enter your character modifiers:\n");
    strMod = getModifier("Strength");
    dexMod = getModifier("Dexterity");
    conMod = getModifier("Constitution");
    intMod = getModifier("Intelligence");
    wisMod = getModifier("Wisdom");
    chaMod = getModifier("Charisma");

    printf("----------------------------------------------------\n");

    printf("Any combination of dice are available to roll:\n");
    printf("Ex: d2, d3, d4, etc... (# has to be positive)\n");
    printf("*If you wish to roll more than one die at a time, add a number before the die\n");
    printf("Ex: \"2d6\" will roll 2 6-sided dice\n");

    printf("----------------------------------------------------\n");

    printf("If you wish to roll an ability check: \n");
    printf("Format your input as \"check dex\"\n"); 
    printf("Strenght -> str\n");
    printf("Dexterity -> dex\n");
    printf("Constitution -> con\n");
    printf("Intellegence -> int\n");
    printf("Wisdom -> wis\n");
    printf("Charisma -> cha\n"); 

    printf("\n");

    printf("\n");
    printf("*input \"end\" to stop the program*\n");
    
    printf("\n\n\n");

    srand((unsigned)time(NULL));

    char input[50];
    char dieChar;
    int sides;
    int numberOf;
    int output;
    int multiRoll;
    int sum;

    while (1) {
        printf("Enter dice or check: ");
        scanf_s(" %49[^\n]", input, (unsigned)_countof(input));

        if (strcmp(input, "end") == 0) {
            printf("Exiting Dice Roller...");
            break;
        }
        else if (strcmp(input, "check str") == 0) {
            output = rand() % 20 + 1;
            printf("Strength Check\n");
            printf("Rolled: %d\n", output);
            printf("Modifier: %+d\n", strMod);
            printf("Total: %d\n\n", output + strMod);
        }
        else if (strcmp(input, "check dex") == 0) {
            output = rand() % 20 + 1;
            printf("Dexterity Check\n");
            printf("Rolled: %d\n", output);
            printf("Modifier: %+d\n", dexMod);
            printf("Total: %d\n\n", output + dexMod);
        }
        else if (strcmp(input, "check con") == 0) {
            output = rand() % 20 + 1;
            printf("Constitution Check\n");
            printf("Rolled: %d\n", output);
            printf("Modifier: %+d\n", conMod);
            printf("Total: %d\n\n", output + conMod);
        }
        else if (strcmp(input, "check int") == 0) {
            output = rand() % 20 + 1;
            printf("Intelligence Check\n");
            printf("Rolled: %d\n", output);
            printf("Modifier: %+d\n", intMod);
            printf("Total: %d\n\n", output + intMod);
        }
        else if (strcmp(input, "check wis") == 0) {
            output = rand() % 20 + 1;
            printf("Wisdom Check\n");
            printf("Rolled: %d\n", output);
            printf("Modifier: %+d\n", wisMod);
            printf("Total: %d\n\n", output + wisMod);
        }
        else if (strcmp(input, "check cha") == 0) {
            output = rand() % 20 + 1;
            printf("Charisma Check\n");
            printf("Rolled: %d\n", output);
            printf("Modifier: %+d\n", chaMod);
            printf("Total: %d\n\n", output + chaMod);
        }
        else if (sscanf_s(input, "%d%c%d", &numberOf, &dieChar, 1, &sides) == 3 &&
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
}