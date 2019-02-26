/**
	Dice Rolling
	6.19-DiceRolling.c

	Purpose: Write a program that simulates the rolling of two dice.

	6.19 (Dice Rolling) Write a program that simulates the rolling of two dice.
	The program should use rand twice to roll the first die and second die, respectively.
	The sum of the two values should then be calculated. [Note: Because each die can show
	an integer value from 1 to 6, then the sum of the two values will vary from 2 to 12,
	with 7 being the most frequent sum and 2 and 12 the least frequent sums.] Figure 6.24
	shows the 36 possible combinations of the two dice. Your program should roll the two
	dice 36,000 times. Use a one-dimensional array to tally the numbers of times each
	possible sum appears. Print the results in a tabular format. Also, determine if the
	totals are reasonable; i.e., there are six ways to roll a 7, so approximately one-sixth
	of all the rolls should be 7.

	Discussion about pre-increment vs post-increment:
	https://www.geeksforgeeks.org/pre-increment-and-post-increment-in-c/
	pre-increment: a = ++x; // both variables will have the same value
	post-increment: a = x++; // a is set to the value of x before adding 1
	** this only matters when assigning to a new variable
	** use within a for loop has the same meaning

	@author Robbie Biesser
	@version 1.0 2/12/2019
	@source Deitel. (2015). C How to Program, 8th Edition.

*/

// include the C library to perform Input/Output operations
// http://www.cplusplus.com/reference/cstdio/
#include <stdio.h> // for input/output
#include <stdlib.h> // for rand() and srand()
#include <time.h> // for time()
#include <math.h> // for abs()

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

/**
	main starts program execution
*/
int main()
{
	srand (time(0)); // initialize the random number generator

	/* Declarations */

	int numRolls = 36000; // 36000 rolls

	int sidesOfDie = 6; // standard die has 6 sides; 1-based

	int numDice = 5; // default is 2 dice

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

	return 1;

	// end
}
