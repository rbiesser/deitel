/**
	Body Mass Index Calculator
	2.32-BMI_Calculator
	Purpose: Calculates the body mass index for a given height and weight.
	
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
	double heightInInches;
	double weightInPounds;
	double bmi;
	
	// output instructions
	puts("Calculate the body mass index for a given height and weight.");
	printf("Please enter your height (in inches): ");
	
	// use "%lf" to read in double
	// http://www.cplusplus.com/reference/cstdio/scanf/
	scanf("%lf", &heightInInches); // input the radius

	printf("Please enter your weight (in pounds): ");
	
	scanf("%lf", &weightInPounds); // input the radius

	// calculate BMI
	bmi = (weightInPounds * 703) / (heightInInches * heightInInches);

	// output
	printf("Your BMI is %f\n", bmi); // largest
	
	puts("\nBMI VALUES");
	puts("Underweight: less than 18.5");
	puts("Normal:      between 18.5 and 24.9");
	puts("Overweight:  between 25 and 29.9");
	puts("Obese:       30 or greater");


}