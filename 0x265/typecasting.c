#include <stdio.h>

int main()
{
	int a, b;
	float c, d;

	a = 13;
	b = 5;

	c = a / b;					// Деление целых чисел
	d = (float) a / (float) b;  // Деление целых чисел
								// привиденных к типу float.

	printf("[integers]\t a = %d\t b = %d\n", a, b);
	printf("[floats]\t c = %f\t d = %f\n", c, d);
}
