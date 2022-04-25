#include "debug.h"
#include "push_swap.h"
void tests(t_situation *s)
{
	showstack(&s->a, 'a');
	showstack(&s->b, 'b');
	showstack(&s->g, 'g');
	return ;
}

void showstack(t_stack *s, char c)
{
	size_t	i;

	putchar(c);
	putchar('|');
	i = 0;
	while (i < s->udr + s->grd + s->len)
	{
		printf("%4d", getn(s, i , UNDER) % 1000);
		i++;
	}
	printf("\n  ");
	i = 0;
	while (i < s->udr)
	{
		printf("    ");
		i++;
	}
	if (i == s->udr)
		printf("^   ");
	i = 1;
	while (i < s->grd)
	{
		printf("    ");
		i++;
	}
	if (i == s->grd)
		printf("^   ");
	putchar('\n');
	fflush(stdout);
	return ;
}
