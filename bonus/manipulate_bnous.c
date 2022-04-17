#include "checker.h"
int manipulate1(t_checker	*s, char *order , int *ko);
int manipulate2(t_checker	*s, char *order , int *ko);
int manipulate3(t_checker	*s, char *order , int *ko);
int manipulate4(t_checker	*s, char *order , int *ko);

int manipulate(t_checker	*s, char *order , int *ko)
{
	int i;
	int ii;

	if (!ft_memcmp(order, "sa\n" ,3))
	{
		if (s->a_len >= 2)
		{
			i = s->a[(s->a_base + s->a_len + (s->buf_len - 1)) % s->buf_len];
			ii = s->a[(s->a_base + s->a_len + (s->buf_len - 2)) % s->buf_len];
			s->a[(s->a_base + s->a_len + (s->buf_len - 1)) % s->buf_len] = ii;
			s->a[(s->a_base + s->a_len + (s->buf_len - 2)) % s->buf_len] = i;
		}
		*ko = check(s);
		return (3);
	}
	else if(!ft_memcmp(order, "sb\n" ,3))
	{
		if (s->b_len >= 2)
		{
			i = s->b[(s->b_base + s->b_len + (s->buf_len - 1)) % s->buf_len];
			ii = s->b[(s->b_base + s->b_len + (s->buf_len - 2)) % s->buf_len];
			s->b[(s->b_base + s->b_len + (s->buf_len - 1)) % s->buf_len] = ii;
			s->b[(s->b_base + s->b_len + (s->buf_len - 2)) % s->buf_len] = i;
		}
		*ko = check(s);
		return (3);
	}
	return (manipulate1(s, order, ko));
}

int manipulate1(t_checker	*s, char *order , int *ko)
{
	int i;

	if (!ft_memcmp(order, "ss\n" ,3))
	{
		*ko = check(s);
		return (3);
	}
	else if(!ft_memcmp(order, "pa\n" ,3))
	{
		*ko = check(s);
		return (3);
	}
	return (manipulate2(s, order, ko));
}

int manipulate2(t_checker	*s, char *order , int *ko)
{
	if(!ft_memcmp(order, "pb\n" ,3))
	{
		*ko = check(s);
		return (3);
	}
	else if(!ft_memcmp(order, "ra\n" ,3))
	{
		*ko = check(s);
		return (3);
	}
	else if(!ft_memcmp(order, "rb\n" ,3))
	{
		*ko = check(s);
		return (3);
	}
	return (manipulate3(s, order, ko));
}

int manipulate3(t_checker	*s, char *order , int *ko)
{
	if(!ft_memcmp(order, "rr\n" ,3))
	{
		*ko = check(s);
		return (4);
	}
	else if(!ft_memcmp(order, "rra\n" ,4))
	{
		*ko = check(s);
		return (4);
	}
	else if(!ft_memcmp(order, "rrb\n" ,4))
	{
		*ko = check(s);
		return (4);
	}
	return (manipulate4(s, order, ko));
}

int manipulate4(t_checker	*s, char *order , int *ko)
{
	if(!ft_memcmp(order, "rrr\n" ,4))
	{
		*ko = check(s);
		return (4);
	}
	*ko = -1;
	return (0);
}
