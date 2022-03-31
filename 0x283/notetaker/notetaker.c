#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include "hacking.h"

void usage(char *prog_name, char *filename)
{
	printf("Usage: %s <data to add to %s\n>", prog_name, filename);
	exit(0);
}

void fatal(char *); // Функция обработки критических ошибок
void *ec_malloc(unsigned int); // Оболочка для malloc() с проверкой ошибок

// Предыдущие две строки прототипов можно не описывать, так hacking.h
// объявлен выше main, а значит эти функции ему известны

int main(int argc, char *argv[])
{
	int userid, fd; // File deskriptor
	char *buffer, *datafile;

	buffer = (char *)ec_malloc(100);
	datafile = (char *)ec_malloc(20);
	strcpy(datafile, "/var/notes");

	if (argc < 2)					// Если аргументов командной строки нет
		usage(argv[0], datafile);	// Вывести сообщение о правилах вызова
									// и завершить работу

	strcpy(buffer, argv[1]);		// Копирать в buffer
	
	printf("[DEBUG] buffer	 @ %p: \'%s\'\n", buffer, buffer);
	printf("[DEBUG] datafile @ %p: \'%s\'\n", datafile, datafile);


	// Открытие файла 
	fd = open(datafile, O_WRONLY|O_CREAT|O_APPEND, S_IRUSR|S_IWUSR);
	if (fd == -1)
		fatal("in main() while opening file");
	printf("[DEBUG] file deskriptor is %d\n", fd);

	userid = getuid(); // Получить фактический ID пользователя

	// Запись данных
	if (write(fd, &userid, 4) == -1) // Записать ID пользователя перед данными
		fatal("in main() while writing userid to file");
	write(fd, "\n", 1); // Добавить перевод строки
	
	if (write(fd, buffer, strlen(buffer)) == -1) // Записать заметку
		fatal("in main() while writing buffer to file");
	write(fd, "\n", 1); // Добавить перевод строки

	// Закрытие файла
	if (close(fd) == -1)
		fatal("in main() while closing file");
	printf("Note has been saved.\n");
	free(buffer);
	free(datafile);
}
