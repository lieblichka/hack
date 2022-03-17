#include <stdio.h>

int main()
{

	int		i;

	char	char_array[5] = {'a', 'b', 'c', 'd', 'e'};
	int		int_array[5] = {1, 2, 3, 4, 5};

	unsigned long int hacky_nonpointer;

	hacky_nonpointer = (unsigned long int) char_array;
	for (i=0; i < 5; i++) // Обход массива char
	{
		printf("[hacky_nonpointer]\tpoints to %p, \
which contains the char %c\n", hacky_nonpointer,
		*((char*)hacky_nonpointer));
		hacky_nonpointer = hacky_nonpointer + sizeof(char);
	}

	hacky_nonpointer = (unsigned long int) int_array;
	for (i=0; i < 5; i++) // Обойти массива int
	{
		printf("[hacky nonpointer]\tpoints to %p, \
which contains the integer %d\n", hacky_nonpointer,
		*((int*)hacky_nonpointer));
		hacky_nonpointer = hacky_nonpointer + sizeof(int);
	}
}
