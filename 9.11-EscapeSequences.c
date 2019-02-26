/**
	Escape Sequences
	9.11-escapesequences.c 
	Purpose: Test the escape sequences of the C language

	9.11	(Escape Sequences) Write a program to test the escape 
	sequences \', \", \?, \\, \a, \b, \n, \r and \t. For the escape sequences that 
	move the cursor, print a character before and after printing the escape sequence 
	so it’s clear where the cursor has moved.

	see Fig. 9.16
	
	@author Robbie Biesser
	@version 1.0 2/19/2019
	@source Deitel. (2015). C How to Program, 8th Edition.

*/

#include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
// #include <string.h> // necessary for string functions

int main()
{
	printf("The single quote : \'\n"); // single quote
	printf("The double qutoe : \"\n"); // double quote
	printf("The question mark: \?\n"); // question mark
	printf("The backslash    : \\\n"); // backslash
	printf("The bell. \a\n"); // audible bell

	// if you need more than one bell, you need a pause in between
	int i;
	for (i=0; i<2; i++)
	{
		printf("\a"); // note only 2 bells play because the first was not finished yet.
		sleep(1); // pause 
	}

	printf("\nMove cursor back one position on current line. *\b*\n"); // back one position -- overwrites previous
	printf("Move cursor to the beginning of next line. *\n*newline\n"); // newline
	printf("Move cursor to the beginning of current line. *put star at beginning\r*\n"); // beginning
	printf("Move cursor to the next horizontal tab position *tab\t*\n"); // horizontal tab

	// these must
	printf("\nMove cursor to the next vertical tab position *vertical tab\v*\n"); // vertical tab
	printf("Move cursor to the next logical page *next page\f*"); // new page or form feed

}