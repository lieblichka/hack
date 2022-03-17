#include <stdio.h>

void function() // Пример функции с собственным контекстом
{
	int			var = 5; // Пример функции с собственным контекстом
	static int	static_var = 5; // Инициализация статической переменной

	printf("\t[in function] var @ %p = %d\n", &var, var);
	printf("\t[in function] static_var @ %p = %d\n", &static_var, static_var);
	var++; // Прибавить 1 к var 
	static_var++; // Прибавить 1 к static_var 
}

int main()
{
	int i;
	static int static_var = 1337; // Другая статическая переменная 
								  // в другом контексте
	for (i = 0; i < 5; i++) // loop 5 times 
	{
		printf("[in main] static_var @ %p = %d\n", &static_var, static_var);
		function(); // Вызвать функцию 
	}
}
