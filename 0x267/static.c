#include <stdio.h>

void function()
{
	int			var = 5; // Пример функции с собственным контекстом
	static int	static_var = 5; // Инициализация статической переменной

	printf("\t[in function] var = %d\n", var);
	printf("\t[in function] static_var = %d\n", static_var);
	var++; // Прибавить 1 к var 
	static_var++; // Прибавить 1 к static_var 
}

int main()
{
	int i;
	static int static_var = 1337; // Другая статическая переменная 
								  // в другом контексте
	for (i = 0; i < 5; i++) // Повторить 5 раз
	{
		printf("[in main] static_var = %d\n", static_var);
		function(); // Вызвать функцию 
	}
}
