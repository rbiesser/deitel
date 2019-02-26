/**
	Pay Calculator
	4.28-pay_calculator.c

	Purpose: Calculate the weekly pay for 4 different employee types.

	4.28	(Calculating Weekly Pay)A company pays its employees as
	managers (who receive a fixed weekly salary), hourly workers (who
	receive a fixed hourly wage for up to the first 40 hours they work
	and time-and-a-half (i.e., 1.5 times their hourly wage) for overtime 
	hours worked), commission workers (who receive $250 plus 5.7% of
	their gross weekly sales), or pieceworkers (who receive a fixed
	amount of money for each of the items they produce (each pieceworker
	in this company works on only one type of item). Write a program to
	compute the weekly pay for each employee. You do not know the number
	of employees in advance. Each type of employee has its own pay code:
	Managers have paycode 1, hourly workers have code 2, commission workers
	have code 3 and pieceworkers have code 4. Use a switch to compute
	each employee�s pay based on that employee�s paycode. Within the
	switch, prompt the user (i.e., the payroll clerk) to enter the
	appropriate facts your program needs to calculate each employee�s
	pay based on that employee�s paycode. [Note: You can input values
	of type double using the conversion specifier %lf with scanf.]

	@author Robbie Biesser
	@version 1.0 1/31/2019
	@source Deitel. (2015). C How to Program, 8th Edition.

*/

// include the C library to perform Input/Output operations
// http://www.cplusplus.com/reference/cstdio/
#include <stdio.h> // for input/output
// #include <stdlib.h> // for rand() and srand()
// #include <time.h> // for time()

/**
	main starts program execution
*/
int main()
{
	/**
	 * menu
	 */
	int payCode;

	/**
	 * Used by all employees
	 * variables can not be declared within the switch
	 */
	double pay; // temp variable used for each employee
	double totalPay = 0;

	/**
	 * Counts
	 * Running total for the number of employees
	 */
	int countManagers = 0;
	int countHourlyWorkers = 0;
	int countCommissionWorkers = 0;
	int countPieceworkers = 0;

	/**
	 * Hourly worker
	 * decimal values can be accepted
	 */
	const int WEEKS_PER_YEAR = 52;
	double salary;

	/**
	 * Hourly worker
	 * decimal values can be accepted
	 */
	const int HOURS_PER_WEEK_THRESHOLD = 40; // considered overtime if greater than this value
	const double OVERTIME_MULTIPLIER = 1.5; // time-and-a-half
	double hourlyRate;
	double hoursWorked;
	double overtimeHours;

	/**
	 * Commission worker
	 * decimal values can be accepted
	 */
	const double COMMISSION_BASE = 250;
	const double COMMISSION_MULTIPLIER = .057; // 5.7%
	double grossWeeklySales;

	/**
	 * Pieceworker
	 * decimal values can be accepted
	 */
	double numberPieces;
	double wagePerPiece;


	do
	{
		// print menu
		puts("");
		puts("Select type of Employee from menu");
		puts("1. Manager/Salary");
		puts("2. Hourly Worker");
		puts("3. Commission Worker");
		puts("4. Pieceworker");
		printf("%s", "Enter paycode (-1 to end): ");

		// user chooses type of employee
		scanf("%d", &payCode);

		// switch will decide which type the user chose
		switch (payCode)
		{
			// manager
			case 1:
				// reset variables
				pay = salary = 0;

				// prompt the user for necessary values
				puts("");
				puts("Manager selected.");
				printf("%s", "Enter the yearly salary: $");
				scanf("%lf", &salary);

				pay = salary / WEEKS_PER_YEAR;

				// output
				printf("Manager's weekly pay is $%.2lf", pay);

				countManagers++; // update count
				totalPay += pay; // increase running total for all inputs

				break;

			// hourly
			case 2:
				// reset variables
				pay = hourlyRate = hoursWorked = overtimeHours = 0;

				// prompt the user for necessary values
				puts("");
				puts("Hourly worker selected.");
				printf("%s", "Enter the hourly rate: $");
				scanf("%lf", &hourlyRate);
				printf("%s", "Enter the total hours worked: ");
				scanf("%lf", &hoursWorked);

				// if the employee worked more than the HOURS_PER_WEEK_THRESHOLD
				// we need to do some calculations to figure out how much overtime to pay
				if (hoursWorked > HOURS_PER_WEEK_THRESHOLD)
				{
					overtimeHours = hoursWorked - HOURS_PER_WEEK_THRESHOLD; // anything over the threshold
					hoursWorked = HOURS_PER_WEEK_THRESHOLD; // we know they are at least at the threshold
				}

				// the pay can be calculated with this one line
				pay = (hourlyRate * hoursWorked) + (hourlyRate * overtimeHours * OVERTIME_MULTIPLIER);

				// output
				printf("Worker's pay this week is $%.2lf", pay);

				countHourlyWorkers++; // update count
				totalPay += pay; // increase running total for all inputs

				break;

			// commission
			case 3:
				// reset variables
				pay = grossWeeklySales = 0;

				// prompt the user for necessary values
				puts("");
				puts("Commission worker selected.");
				printf("%s", "Enter the gross weekly sales: $");
				scanf("%lf", &grossWeeklySales);

				// the pay can be calculated with this one line
				pay = COMMISSION_BASE + (grossWeeklySales * COMMISSION_MULTIPLIER);

				// output
				printf("Worker's pay this week is $%.2lf", pay);

				countCommissionWorkers++; // update count
				totalPay += pay; // increase running total for all inputs

				break;

			// piecework
			case 4:
				// reset variables
				pay = numberPieces = wagePerPiece = 0;

				// prompt the user for necessary values
				puts("");
				puts("Pieceworker selected.");
				printf("%s", "Enter the number of pieces: ");
				scanf("%lf", &numberPieces);
				printf("%s", "Enter the wage per piece: $");
				scanf("%lf", &wagePerPiece);

				// the pay can be calculated with this one line
				pay = numberPieces * wagePerPiece;

				// output
				printf("Worker's pay this week is $%.2lf", pay);

				countPieceworkers++; // update count
				totalPay += pay; // increase running total for all inputs

				break;

			// exit the menu
			case -1:
				break;

			// input not recognized
			default:
				puts("Invalid pay code.");
				break;
		}
	}
	// loop until user chooses to end
	while(payCode != -1);

	/**
	 * Output Totals
	 * these are the variables we have been tracking through the whole program
	 */
	puts("");
	printf("Number of Employees:\t\t\t\t%d\n",
			countManagers
			+ countHourlyWorkers
			+ countCommissionWorkers
			+ countPieceworkers
		);
	printf("Total number of managers paid:\t\t\t%d\n", countManagers);
	printf("Total number of hourly workers paid:\t\t%d\n", countHourlyWorkers);
	printf("Total number of commission workers paid:\t%d\n", countCommissionWorkers);
	printf("Total number of pieceworkers paid:\t\t%d\n", countPieceworkers);
	printf("Total value paid:\t\t\t$%.2lf\n", totalPay);
}
