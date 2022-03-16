#include <stdio.h>

int main()
{

	int		i;

	char	char_array[5] = {'a', 'b', 'c', 'd', 'e'};
	int		int_array[5] = {1, 2, 3, 4, 5};

	char	*char_pointer;
	int		*int_pointer;

	char_pointer = (char *) int_array; // Привидение к типу 
	int_pointer = (int *) char_array; // данных указателя

	for (i=0; i < 5; i++) // Обойти массив символов с помощью int_pointer
	{
		printf("[integer pointer]\tpoints to %p, \
which contains the integer %c\n", int_pointer, *int_pointer);
		int_pointer = (int*)((char*)int_pointer + 1);
	}

	for (i=0; i < 5; i++) // Обойти массив символов с помощью char_pointer
	{
		printf("[char pointer]\t\tpoints to %p, \
which contains the char %d\n", char_pointer, *char_pointer);
		char_pointer = (char*)((int*)char_pointer + 1);
	}
}