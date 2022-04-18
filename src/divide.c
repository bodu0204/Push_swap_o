#include "push_swap.h"
int		divide_from_a(t_stack	*s, t_dividing *d, t_dividing *next);
int		push_from_a(t_stack	*s, int *flag, t_dividing *next);
int		divide_from_b(t_stack	*s, t_dividing *d, t_dividing *next);
int		push_from_b(t_stack	*s, int *flag, t_dividing *next);

int divide(t_stack	*s, t_dividing *d, int ms)
{
	t_dividing	next;

	if (ms == _a)
	{
		set_divide_fmt(&next, s->g + d->ma, d->mb);
		return (divide_from_a(s, d, &next));
	}
	set_divide_fmt(&next, s->g, d->ma);
	return(divide_from_b(s, d, &next));
}

int divide_from_a(t_stack	*s, t_dividing *d, t_dividing *next)
{
	size_t	ib;
	int		flag;

	ib = 0;
	flag = 0;
	while(ib < d->mb)
	{
		if (s->a[s->a_len - 1] >= d->dn)
		{
			if (s->a[s->a_len - 1] == d->dn)
				d->use++;
			if (rotate(s, &flag, _a))
				return (1);
		}
		else
		{
			ib++;
			if (push_from_a(s, &flag, next))
				return (1);
		}
	}
	if (flag)
		if (manipulate(s, rb))
			return (1);
	return(0);
}

int push_from_a(t_stack	*s, int *flag, t_dividing *next)
{
	int i;

	if (*flag)
		if (manipulate(s, rb))
			return (1);
	*flag = 0;
	i = s->a[s->a_len - 1];
	if (manipulate(s, pb))
		return (1);
	if (s->b_len - 1 <= next->ma \
	&& i <= next->dn && s->a != s->a_base)
	{
		if (i < next->dn)
			*flag = 1;
		else
			next->use++;
	}
	return (0);
}

int divide_from_b(t_stack	*s, t_dividing *d, t_dividing *next)
{
	size_t		ibb;
	int			flag;

	ibb = 0;
	flag = 0;
	while(ibb < d->ma)
	{
		if (s->b[s->b_len - 1] < d->dn )
		{
			if (s->b[s->b_len - 1] == d->dn)
				d->use++;
			if (rotate(s, &flag, _b))
				return (1);
		}
		else
		{
			ibb++;
			if (push_from_b(s, &flag, next))
				return (1);
		}
	}
	if (flag)
		if (manipulate(s, ra))
			return (1);
	return(0);
}

int push_from_b(t_stack	*s, int *flag, t_dividing *next)
{
	int i;

	if (*flag)
		if (manipulate(s, ra))
			return (1);
	*flag = 0;
	i = s->b[s->b_len - 1];
	if (manipulate(s, pa))
		return (1);
	if (s->a_len - 1 <= next->mb \
	&& i <= next->dn && s->b != s->b_base)
	{
		if (i >= next->dn)
			*flag = 1;
		else
			next->use++;
	}
	return (0);
}
