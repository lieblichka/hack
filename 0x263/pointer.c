#include <stdio.h>
#include <string.h>

int main()
{
	char	str_a[20];	// Массив из 20 символов 
	char	*pointer;	// Указатель массива символов 
	char	*pointer2;	// Другой указатель

	strcpy(str_a, "Hello World!\n");
	pointer = str_a;	// Установим первый указатель на начало массива
	printf(pointer); 

	pointer2 = pointer + 2; // Установим второй указатель на 2 байта дальше
	printf(pointer2); 		// Вывод 
	strcpy(pointer2, "y you guys!\n");	// Копируем в то же место
	printf(pointer);					// Еще один вывод
}
