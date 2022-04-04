#include <stdio.h>
#include <time.h>

int main()
{
	long int	seconds_since_epoch;
	struct		tm current_time, *time_ptr;
	int			hour, minute, second, day, month, year;

	seconds_since_epoch = time(0); // Передать функции time в качестве
								   // аргумента нулевой указатель
	printf("time() - seconds since epoch: %ld\n", seconds_since_epoch);
	time_ptr = &current_time; // Поместить в time_ptr адрес
							  // структуры current_time
	
	localtime_r(&seconds_since_epoch, time_ptr);

	// Три способа доступа к элементам структуры:

	hour = current_time.tm_hour;	// Прямой доступ
	minute = time_ptr->tm_min;		// Доступ по указателю
	//minute = *((int *) time_ptr + 1);	

	second = *((int *) time_ptr);	// Хакерский доступ по указателю

	printf("Current time is: %02d:%02d:%02d\n", hour, minute, second);
}
