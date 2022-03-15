#include <stdio.h>

int main()
{
	int	int_var = 5;
	int	*int_ptr;
	int *int_p;

	int_ptr = &int_var; // Записать адрес int_var в int_ptr
	
	printf("int_ptr = 0x%08x\n", int_ptr);
	// демонстрация отступа в размере 4 байт, так как переменная типа int
	printf("&int_ptr = 0x%08x\n", &int_ptr);
	printf("&int_p = 0x%08x\n", &int_p); 
	// демонстрация отступа количества байт, что указывает на размер
	// указателя в размере 8 байт
	printf("*int_ptr = 0x%08x\n\n", *int_ptr);
	printf("int_var is located at 0x%08x and contains %d\n", &int_var,
		int_var);
	printf("int_ptr is located at 0x%08x, contains 0x%08x, \
and points to %d\n\n", &int_ptr, int_ptr, *int_ptr);
}
