#include <stdio.h>

int main()
{
	printf("The 'int' data type is\t\t %d bytes\n", sizeof(int));
		// sizeof() возвращает размер типа данных
	printf("The 'unsigned int' data type is\t %d bytes\n",
			sizeof(unsigned int));
		// %d спецификатор вывода целочисленных переменных
	printf("The 'short int' data type is\t %d bytes\n", sizeof(short int));
	printf("The 'long int' data type is\t %d bytes\n", sizeof(long int));
	printf("The 'long long int' data type is %d bytes\n",
			sizeof(long long int));
	printf("The 'unsigned long int' data type is %d bytes\n",
			sizeof(unsigned long int));
	printf("The 'float' data type is\t %d bytes\n", sizeof(float));
	printf("The 'char' data type is\t\t %d bytes\n", sizeof(char));
	printf("The 'void*' data type is\t %d bytes\n", sizeof(void*));
	printf("The 'char*' data type is\t %d bytes\n", sizeof(char*));


}
