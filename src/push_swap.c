#include "push_swap.h"
void	pop_push(int *pops, size_t *pol, int *pushs, size_t *pul);
void	set_divide_fmt(t_dividing	*d, int	*goal, size_t	l);
int		divide(t_stack	*s, t_dividing *d, int ms);
int		divide_from_a(t_stack	*s, t_dividing *d, t_dividing *next);
int		push_from_a(t_stack	*s, int *flag, t_dividing *next);
int		rotate(t_stack *s, int *flag, int ms);
int		divide_from_b(t_stack	*s, t_dividing *d, t_dividing *next);
int		push_from_b(t_stack	*s, int *flag, t_dividing *next);
int		treatstack(t_stack	*s, int ms);
void	mvstack(int *mst, size_t *msl, int *bst, size_t *bsl);
void	set_next_stack(t_stack *s, t_stack *next, t_dividing *d, int ms);
int		swaptwo(t_stack *s, t_dividing *d);
void	raise_a(t_stack *s);
int		little_push_swap(t_stack *s);

int push_swap(t_stack	*s, int ms)
{
	t_stack		next;
	t_dividing	d;
	if (little_push_swap(s))
		return (1);
	if (!s->a_len && !s->b_len)
		return (0);
	set_divide_fmt(&d, s->g, s->g_len);
	if (divide(s, &d, ms))
		return (1);
	if (treatstack(s, ms))
		return (1);
	if (s->a_len <= 2)
	{
		if(swaptwo(s, &d))
			return(1);
		if (!s->b_len)
			return(0);
	}
	set_next_stack(s, &next, &d, _a);
	if (s->a_len)
		if (push_swap(&next, _a))
			return (1);
	set_next_stack(s, &next, &d, _b);
	if (s->b_len)
		if (push_swap(&next, _b))
			return (1);
	return (0);
}

void pop_push(int *pops, size_t *pol, int *pushs, size_t *pul)
{
	(*pol)--;
	pushs[*pul] = pops[*pol];
	(*pul)++;
}

void	set_divide_fmt(t_dividing	*d, int	*goal, size_t	l)
{
	size_t	i;

	ft_bzero(d, sizeof(t_dividing));
	i = (l / 2) + (l % 2) - 1;
	d->dn = goal[i];
	while (goal[i] == d->dn && i < l)
		i++;
	d->mb = l - i;
	d->ma = i;
	if (!d->mb)
	{
		i = 0;
		while (goal[i] > d->dn)
			i++;
		d->dn = goal[i - 1];
		d->mb = l - i;
		d->ma = i;
	}
	return ;
}

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

int rotate(t_stack *s, int *flag, int ms)
{
	if (*flag)
	{
		if(manipulate(s, rr))
			return (1);
	}
	else if (ms == _a)
	{
		if(manipulate(s, ra))
			return (1);
	}
	else if (ms == _b)
	{
		if(manipulate(s, rb))
			return (1);
	}
	else
		return (1);
	*flag = 0;
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

int treatstack(t_stack	*s, int ms)
{
	if ((ms == _a && s->a == s->a_base) \
	|| (ms == _b && s->b == s->b_base))
	{
		mvstack(s->a_base, &s->a_len, s->a_back, &s->a_back_len);
		mvstack(s->b_base, &s->b_len, s->b_back, &s->b_back_len);
		raise_a(s);
		return (0);
	}
	while (s->a_back_len && s->b_back_len)
		if (manipulate(s, rrr))
			return(1);
	while (s->a_back_len)
		if (manipulate(s, rra))
			return(1);
	while (s->b_back_len)
		if (manipulate(s, rrb))
			return(1);
	raise_a(s);
	return (0);
}

void	mvstack(int *mst, size_t *msl, int *bst, size_t *bsl)
{
	size_t	i;

	i = 0;
	ft_memmove(mst + *bsl, mst, *msl * sizeof(int));
	while (i < *bsl)
	{
		mst[*bsl - i - 1] = bst[i];
		i++;
	}
	*msl += *bsl;
	*bsl = 0;
	return ;
}

void set_next_stack(t_stack *s, t_stack *next, t_dividing *d, int ms)
{
	ft_memcpy(next, s, sizeof(t_stack));
	next->a_back_len = 0;
	next->b_back_len = 0;
	if (ms == _a)
	{
		next->g_len -= d->mb;
		next->b += d->mb;
		next->b_len = 0;
	}
	else
	{
		next->g += d->ma;
		next->g_len -= d->ma;
		next->a += d->ma;
		next->a_len = 0;
	}
	return ;
}

int swaptwo(t_stack *s, t_dividing *d)
{
	if (s->a_len == 2 && (s->a[s->a_len - 1] > s->a[s->a_len - 2]) \
	&& (s->b_len == 2 && s->b[s->b_len - 1] < s->b[s->a_len - 2]))
	{
		if (manipulate(s, ss))
			return(1);
	}
	else if (s->a_len == 2 && s->a[s->a_len -1] > s->a[s->a_len -2])
	{
		if (manipulate(s, sa))
			return(1);
	}
	else if (s->b_len == 2 && s->b[s->b_len - 1] < s->b[s->a_len - 2])
	{
		if (manipulate(s, sb))
			return(1);
	}
	while ((d->ma||s->b_len <= 2) && s->b_len)
		if (manipulate(s, pa))
			return (1);
	return (0);
}

void raise_a(t_stack *s)
{
	while (*(s->a) == *(s->g) && s->a_len)
	{
		s->a++;
		s->g++;
		s->g_len--;
		s->a_len--;
	}
	return ;
}

int little_push_swap(t_stack *s)
{
	raise_a(s);
	if (s->a_len && s->a_len <= 2)
	{
		if (s->a_len == 2)
		{
			if(manipulate(s, sa))
				return (1);
		}
		s->a += s->a_len;
		s->g += s->g_len;
		s->a_len = 0;
		s->g_len = 0;
	}
	return (0);
}
