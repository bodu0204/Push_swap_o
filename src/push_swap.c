#include "push_swap.h"
#include "debug.h"/* test */
int	push_swap1(t_stack	*s, t_dividing	*d);

int	push_swap(t_stack	*s, int ms)
{
/* test */static	size_t stc = 0;
/* test */const int stc_max = 10;
/* test */const int onoff = 1;
/* test */stc++;
/* test */if (stc > stc_max && onoff)
/* test */{
/* test */	printf("the number is too big"); TEST
/* test */	exit(0);
/* test */}
	t_dividing	d;

printf("----------------------little_push_swap");TESTn("s->a_len", s->a_len)
	if (little_push_swap(s))
		return (1);
	if (!s->a_len && !s->b_len)
		return (0);
printf("----------------------set_divide_fmt");TESTn("s->a_len", s->a_len)
	set_divide_fmt(&d, s->g, s->g_len);
printf("----------------------divide");TESTn("s->a_len", s->a_len)
	if (divide(s, &d, ms))
		return (1);
printf("----------------------treatstack");TESTn("s->a_len", s->a_len)
	if (treatstack(s, ms))
		return (1);
	if (s->a_len <= 2)
	{
printf("----------------------swaptwo");TESTn("s->a_len", s->a_len)
		if (swaptwo(s, &d))
			return (1);
		if (!s->b_len)
			return (0);
	}
	return (push_swap1(s, &d));
}

int	push_swap1(t_stack	*s, t_dividing	*d)
{
	t_stack		next;

printf("----------------------set_next_stack-a");TESTn("s->a_len", s->a_len)
	set_next_stack(s, &next, d, _a);
printf("----------------------push_swap-a");TESTn("s->a_len", s->a_len)
	if (s->a_len)
		if (push_swap(&next, _a))
			return (1);
printf("----------------------set_next_stack-b");TESTn("s->a_len", s->a_len)
	set_next_stack(s, &next, d, _b);
printf("----------------------push_swap-b");TESTn("s->a_len", s->a_len)
	if (s->b_len)
		if (push_swap(&next, _b))
			return (1);
	return (0);
}
