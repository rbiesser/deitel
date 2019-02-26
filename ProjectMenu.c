/**
	Project Menu
	projectmenu.c 
	Purpose: Final Course Project

	Start by creating a menu that lists four of the programs you have done 
	for this course during the past four weeks. Pick one program from each 
	week 1 thru 4.

	Create a function for each of the programs and copy and paste the code 
	into the function. Do NOT copy and paste #include statements or main() 
	just everything below main. Add the code to call the function based on 
	the menu selection.

	@author Robbie Biesser
	@version 1.0 2/19/2019
	@source Deitel. (2015). C How to Program, 8th Edition.

*/

#include <stdio.h>
#include <stdlib.h> // for rand() and srand()
#include <time.h> // for time()
// #include <ctype.h>
// #include <string.h> // necessary for string functions

// prototypes
void week1(int a);
void week2(int a);
void week3(int a);
void week4(int a);

/**
 	Calculates the sum of random numbers

	@param you need to tell me how many sides and how many dice
	@return the sum of random numbers
*/
int sumOfDiceRoll(int sidesOfDie, int numDice) // C doesn't allow default values
{
	// int rolls[numDice]; // use an array if you need to keep track of each roll
	int sum = 0; // we just need to return the sum

	int i; // temp
	// loop for each dice roll
	for (i = 0; i < numDice; i++)
	{
		sum += rand() % sidesOfDie + 1; // some random number between 1 and sidesOfDie
	}

	// first idea was to hard code using 2 dice
	// this evolved into the step above
	// int roll1 = rand() % sidesOfDie + 1; // some random number between 1 and sidesOfDie
	// int roll2 = rand() % sidesOfDie + 1; // some random number between 1 and sidesOfDie

	// debugging print each calculation
	// printf("%d + %d = %d\n", roll1, roll2, roll1+roll2);
	// printf("%d\n", sum);

	// returns the sum
	// return roll1 + roll2;

	return sum;
}

/**
	adapted from a solution found at https://stackoverflow.com/a/6394166

	Counts the number of ways to obtain a desired sum 
	It seems to work for the required settings, but fails to calculate for different cases.
	This should be replaced by a more efficient probability function.
*/
int countPossibleSums(int poss, int sumto)
{
  return (poss - abs(sumto-(poss+1)))  *100000;
}

int main()
{
	// reusing array of pointers to functions from Week 3: Circle Math with Function Pointers

	// initialize array of 3 pointers to functions
	// returns void
	// accepts a double variable as an argument
	void (*f[4])(int) = {
		week1,
		week2,
		week3,
		week4
	};

	int menuSelection;

	do
	{
		system("cls"); // clear screen
		printf("%s\n", "CIS126L Week 5 Project Menu");
		printf("%s\n", "1. Week 1 - Largest Smallest");
		printf("%s\n", "2. Week 2 - Guess The Number");
		printf("%s\n", "3. Week 3 - Roll Two Dice");
		printf("%s\n", "4. Week 4 - Random Sentences");
		printf("%s\n", "5. Exit");

		printf("%s\n", "Enter an option");
		scanf("%d", &menuSelection);

		// check if the Exit option was chosen
		if (menuSelection != 5)
		{
			// invoke function at location from the menu and pass
			// the radius as an argument
			(*f[menuSelection-1])(menuSelection-1);
		}

		// repeat until exit
	} while (menuSelection != 5);
	
	return 1;

	// end

}

/**

*/
void week1(int a)
{
	// declarations
	int largest;
	int smallest;
	int integer1; // integer values to hold the inputs
	int integer2;
	int integer3; 

	// output instructions
	puts("Determine and print the largest and the smallest integers in the group");
	printf("Enter 3 integer numbers: ");
	
	scanf("%d %d %d", &integer1, &integer2, &integer3); // input the numbers

	// decision making
	largest = smallest = integer1; // the first number will be both largest and smallest

	// repeat for each number
	// check the second number
	if (integer2 < smallest) // compare to smallest
	{
		smallest = integer2;
	}
	
	if (integer2 > largest) // compare to largest
	{
		largest = integer2;
	}

	// check the third number
	if (integer3 < smallest) // compare to smallest
	{
		smallest = integer3;
	}

	if (integer3 > largest) // compare to largest
	{
		largest = integer3;
	}

	// output
	printf("The largest value is %d\n", largest); // largest
	printf("The smallest value is %d\n", smallest); // smallest

	// pause for output
	printf("Press Any Key to Continue\n");  
	char ch;
	ch = getchar(); // getchar gets a char off stdin 
	ch = getchar(); // burn the first enter press and wait for the second
	return;
	
}

/**

*/
void week2(int a)
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


	// pause for output
	printf("Press Any Key to Continue\n");  
	char ch;
	ch = getchar(); // getchar gets a char off stdin 
	ch = getchar(); // burn the first enter press and wait for the second
	
	return;
}

