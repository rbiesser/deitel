#include <stdio.h>

int main(void)
{
	int r;

	puts("Calculate the diameter, circumference, and area of a circle given its r");
	printf("%s", "Enter the circle radius: ");

	scanf("%d", &r);

	printf("\nThe diameter is %d\n", 2 * r);
	printf("The circumference is %f\n", 2 * 3.14159 * r);
	printf("The area is %f\n", 3.14159 * r * r);
}
