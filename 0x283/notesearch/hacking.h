#include <stdlib.h>

// Функция вывода сообщения об ошибке и завершения работы программы
void fatal(char *message)
{
	char error_message[100];

	strcpy(error_message, "[!!] Fatal Error ");
	strncat(error_message, message, 83);
	perror(error_message);
	exit(-1); 
}

// Оболочка для malloc() с проверкой ошибок
void *ec_malloc(unsigned int size)
{
	void *ptr;
	
	ptr = malloc(size);
	if (ptr == NULL)
		fatal("in ec_malloc() on memory allocation");
	return ptr;
}
