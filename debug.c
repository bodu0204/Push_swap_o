#include "debug.h"
#include "push_swap.h"
void tests(t_stack *s)
{
	int *i;
	int ii;
/* test */static	size_t stc = 0;

	i = s->a_base;
	printf("\na|");
	while (i < s->a + s->a_len)
	{
/* test */stc++;
/* test */if (stc > 1000 + 0)
/* test */{
/* test */	printf("the number is too big"); TEST
/* test */	exit(0);
/* test */}
		printf("%3d,", *i % 1000);
		i++;
	}
	printf("\n  ");
	i = s->a_base;
	while (i < s->a)
	{
/* test */stc++;
/* test */if (stc > 1000 + 0)
/* test */{
/* test */	printf("the number is too big"); TEST
/* test */	exit(0);
/* test */}
		printf("    ");
		i++;
	}
	printf("^\n");
	i = s->b_base;
	printf("b|");
	while (i < s->b + s->b_len)
	{
/* test */stc++;
/* test */if (stc > 1000 + 0)
/* test */{
/* test */	printf("the number is too big"); TEST
/* test */	exit(0);
/* test */}
		printf("%3d,", *i % 1000);
		i++;
	}
	printf("\n  ");
	i = s->b_base;
	while (i < s->b)
	{
/* test */stc++;
/* test */if (stc > 1000 + 0)
/* test */{
/* test */	printf("the number is too big"); TEST
/* test */	exit(0);
/* test */}
		printf("    ");
		i++;
	}
	printf("^\n");
	ii = 0;
	printf("g|");
	while ((size_t)ii < s->g_len)
	{
/* test */stc++;
/* test */if (stc > 1000 + 0)
/* test */{
/* test */	printf("the number is too big"); TEST
/* test */	exit(0);
/* test */}
		printf("%3d,", s->g[ii] % 1000);
		ii++;
	}
	printf("\n");
	i = s->a_back + s->a_back_len - 1;
	for (size_t a = 0; a < s->a_back_len; a++)
	{
/* test */stc++;
/* test */if (stc > 1000 + 0)
/* test */{
/* test */	printf("the number is too big"); TEST
/* test */	exit(0);
/* test */}
		printf("%3d,", *i % 1000);
		i--;
	}
	printf("|a_back\n");
	i = s->b_back + s->b_back_len - 1;
	for (size_t a = 0; a < s->b_back_len; a++)
	{
/* test */stc++;
/* test */if (stc > 1000 + 0)
/* test */{
/* test */	printf("the number is too big"); TEST
/* test */	exit(0);
/* test */}
		printf("%3d,", *i % 1000);
		i--;
	}
	printf("|b_back\n");
	fflush(stdout);
	return ;
}
