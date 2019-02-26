/**
	Math Practice Project
	Math_Practice_Project.c
	Purpose: Step 4. Adding selection of difficulty and statistics.

	For this project, you will create a program that will test the user’s proficiency
	at solving different types of math problems. The program will be menu driven. The
	user will select either addition, subtraction, multiplication or division problems.
	The program will then display a problem, prompt the user for an answer and then
	check the answer displaying an appropriate message to the user whether their answer
	was correct or incorrect. The program will also keep statistics on how many problems
	were answered correctly.

	CHANGELOG
	version 1.0 1/23/2019
	This week you will create the flowchart and pseudocode for program that
	will display a math problem (addition) to the user. Allow the user to enter their
	answer and check to see if they were right or wrong. Make up the problem and hard
	code it into our program.

	version 2.0 1/24/2019
	This week, you will create the flowchart and pseudocode for the main menu, which
	will allow the user to select the type of math problem they want or exit the program.
	This is the control menu. Continue with the project by adding the subtraction,
	multiplication and division functions. To test the menu function completely you will
	need to write all of the functions. The addition function should be working but the
	remaining functions are empty. These empty functions are called “blackboxes”. You
	will also add a random generator to create the math problem's operands.

	version 3.0 2/13/2019
	This week, you will continue with the project by adding the subtraction, multiplication,
	and division functions. Create the flowchart for the remaining functions. Pay particular
	attention to the division function. You will want to do only integer division showing
	the answer and remainder back to the user. Prompt the user for both the answer and
	remainder for all division problems. Use the Modulus operator to calculate the correct
	answer and remainder. Also, include logic to make the numerator the larger of the two
	numbers to avoid answers less than 1.

	I found that because the division problem requires 2 inputs, I need to have each function
	do the input and comparison to the correct answer. Rewrote those functions to have a
	boolean return type to main and then main prints the output message.

	version 4.0 2/18/2019
	This week, you will complete the application by adding functions to allow the user to
	select problems of varying degrees of difficulty and keep statistics on number of correct
	answers vs total number of problems attempted.

	@author Robbie Biesser
	@version 4.0 2/18/2019

*/

// include the C library to perform Input/Output operations
// http://www.cplusplus.com/reference/cstdio/
#include <stdio.h> // for input/output
#include <stdlib.h> // for rand() and srand()
#include <time.h> // for time()
#include <string.h>

/**
    Print the addition problem

    @param correctAnswer is returned by reference
    @param randomNumber1, randomNumber2
    @return boolean
*/
int additionProblem(char *correctAnswer, int randomNumber1, int randomNumber2);

/**
    Print the subtraction problem

    @param correctAnswer is returned by reference
    @param randomNumber1, randomNumber2
    @return boolean
*/
int subtractionProblem(char *correctAnswer, int randomNumber1, int randomNumber2);

/**
    Print the multiplication problem

    @param correctAnswer is returned by reference
    @param randomNumber1, randomNumber2
    @return boolean
*/
int multiplicationProblem(char *correctAnswer, int randomNumber1, int randomNumber2);

/**
    Print the division problem

    @param correctAnswer is returned by reference
    @param randomNumber1, randomNumber2
    @return boolean
*/
int divisionProblem(char *correctAnswer, int randomNumber1, int randomNumber2);

/**
	Set the difficulty

	@param difficulty returned by reference
*/
void chooseDifficulty(char * difficulty);

/**
	Display result of each math problem and returns 1 or 0 which is used to update
	correctAnswers counter

	@param integer isCorrect
	@param string correctAnswer
	@return boolean
*/
int printIsCorrect(int isCorrect, char * correctAnswer);

