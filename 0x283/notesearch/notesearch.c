#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "hacking.h"
#include <unistd.h>

#define	FILENAME "/var/notes"

int		print_notes(int, int, char *); // Функия для вывода заметок
int		find_user_note(int, int);	   // Поиск заметки пользователя
									   // в файле

int		search_note(char *, char *);   // Функция поиска ключевого слова
void	fatal(char *);				   // Обработчик критических ошибок

int		main(int argc, char *argv[])   
{
	int		userid, printing = 1, fd;	   // Дескриптор файла
	char	searchstring[100];

	if (argc > 1)						   // Если есть аргумент
		strcpy(searchstring, argv[1]);	   // 	эта строка для поиска 
	else								   // В противном случае 
		searchstring[0] = 0;			   // строка для поиска пуста

	userid = getuid();
	fd = open(FILENAME, O_RDONLY);		   // Открыть файл только для чтения
	if (fd == -1)
		fatal("in main() while opening file for reading");
	
	while (printing)
		printing = print_notes(fd, userid, searchstring);
	printf("-------[ end of note data ]-------\n");
	close(fd);
}

// Функция для вывода заметок с заданным ID пользователя
// соответствующих строке поиска, если она задана
// возвращает 0, если достигнут конец файла, и 1, если есть другие заметки
int print_notes(int fd, int uid, char *searchstring)
{
	int note_length;
	char byte = 0, note_buffer[100];

	note_length = find_user_note(fd, uid);
	if (note_length == -1)				  // Если достигнут конец файла
		return 0;						  // вернуть 0

	read(fd, note_buffer, note_length);   // Прочитать данные заметки
	note_buffer[note_length] = 0;		  // Символ конца строки

	if (search_note(note_buffer, searchstring)) // Если строка найдена
		printf(note_buffer);					// Вывести заметку
	return 1;
}

// Функция для поиска следующей заметки с заданным ID пользователя 
// возвращает -1, если достигнут конец файла 
// в противном случае возвращает длину недавней заметки 
int	find_user_note(int fd, int user_uid)
{
	int note_uid = -1;
	unsigned char byte;
	int length; 

	while (note_uid != user_uid)
	{

		if (read(fd, &note_uid, 4) != 4)
			return -1;
		if (read(fd, &byte, 1) != 1)
			return -1;

		byte = length = 0;
		while (byte != '\n')				// Узнать, сколько байт осталось
		{									// до конца строки 

			if (read(fd, &byte, 1) != 1)	// Прочитать один байт
				return -1;					// Если не удалось прочитать байт
											// вернуть код конца файла
			length++;
		}
	}
	lseek(fd, length * -1, SEEK_CUR);		// Переместить текущую позицию
											// чтения назад на length байт

	printf("[DEBUG] found a %d byte note for user id %d\n", length, note_uid);
	return length;

}

// Функция для поиска заметки по данному ключевому слову
// возвращает 1, если заметка найдена, и 0, если найдена
int		search_note(char *note, char *keyword)
{
	int i, keyword_length, match = 0;

	keyword_length = strlen(keyword);
	if (keyword_length == 0)			// Если строка поиска не задана
		return 1;						// всегда "совпадение"

	for (i = 0; i < strlen(note); i++)	// Цисл по всем байтам заметки
	{
		if (note[i] == keyword[match])	// Если совпадает с байтом
										// ключевого слова
			match++;	// Приготовиться к проверке следующего байта
		else			// в противном случае 
		{
			if (note[i] == keyword[0]) // если байт совпадает с первым байтом
									   // ключевого слова 
				match = 1; // в счетчик повторений записывается 1
			else
				match = 0; // В противном случае - 0
		}
		if (match == keyword_length) // Если найдено полное совпадение
			return 1; 	// вернуть код совпадения
	}
	return 0; // Вернуть код несовпадения 
}













