#include <stdio.h>
#include <stdlib.h>

void	usage(char *program_name)
{
	printf("Usage: %s <message> <# of times to repeat>\n", program_name);
	exit(1);
}

void	check_seg(const char *str)
{
	printf("argv[2] = %p\n", str);
	if (!str)
	{
		printf("if continue *argv[2] will be segfault\n");
		exit(1);
	}
}

int		main(int argc, char *argv[])
{
	int i, count;

	check_seg(argv[2]);
	//if (argc < 3) // Если аргументов меньше 3, вывести сообщение 
	//	usage(argv[0]); // о том, как вызывать программу, и завершить работу
	
	count = atoi(argv[2]); // Преобразовать 2-й аргумент в целое число
	printf("Repeating %d times..\n", count);

	for (i=0; i < count; i++)
		printf("%3d - %s\n", i, argv[1]); // Вывести 1-й аргумент
}
