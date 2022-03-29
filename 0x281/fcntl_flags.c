#include <stdio.h>
#include <fcntl.h>

void display_flags(char *, unsigned int);
void binary_print(unsigned int);

int main(int argc, char *argv)
{
	display_flags("O_RDONLY\t\t", O_RDONLY);	
	display_flags("O_WRONLY\t\t", O_WRONLY);	
	display_flags("O_RDWR\t\t\t", O_RDWR);
	printf("\n");
	display_flags("O_APPEND\t\t", O_APPEND);	
	display_flags("O_TRUNC\t\t\t", O_TRUNC);	
	display_flags("O_CREAT\t\t\t", O_CREAT);	
	printf("\n");
	display_flags("O_WRONLY|O_APPEND|O_CREAT", O_WRONLY|O_APPEND|O_CREAT);

}

void display_flags(char *label, unsigned int value)
{
	printf("%s\t: %d\t:", label, value);
	binary_print(value);
	printf("\n");
}

void binary_print(unsigned int value)
{
	unsigned int mask = 0xff000000; 	  // Маска для старшего байта
	unsigned int shift = 256 * 256 * 256; // Смещение для страшего байта 
	unsigned int byte, byte_iterator, bit_iterator;

	for (byte_iterator=0; byte_iterator < 4; byte_iterator++)
	{
		byte = (value & mask) / shift; // Выделить каждый бит
		printf(" ");
		for (bit_iterator=0; bit_iterator < 8; bit_iterator++) // Выести
		{													   // биты байта
			if (byte & 0x80) // Если страший бит в байте не 0
				printf("1"); // Вывести 1
			else
				printf("0"); // Иначе вывести 0
			byte *= 2;		 // Сдвинуть все биты влево 1
		}
	//	printf(" mask --> %0x and shift --> %0x\n", mask, shift);
		mask /= 256;		 // Переместить биты маски вправо на 8
		shift /= 256;		 // Переместить биты смещения вправо на 8
	}
	

}
