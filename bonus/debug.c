#include "debug.h"
#include "checker.h"
void tests(t_checker *s)
{
	size_t	i;

	i = 0;
	printf("\na|");
	while(i < s->a_len)
	{
		printf("%3d,", s->a[(s->a_base + i) % s->buf_len]);
		i++;
	}
	printf("\nb|");
	i = 0;
	while(i < s->b_len)
	{
		printf("%3d,", s->b[(s->b_base + i) % s->buf_len]);
		i++;
	}
	fflush(stdout);
	return ;
}
