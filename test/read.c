#include <unistd.h>
#include <stdio.h>
#include<string.h>
#define BUFFER 32
void show(char* s);

int main (void)
{
	char buf[BUFFER];
	int i = 1;

	bzero(buf, sizeof(buf));
	while(i)
		i = read(0, buf, BUFFER);
	printf("%d", i);
	show(buf);
	read(0, buf, BUFFER);
B	return (0);
}

void show(char* s)
{
	size_t i;
	size_t ii;
	size_t m;
	size_t line;

	line = 32;
	m = 0;
	ii = 0;
	printf("\nstart:%p\n", s);
	while (m < 3)
	{
		printf("|");
		i = 0;
		while (i < line)
		{
			printf("%7zu|", ii + i + 1);
			i++;
		}
		printf("\n|");
		i = 0;
		while (i < line)
		{
			if (*(s + ii + i) == 0 && !m)
				m++;
			printf("%4d(%c)|", (int)*(s + ii + i), (*(s + ii + i) > 32 && *(s + ii + i) < 127) ? *(s + ii + i) : 32);
			i++;
		}
		printf("\n");
		if (m > 0)
		    m++;
		ii += line;
	}

}
