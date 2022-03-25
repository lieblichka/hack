#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *errorchecked_malloc(unsigned int); // Прототип функции
										 // errorchecked_malloc()

int main(int argc, char *argv[])
{
	char *char_ptr; // Указатель на символьный тип
	int	*int_ptr;	// Указатель на целый тип
	int mem_size;

	if (argc < 2)		// Если нет аргументов командной строки
		mem_size = 50;	// используется 50 - значение по умолчанию
	else
		mem_size = atoi(argv[1]);
	
	printf("\t[+] allocating %d bytes of memory on the heap for char_ptr\n",
		mem_size);
	char_ptr = (char *) errorchecked_malloc(mem_size); // Выделение памяти
													   // в куче
	
	strcpy(char_ptr, "This is memory is located on the heap. ");
	printf("char_ptr (%p) --> '%s'\n", char_ptr, char_ptr);
	printf("\t[+] allocating 12 bytes of memory on the heap for int_ptr\n");
	int_ptr = (int *) errorchecked_malloc(12); // Еще раз выделяем память
											   // в куче
	
	*int_ptr = 31337; // Поместить 31337 по адресу, содержащемуся в int_ptr
	printf("int_ptr (%p) --> %d\n", int_ptr, *int_ptr);

	printf("\t[-] freeing char_ptr's heap memory...\n");
	free(char_ptr); // Освободить память в куче

	printf("\t[+] allocating another 15 bytes for char_ptr\n");
	char_ptr = (char *) errorchecked_malloc(15); // Еще раз выделяем память
												 // в куче
	
	strcpy(char_ptr, "new memory");
	printf("char_ptr (%p) --> '%s'\n", char_ptr, char_ptr);

	printf("\t[-] freeing int_ptr's heap_memory...\n");
	free(int_ptr); // Освободить память в куче 
	printf("\t[-] freeing char_ptr's heap_memory...\n");
	free(char_ptr); // Освободить еще один блок памяти в куче 
}

void *errorchecked_malloc(unsigned int size) // Функция malloc() 
											 // с контролем ошибок
{
	void *ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: could not allocate heap memory.\n");
		exit(-1);
	}
	return ptr;
}










