#include <stdio.h>
#include <time.h>

void dump_time_struct_bytes(struct tm *time_ptr, int size)
{
	int i;
	unsigned char *raw_ptr;

	printf("bytes if struct located at 0x%08x\n", time_ptr);
	raw_ptr = (unsigned char *) time_ptr;
	for (i = 0; i < size; i++)
	{
		printf("%02x ", raw_ptr[i]);
		if (i%16 == 15) // Начинать новую строку через каждые 16 байт.
			printf("\n");
	}
	printf("\n");
}

int main()
{
	long int	seconds_since_epoch;
	struct		tm current_time, *time_ptr;
	int			hour, minute, second, i, *int_ptr;

	seconds_since_epoch = time(0); // Передать функции time в качестве
								   // аргумента нулевой указатель
	printf("time() - seconds since epoch: %ld\n", seconds_since_epoch);
	time_ptr = &current_time; // Поместить в time_ptr адрес
							  // структуры current_time
	
	localtime_r(&seconds_since_epoch, time_ptr); // Заполнить структуру 

	// Три способа доступа к элементам структуры:

	hour = current_time.tm_hour;	// Прямой доступ
	minute = time_ptr->tm_min;		// Доступ по указателю
	//minute = *((int *) time_ptr + 1);	
	second = *((int *) time_ptr);	// Хакерский доступ по указателю

	printf("Current time is: %02d:%02d:%02d\n", hour, minute, second);

	dump_time_struct_bytes(time_ptr, sizeof(struct tm));

	minute = hour = 0; // Отчистить минуты и часы
	int_ptr = (int *) time_ptr;

	for (i = 0; i < 3; i++)
	{
		printf("int_ptr @ 0x%08x : %d\n", int_ptr, *int_ptr);
		int_ptr++; // Прибавление 1 к int_ptr увеличивает адрес на 4,
				   // так как int занимает 4 байта
	}
}