// main starts program execution
int main(void)
{
	// declarations
	// int userAnswer;
	char correctAnswer[10]; // holds string representation of answer from math functions
							// 10 is an arbitrary number and may limit possible answers available
	int menuSelection;
	int randomNumber1;
	int randomNumber2;
	int isCorrect; // boolean return from math functions

	char difficulty = ' ';

	/* initially only need to track totals
		would need more variables or larger data structure to track each problem and difficulty */
	int totalProblems = 0; // tracking statistics
	int correctAnswers = 0; // tracking statistics

	do // allow the app to keep running until the user quits
	{
		srand(time(0)); // seed the random number generator

		// these random numbers will be used for every question
		// and change for each iteration
		randomNumber1 = rand();// % 100; // assign random numbers
		randomNumber2 = rand();// % 100;

		// reset answers
		// double quote !important
		strcpy(correctAnswer, ""); // reset correctAnswer
		isCorrect = 0; // boolean

		// print the menu
		puts("");
		puts("Math Practice Program Main Menu");
		puts("1. Addition");
		puts("2. Subtraction");
		puts("3. Multiplication");
		puts("4. Division");
		puts("5. Exit");
		puts("6. Reset Difficulty");
		printf("%s", "Select an option: ");
		scanf("%d", &menuSelection);
		puts("");

		// only set difficulty one time and choose menu 6 to reset
		if (difficulty == ' ')
		{

			chooseDifficulty(&difficulty); // pass by reference

			// debug: character is represented as a digit
			// printf(" difficulty %c : %d\n", difficulty, difficulty);
		}

		// random number gets chose before choosing the problem type
		// you could also combine this with the chooseDifficulty function
		switch(difficulty)
		{
			// Easy – problems using numbers 0 thru 10
			case 'e':
				randomNumber1 = randomNumber1 % 10; // assign random numbers
				randomNumber2 = randomNumber2 % 10;
				// printf("%d %d\n", randomNumber1, randomNumber2);
				break;
			// Medium – problems 11 thru 100
			case 'm':
				randomNumber1 = randomNumber1 % 100 + 1; // assign random numbers
				randomNumber2 = randomNumber2 % 100 + 1;
				break;
			// Difficult – problems 100 – 1000
			case 'h':
				randomNumber1 = randomNumber1 % 1000 + 1; // assign random numbers
				randomNumber2 = randomNumber2 % 1000 + 1;
				break;
			// default:
				// never runs
				// difficulty wil not make it out of the chooceDifficulty function
				// if not e, m, or h
				// printf("%s", "Please enter e, m, or h");
				// difficulty = ' ';
		}

		// menuSelection must be one of the choices from the menu
		// each type of math problem handles the user input and validation of correct answer
		// these functions are essentially the same with the exception that division asks for a
		// remainder.
		switch (menuSelection)
		{
			// addition
			case 1:
				// correctAnswer is an addition problem
				isCorrect = additionProblem(correctAnswer, randomNumber1, randomNumber2);
				correctAnswers += printIsCorrect(isCorrect, correctAnswer);
				totalProblems++;
				break;

			// subtraction
			case 2:
				// correctAnswer is an subtraction problem
				isCorrect = subtractionProblem(correctAnswer, randomNumber1, randomNumber2);
				correctAnswers += printIsCorrect(isCorrect, correctAnswer);
				totalProblems++;
				break;

			// multiplication
			case 3:
				// correctAnswer is an multiplication problem
				isCorrect = multiplicationProblem(correctAnswer, randomNumber1, randomNumber2);
				correctAnswers += printIsCorrect(isCorrect, correctAnswer);
				totalProblems++;
				break;

			// division
			case 4:
				// correctAnswer is an division problem
				isCorrect = divisionProblem(correctAnswer, randomNumber1, randomNumber2);
				correctAnswers += printIsCorrect(isCorrect, correctAnswer);
				totalProblems++;
				break;

			// exit
			case 5:
				//
				break;

			case 6:
				difficulty = ' '; // reset difficulty
				chooseDifficulty(&difficulty);  // pass by reference
				break;

			// invalid choice
			default:
				puts("Invalid option: select from the menu below");
				break;

		} // exit switch

		// do something within the loop

	// print the menu again until the user exits
	} while(menuSelection != 5);

	// print statistics
	printf("You attempted %d problems and got %d correct\n", totalProblems, correctAnswers);
	printf("For a percentage correct of %.2f%%\n", (float)correctAnswers/totalProblems*100);

	return 1;

	// end
}

/**
	Display result of each math problem and returns 1 or 0 which is used to update
	correctAnswers counter

	@param integer isCorrect
	@param string correctAnswer
	@return boolean
*/
int printIsCorrect(int isCorrect, char * correctAnswer)
{
	// each type of math problem handles the user input and validation of correct answer
		// correctAnswer is a string passed to each function by reference and will contain the
		// correct answer from the math function performed.
		// 1. now, we print a message to the user
		if (isCorrect)
		{
			// 4. output
			puts("Correct"); // correct
			return 1;
		}
		else
		{
			// 4. output
			printf("Incorrect, the correct answer is %s\n", correctAnswer); // wrong answer
			return 0;
		}
}

/**
	Set the difficulty

	@param difficulty returned by reference
*/
void chooseDifficulty(char * difficulty)
{

	// difficulty initialized to empty char
	// if the user has already set the difficulty do not ask them to set again
	// added menu option to reset difficulty
	// on first run, difficulty will be ' ' (space)
	// exit loop when difficulty is e, m, or h
	while (*difficulty == ' ' || !(*difficulty == 'e' || *difficulty == 'm' || *difficulty == 'h'))
	{

		// debug: character is represented as a digit
		// printf(" difficulty %c : %d\n", *difficulty, difficulty[0]);

		if (*difficulty == ' ') // dereference pointer
		{
			// difficulty has not been set yet
			printf("%s", "Select difficulty level e-easy m-medium h-hard: ");
			scanf(" %c", difficulty); // space is important!; read into memory location by reference
		}
		else
		{
			// user entered a value but it wasn't e, m, or h
			printf("%s", "Please enter e, m, or h: ");
			scanf(" %c", difficulty); // space is important!
		}
	}
}

