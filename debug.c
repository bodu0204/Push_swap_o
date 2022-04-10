#include "debug.h"
#include "push_swap.h"
void tests(t_stack *s)
{
	int *i;
	int ii;

	i = s->a_base;
	printf("\na|");
	while (i < s->a + s->a_len)
	{
		printf("%3d,", *i % 1000);
		i++;
	}
	printf("\n  ");
	i = s->a_base;
	while (i < s->a)
	{
		printf("    ");
		i++;
	}
	printf("^\n");
	i = s->b_base;
	printf("b|");
	while (i < s->b + s->b_len)
	{
		printf("%3d,", *i % 1000);
		i++;
	}
	printf("\n  ");
	i = s->b_base;
	while (i < s->b)
	{
		printf("    ");
		i++;
	}
	printf("^\n");
	ii = 0;
	printf("g|");
	while ((size_t)ii < s->g_len)
	{
		printf("%3d,", s->g[ii] % 1000);
		ii++;
	}
	printf("\n");
	i = s->a_back + s->a_back_len - 1;
	for (size_t a = 0; a < s->a_back_len; a++)
	{
		printf("%3d,", *i % 1000);
		i--;
	}
	printf("|a_back\n");
	i = s->b_back + s->b_back_len - 1;
	for (size_t a = 0; a < s->b_back_len; a++)
	{
		printf("%3d,", *i % 1000);
		i--;
	}
	printf("|b_back\n");
	fflush(stdout);
	return ;
}
