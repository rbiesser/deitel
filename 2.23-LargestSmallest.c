/**
	Largest Smallest
	2.23-largest_smallest.c 
	Purpose: Determine and print the largest and the smallest integers in the group
	
	@author Robbie Biesser
	@version 1.0 1/23/2019
	@source Deitel. (2015). C How to Program, 8th Edition.

*/

// include the C library to perform Input/Output operations
// http://www.cplusplus.com/reference/cstdio/
#include <stdio.h>

// main starts program execution
int main(void)
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


}