/**

*/
void week3(int a)
{
	srand (time(0)); // initialize the random number generator

	/* Declarations */

	int numRolls = 36000; // 36000 rolls
		
	int sidesOfDie = 6; // standard die has 6 sides; 1-based

	int numDice = 2; // default is 2 dice

	int possibleSums = sidesOfDie*numDice-numDice; // there are 11 possible sums 2-12 for (2) 6-sided dice
													 // one less than the number of dice

	int sums[possibleSums]; // we are going to keep track of sums of each roll in this array
							// the size of the sums array will change to reflect the given values

	int i; // temp
	// initialize all sums to zero
	for (i = 0; i <= possibleSums; i++)
	{
		sums[i] = 0; // zero based array
	}

	// run the main trial
	for (i = 0; i < numRolls; i++)
	{
		// printf("%d\n", sumOfTwoDiceRoll()); // debug
		
		sums[sumOfDiceRoll(sidesOfDie, numDice)-numDice]++; // zero based array
															// sum will be at least 1 for each dice
	}

	// printf("%f", (float)sums[0]/(float)numRolls);
	// header row
	printf("%10s%10s%11s%11s\n", "Sum", "Total", "Expected", "Actual");
	
	// output results
	for (i = 0; i <= possibleSums; i++)
	{
		// calculate expected and actual
		// float expected = (float)sums[i]/(float)numRolls *100;
		float expected = (countPossibleSums(sidesOfDie, i+2)/(float)numRolls);
		float actual = ((float)sums[i]/(float)numRolls) *100;
		
		printf("%10d%10d%10.3f%%%10.3f\%%\n", i+numDice, sums[i], expected, actual); // zero based array
												// sum will be at least 1 for each dice
	}

	// pause for output
	printf("\nPress Any Key to Continue\n");  
	char ch;
	ch = getchar(); // getchar gets a char off stdin 
	ch = getchar(); // burn the first enter press and wait for the second
	
	return;
}

/**

*/
void week4(int a)
{
	srand(time(0)); // seed the random number generator

	// string literals
	// https://stackoverflow.com/a/16767062
	char const *articles[] = {"the", "a", "one", "some", "any"};
	char const *nouns[] = {"boy", "girl", "dog", "town", "car"};
	char const *verbs[] = {"drove", "jumped", "ran", "walked", "skipped"};
	char const *prepositions[] = {"to", "from", "over", "under", "on"};

	// printf("%c\n", toupper(articles[0][0]));

	char sentence[80]; // variable to store a sentence

	// a C string references each letter like an element in the char array
	// "this" "that"
	// "t", "h", "i", "s"

	int i;
	for (i = 0; i < 20; i++)
	{
		/* There's a couple different ways to solve */

		/* 1. printf, but can't reuse the sentence */
		// printf("%s %s %s %s %s %s\n"
		// 		, articles[rand() % 5]
		// 		, nouns[rand() % 5]
		// 		, verbs[rand() % 5]
		// 		, prepositions[rand() % 5]
		// 		, articles[rand() % 5]
		// 		, nouns[rand() % 5]
		// 	);

		/* 2. string concatenation with the strcat function, but it takes a lot of steps */
		// strcpy(sentence, articles[rand() % 5]);
		// strcat(sentence, " ");
		// strcat(sentence, nouns[rand() % 5]);
		// strcat(sentence, " ");
		// strcat(sentence, verbs[rand() % 5]);
		// strcat(sentence, " ");
		// strcat(sentence, prepositions[rand() % 5]);
		// strcat(sentence, " ");
		// strcat(sentence, articles[rand() % 5]);
		// strcat(sentence, " ");
		// strcat(sentence, nouns[rand() % 5]);
		// strcat(sentence, ".");

		/* 3. sprintf, like the printf function and you can reuse the sentence */
		// http://www.cplusplus.com/reference/cstdio/sprintf/
		sprintf(sentence, "%s %s %s %s %s %s."
				, articles[rand() % 5]
				, nouns[rand() % 5]
				, verbs[rand() % 5]
				, prepositions[rand() % 5]
				, articles[rand() % 5]
				, nouns[rand() % 5]
			);

		/* shared by all to uppercase the first letter */
		sentence[0] = toupper(sentence[0]); // access the first char in the string like an array

		puts(sentence);

		// the initial thought
		// you can use a 2 dimensional array if you need to save each sentence
		// select randoms
		// randomNumber1 = rand() % 100;
		// sentence[][i] = "article noun verb preposition article noun";
	}

	// pause for output
	printf("\nPress Any Key to Continue\n");  
	char ch;
	ch = getchar(); // getchar gets a char off stdin 
	ch = getchar(); // burn the first enter press and wait for the second
	
	return;
}

