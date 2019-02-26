/**
	Tempuratures
	9.10-temperatures.c 
	Purpose: Convert temperatures from Fahrenheit to Celsius

	9.10	(Temperature Conversions) Write a program that converts integer Fahrenheit 
	temperatures from 0 to 212 degrees to floating-point Celsius temperatures with 3 
	digits of precision. Perform the calculation using the formula

	celsius = 5.0 / 9.0* (fahrenheit - 32);

	The output should be printed in two right-justified columns of 10 characters each, 
	and the Celsius temperatures should be preceded by a sign for both positive and 
	negative values.
	
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
	// start and end in degrees Fahrenheit
	int startingTempF = 0;
	int endingTempF = 212;

	// used in the conversion calculation
	float fahrenheit;
	float celsius;

	// print header
	printf("%10s %10s\n", "Fahrenheit", "Celsius");

	// print celsius calculations on each line
	for(fahrenheit = startingTempF; fahrenheit <= endingTempF; fahrenheit++)
	{
		celsius = 5.0 / 9.0* (fahrenheit - 32);

		// celsius printed with 3 digits of precision
		// right justified 10 spaces
		// precede with sign for positive negative
		printf("%10.0f %10.3f\n", fahrenheit, celsius);
	}
}