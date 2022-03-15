#include <stdio.h>
#include <string.h>

int main()
{
	char	message[13];
	int		count, i;

	strcpy(message, "Hello World!");

	printf("Repeat how many times? ");
	scanf("%d", &count); 
	// функция ввода данных, вторым аргументом принимает адрес 
	// поэтому передается адрес переменной count  (&count) 

	for (i = 0; i < count; i++)
		printf("%3d - %s\n", i, message);
}
