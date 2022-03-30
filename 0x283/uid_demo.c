#include <stdio.h>
#include <unistd.h> // without this include will warning 
					// on getuid geteuid

int main()
{
	printf("real uid: %d\n", getuid());
	printf("effective uid: %d\n", geteuid());
}
