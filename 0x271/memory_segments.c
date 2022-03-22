#include <stdio.h>
#include <stdlib.h>

int global_var; // объявлние глобальной переменной
int global_initialized_var = 5; // объявление и инициализация глоб. перменной

void function() // Это демонстрационная функция 
{
	int stack_var; // Переменная с таким же именем есть в main().
	
	printf("the function's stack_var is at address 0x%08x\n", &stack_var);
}

int main()
{
	int			stack_var; // Переменная с таким же именем есть в function()
	static int	static_initialized_var = 5;
	static int	static_var;
	int			*heap_var_ptr;

	heap_var_ptr = (int*) malloc(4);

	// Эти переменные находятся в сегменте DATA
	printf("global_initialized_var is at address 0x%08x\n",
			&global_initialized_var);
	printf("static_initialized_var is at address 0x%08x\n\n",
			&static_initialized_var);

	// Эти переменные находятся в сегменте BSS
	printf("static_var is at address 0x%08x\n", &static_var);
	printf("global_var is at address 0x%08x\n\n", &global_var);
	
	// Эта переменная находится в сегменте HEAP 
	printf("heap_var is at address 0x%08x\n\n", heap_var_ptr);

	// Эти переменные находятся в сегменте STACK
	printf("stack_var is at address 0x%08x\n", &stack_var);
	function(); 
	
}
