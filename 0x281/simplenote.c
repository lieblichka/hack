#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>		// for file flags
#include <sys/stat.h>
#include <unistd.h>		// for function write

void usage(char *prog_name, char *filename)
{
	printf("Usage: %s <data to add to %s\n>", prog_name, filename);
	exit(0);
}

void fatal(char *); 				// Функция обработки критических ошибок
void *ec_malloc(unsigned int);	// Оболочка для malloc() с проверкой ошибок

int main(int argc, char *argv[])
{
	int fd;	// file deskriptor
	char *buffer, *datafile;

	buffer = (char *) ec_malloc(100);
	datafile = (char *) ec_malloc(20);
	strcpy(datafile, "/tmp/notes");

	if (argc < 2)				  // Если нет аргументов командной строки нет
		usage(argv[0], datafile); // вывести сообщение о правилах вызова
								  // и завершить работу
	
	strcpy(buffer, argv[1]);	  // Копировать в буфер

	printf("[DEBUG] buffer  @ %p:\'%s\'\n", buffer, buffer);
	printf("[DEBUG] datafile  @ %p:\'%s\'\n", datafile, datafile);

	// На данную функцию при текущей конструкции компилятор будет ругаться
	// так как, для такой конструции предпочтительнее будет использовать
	// strcat из за того, что строка состоит из одного символа "\n" и к тому
	// же она не инициализирована, поэтому такое использование подозрительно 

	//strncat(buffer, "\n", 1); 	  // Добавить в конце перевод строки
	strcat(buffer, "\n");			  // Добавить в конце перевод строки
	
 // Открытие файла
	fd = open(datafile, O_WRONLY|O_CREAT|O_APPEND, S_IRUSR|S_IWUSR);
	if (fd == -1)
		fatal("in main() while opening file");
	printf("[DEBUG] file deskriptor is %d\n", fd);
	
 // Запись данных
	if (write(fd, buffer, strlen(buffer)) == -1)
		fatal("in main() while writing buffer to file");
	
 // Закрытие файла
 	if (close(fd) == -1)
		fatal("in main() while closing file");
	
	printf("Note has been saved.\n");
	free(buffer);
	free(datafile);
}

// Функция вывода сообщения об ошибке и завершение работы программы
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
