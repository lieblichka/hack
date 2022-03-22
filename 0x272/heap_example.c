#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char	*char_ptr; // Указатель на символьный тип
	int		*int_ptr; // Указатель на целйы тип
	int		mem_size;

	if (argc < 2) // Если нет аргументов командной строки
				  // используеся 50 значение по умолчанию
		mem_size = 50; 
	else
		mem_size = atoi(argv[1]);

	printf("\t[+] allocating %d bytes of memory on the heap for char_ptr\n",
		mem_size);
	char_ptr = (char *) malloc(mem_size); // Выделение памяти в куче

	if (char_ptr == NULL) // Проверка ошибки - сбоя malloc()
	{
		fprintf(stderr, "Error: could not allocate heap memory.\n");
		exit(-1);
	}

	strcpy(char_ptr, "This memory is located on the heap.");
	printf("char_ptr (%p) --> '%s'\n", char_ptr, char_ptr);

	printf("\t[+] allocating 12 bytes of memory on the heap for int_ptr\n");
	int_ptr = (int *) malloc(12); // Еще раз выделяем память в куче

	if (int_ptr == NULL) // Проверка ошибки - сбоя malloc() fails
	{
		fprintf(stderr, "Error: could not allocate heap memory.\n");
		exit(-1);
	}
	
	*int_ptr = 31337; // Поместить 31337 по адресу, содержащемуся в int_ptr.
	printf("int_ptr (%p) --> %d\n", int_ptr, *int_ptr);

	printf("\t[-] freeing char_ptr's heap memory... \n");
	free(char_ptr); // Освободить память в куче 

	printf("\t[+] allocating another 15 bytes for char_ptr\n");
	char_ptr = (char*) malloc(15); // Еще раз выделяем память в куче

	if (char_ptr == NULL) // Проверка ошибки - сбоя malloc()
	{
		fprintf(stderr, "Error, could not allocate heap memory.\n");
		exit(-1);
	}

	strcpy(char_ptr, "new memory");
	printf("char_ptr (%p) -->  '%s' \n", char_ptr, char_ptr);

	printf("\t[-] freeing int_ptr's heap memory... \n");
	free(int_ptr); // Освободить память в куче 
	printf("\t[-] freeing char_ptr's heap memory... \n");
	free(char_ptr); // Освободить еще один блок памяти в куче

}
