/**
	Diameter, Circumference and Area of a Circle
	2.20-circle.c 
	Purpose: Calculate the diameter, circumference, and area of a circle given its radius
	
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
	const double PI = 3.14159;
	int radius;

	// output instructions
	puts("Calculate the diameter, circumference, and area of a circle given its radius");
	printf("%s", "Enter the circle radius: ");
	
	scanf("%d", &radius); // input the radius

	// output calculations
	printf("\nThe diameter is %d\n", 2 * radius); // diameter
	printf("The circumference is %f\n", 2 * PI * radius); // circumference
	printf("The area is %f\n", PI * radius * radius); // area
}