/**
    Print the addition problem

	@param correctAnswer is returned by reference
    @param randomNumber1, randomNumber2
    @return boolean
*/
int additionProblem(char *correctAnswer, int randomNumber1, int randomNumber2)
{
	// temp variables to get input from user
	int userAnswer;
	// output problem
	printf("%d + %d = ? ", randomNumber1, randomNumber2);
	// 2. get input
	scanf("%d", &userAnswer);

	// correctAnswer = (char) (randomNumber1 + randomNumber2);

	// http://www.cplusplus.com/reference/cstdlib/itoa/?kw=itoa
	// itoa((randomNumber1 + randomNumber2), correctAnswer, 10);
	sprintf(correctAnswer, "%d", randomNumber1 + randomNumber2);


	// C has the shorthand (ternary) if operator
	// http://www.cplusplus.com/forum/articles/14631/
	return ((randomNumber1 + randomNumber2) == userAnswer ) ? 1 : 0;
}

/**
    Print the subtraction problem

	@param correctAnswer is returned by reference
    @param randomNumber1, randomNumber2
    @return boolean
*/
int subtractionProblem(char *correctAnswer, int randomNumber1, int randomNumber2)
{
	// temp variables to get input from user
	int userAnswer;

	// output problem
	printf("%d - %d = ? ", randomNumber1, randomNumber2);
	// 2. get input
	scanf("%d", &userAnswer);

	// http://www.cplusplus.com/reference/cstdlib/itoa/?kw=itoa
	// itoa((randomNumber1 - randomNumber2), correctAnswer, 10);
	sprintf(correctAnswer, "%d", randomNumber1 - randomNumber2);

	// C has the shorthand (ternary) if operator
	// http://www.cplusplus.com/forum/articles/14631/
	return ((randomNumber1 - randomNumber2) == userAnswer ) ? 1 : 0;
}

/**
    Print the multiplication problem

	@param correctAnswer is returned by reference
    @param randomNumber1, randomNumber2
    @return boolean
*/
int multiplicationProblem(char *correctAnswer, int randomNumber1, int randomNumber2)
{
	// temp variables to get input from user
	int userAnswer;

	// output problem
	printf("%d * %d = ? ", randomNumber1, randomNumber2);
	// 2. get input
	scanf("%d", &userAnswer);

	// http://www.cplusplus.com/reference/cstdlib/itoa/?kw=itoa
	// itoa((randomNumber1 * randomNumber2), correctAnswer, 10);
	sprintf(correctAnswer, "%d", randomNumber1 * randomNumber2);

	// C has the shorthand (ternary) if operator
	// http://www.cplusplus.com/forum/articles/14631/
	return ((randomNumber1 * randomNumber2) == userAnswer ) ? 1 : 0;
}

/**
    Print the division problem

	@param correctAnswer is returned by reference
    @param randomNumber1, randomNumber2
    @return boolean
*/
int divisionProblem(char *correctAnswer, int randomNumber1, int randomNumber2)
{
	// temp variables to get input from user
	int userAnswer;
	int userAnswerRemainder;
	char userAnswerString[10];
	int tempRandomNumber;

	// verify that the answer will not be less than 1
	if (randomNumber1 < randomNumber2)
	{
		// tempRandomNumber holds a copy of randomNumber2 so we don't lose it
		tempRandomNumber = randomNumber2;
		randomNumber2 = randomNumber1;
		randomNumber1 = tempRandomNumber;
	}

	// can't divid by zero
	// zero will happen just as randomly as 1 now
	randomNumber2 = (randomNumber2 == 0) ? randomNumber2 +1 : randomNumber2;

	// output problem
	printf("%d / %d = ? ", randomNumber1, randomNumber2);
	// 2. get input
	scanf("%d", &userAnswer);
	// output problem
	printf("%s", "Enter any remainder: ");
	// 2. get input
	scanf("%d", &userAnswerRemainder);

	// itoa is not necessary, use sprintf below
	// http://www.cplusplus.com/reference/cstdlib/itoa/?kw=itoa
	// itoa((randomNumber1 * randomNumber2), correctAnswer, 10);
	// strcat(correctAnswer, " r ");
	// itoa((randomNumber1 * randomNumber2), tempRemainderString, 10);
	// strcat(correctAnswer, tempRemainderString);

	// http://www.cplusplus.com/reference/cstdio/sprintf/
	// found out about the sprintf function which works like printf but saves to a string
	// end strings with \0 (null) so we can use strcmp to compare in return
	sprintf (correctAnswer, "%d r %d\0", randomNumber1 / randomNumber2, randomNumber1 % randomNumber2);
	sprintf(userAnswerString, "%d r %d\0", userAnswer, userAnswerRemainder);


	// debug
	// printf("correct: %s user: %s", correctAnswer, userAnswerString);

	// int i;
	// for (i =0; i<10; i++)
	// {
	// 	printf(" correctAnswer i: %c\n", correctAnswer[i]);
	// }
	// for (i =0; i<10; i++)
	// {
	// 	printf("userAnswerString i: %c\n", userAnswerString[i]);
	// }

	// C has the shorthand (ternary) if operator
	// http://www.cplusplus.com/forum/articles/14631/
	// strcmp performs binary comparison and return 0 when strings are the same
	// http://www.cplusplus.com/reference/cstring/strcmp/
	return (strcmp(correctAnswer, userAnswerString) == 0) ? 1 : 0;
}
