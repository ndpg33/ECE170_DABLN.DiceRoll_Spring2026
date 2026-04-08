#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int main(void) {
	
	printf("-------------- D & D Dice Roller --------------\n");
	printf("By: Nick D, Ben B, Dylan C, Logan E, Andrew C\n"); 

	printf("\n");
	printf("Any combination of dice are available to roll: \n");
	printf("Ex: d2, d3, d4, etc... (# has to be positive)\n");
	
	
	printf("\n");
	printf("*input \"end\" to stop the program*\n"); 
	printf("*Iif you wish to roll more than one dice at a time, add a number before the die\n");
	printf("Ex: \"2d6\" will roll 2 6 sided die\n"); 
	printf("\n");
	printf("\n");
	printf("\n");


	//Start for loop to keep rolling dice until user inputs escape sequence
	
	srand(time(NULL));



	char input[20];
	int sides;
	int numberOf;
	int output;
	int multiRoll;
	int sum = 0;
	
	while (1) {

		//Ask use for input and scan, assing it as a string to an array -> input[]
		printf("Enter dice: ");
		scanf_s("%s", input, (unsigned)_countof(input));

		//End Sequence
		if (strcmp(input, "end") == 0) {
			printf("Exiting Dice Roller...");
			break;
		}

		//---------------------------------------------------------------------------------------------------

		//more than one dice
		if ((sscanf_s(input, "%dd%d", &numberOf, &sides) == 2 ||sscanf_s(input, "%dD%d", &numberOf, &sides) == 2) && sides > 0) {
			//Roll more than one dice
			sum = 0;
			printf("Your rolls: \n");
			for (int i = 0; i < numberOf; i++) {

				multiRoll = rand() % sides + 1;
				sum += multiRoll;
				printf("%d ", multiRoll);

			}

			printf("\n");
			printf("The sum of your rolls are: %d\n", sum);
			printf("\n");

		}

		//---------------------------------------------------------------------------------------------------

		//one dice
		//sscanf_s reads data from a string rather than user input, in this case, from the string data in array input[]
		else if ((sscanf_s(input, "d%d", &sides) == 1 || sscanf_s(input, "D%d", &sides) == 1) && sides > 0) { 
			//Fall back/roll one die

			output = rand() % sides + 1;
			printf("You rolled a: %d\n", output);
			printf("\n");
			numberOf = 1;
		}

		//---------------------------------------------------------------------------------------------------

		//Invalid entry
		else {

			printf("Invalid input!\n");
			printf("\n");

		}

	}
	



	printf("\n"); 
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");

}