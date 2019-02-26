/**
	Guess The Number
	5.32-GuessTheNumber.c

	Purpose: Implement a number guessing game.

	5.32	(Guess the Number) Write a C program that plays the game of
	"guess the number" as follows: Your program chooses the number to be 
	guessed by selecting an integer at random in the range 1 to 1000.

	[Note: The searching technique employed in this problem is called
	binary search. We�ll say more about this in the next problem.]

	Changelog:

	1.2 02/12/2019 Added the ability to set the difficulty level by entering
	a range of numbers.

	1.1 02/05/2019 stat tracking to make the game more competitive and an
	initial attempt at runtime.

	@author Robbie Biesser
	@version 1.2 2/12/2019
	@source Deitel. (2015). C How to Program, 8th Edition.

*/

// include the C library to perform Input/Output operations
// http://www.cplusplus.com/reference/cstdio/
#include <stdio.h> // for input/output
#include <stdlib.h> // for rand() and srand()
#include <time.h> // for time()

/**
	main starts program execution
*/
int main()
{
	int maxRange = 1000; // range of numbers

	// allow the user to choose difficulty at runtime
	printf("%s", "Choose the difficulty. Enter a max for the range of numbers (1 - 1000): ");
	scanf("%d", &maxRange);

	char readyToPlay = 'y'; // sentinel for main

	// do..while starts at 1
	int numRounds = 0; // tracking rounds
	int numGuesses = 0; // tracking how many guesses
	int totalGuesses = 0;
	int recordGuesses = maxRange;
	clock_t runtime = clock(); // https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/

	do // loop allows multiple plays until user exits
	{
		srand (time(0)); // a new random number will be initilized each round

		int secretNumber = rand() % maxRange + 1; // some random number between 1 and maxRange
		int guess = 0; // user input
		numGuesses = 1; // reset number of guesses each round

		// all this for a response prompt
		if (numRounds == 0) // round 1
		{
			printf("I have a number between 1 and %d.\n\nCan you guess my number?\n\nPlease type your first guess.\n? ", maxRange);
		}
		else // new
		{
			printf("I have a new number between 1 and %d.\n\nCan you guess my number?\n\nPlease type your first guess.\n? ", maxRange);
		}

		// get the first guess
		scanf("%d", &guess);

		// loop until user guesses the secret number
		// makes more sense as a while instead of do..while, incase guess is correct on first try!
		while ( guess != secretNumber )
		{
			// give special warning guess is outside of the range
			if ( guess < 1 || guess > maxRange)
			{
				printf("You will have better luck if your guess is between 1 and %d!\n", maxRange);
			}
			else
			{
				// we know the secret number has not been guessed yet.
				// display a hint to the user.
				if ( guess < secretNumber)
				{
					puts("Too low. Try again.");

				}
				else // we know it is greater
				{
					puts("Too high. Try again.");
				}
			}

			numGuesses++; // increment

			// get the next guess then enter the loop again
			printf("%s", "? ");
			scanf("%d", &guess);
		}

		// correct
		// you know if the inner loop exits, the player guessed the correct number
		if (numGuesses == 1)
		{
			// for the chance this may happen
			puts("Excellent! You guessed the number on the first try!");
		}
		else
		{
			// most likely
			printf("Excellent! You guessed the number in %d tries!\n", numGuesses);
		}

		// prompt to play again
		printf("%s","\n\nWould you like to play again (y or n)? ");

		// the space in scanf skips the enter key and waits for char input
		// https://gsamaras.wordpress.com/code/caution-when-reading-char-with-scanf-c/
		scanf(" %c", &readyToPlay); // wait for user input

		// updating stats at the end of each round
		numRounds++; // increment the round
		totalGuesses+=numGuesses; // add the number of guesses to the total

		// checking the record at the end of each round
		if (numGuesses < recordGuesses)
		{
			recordGuesses = numGuesses; // reset record
		}

	// loop until user exits
	} while ( readyToPlay != 'n' );

	// calculate the total time the app has been running
	// https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/
	runtime = (double)(clock() - runtime) / CLOCKS_PER_SEC;

	// begin output stats
	printf("\nSee you later!\nYou played %d rounds and made a total of %d guesses", numRounds, totalGuesses);

	// print runtime
	// in time hope to figure out an easier way to print time
	// this will most likely turn into a function call
	if ( runtime < 60 )
	{
		printf(" in %d seconds.\n", runtime);
	}
	else
	{
		printf(" in %d minutes.\n", runtime / 60);
	}

	// print stats
	// average
	printf("Average number of guesses per round: %d\n", totalGuesses/numRounds);
	// best record
	printf("Record number of guesses: %d\n\n", recordGuesses);

	return 1;

	// end
}
