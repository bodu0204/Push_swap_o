#include "push_swap.h"
#include "debug.h"/* test */
int	push_swap1(t_stack	*s, t_dividing	*d);

int	push_swap(t_stack	*s, int ms)
{
	t_dividing	d;

printf("little_push_swap\n");TEST
	if (little_push_swap(s))
		return (1);
	if (!s->a_len && !s->b_len)
		return (0);
printf("set_divide_fmt\n");TEST
	set_divide_fmt(&d, s->g, s->g_len);
printf("divide\n");TEST
	if (divide(s, &d, ms))
		return (1);
printf("treatstack\n");TEST
	if (treatstack(s, ms))
		return (1);
	if (s->a_len <= 2)
	{
printf("swaptwo\n");TEST
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

printf("set_next_stack-a\n");TEST
	set_next_stack(s, &next, d, _a);
printf("push_swap-a\n");TEST
	if (s->a_len)
		if (push_swap(&next, _a))
			return (1);
printf("set_next_stack-b\n");TEST
	set_next_stack(s, &next, d, _b);
printf("push_swap-b\n");TEST
	if (s->b_len)
		if (push_swap(&next, _b))
			return (1);
	return (0);
}
