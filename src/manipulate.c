#include "push_swap.h"
int	manipulate1(t_stack	*s, int cmd);
int	manipulate2(t_stack	*s, int cmd);
int	manipulate3(t_stack	*s, int cmd);
int	manipulate4(t_stack	*s, int cmd);

int manipulate(t_stack	*s, int cmd)
{
	int	i;
	if (cmd == sa)
	{
		i = s->a[s->a_len - 1];
		s->a[s->a_len - 1] = s->a[s->a_len - 2];
		s->a[s->a_len - 2] = i;
		if (write(fd, "sa\n", 3) < 0)
			return (1);
	}
	else if (cmd == sb)
	{
		i = s->b[s->b_len - 1];
		s->b[s->b_len - 1] = s->b[s->b_len - 2];
		s->b[s->b_len - 2] = i;
		if (write(fd, "sb\n", 3) < 0)
			return (1);
	}
	else
	{
		if (manipulate1(s, cmd))
			return (1);
	}
	return (0);
}

int	manipulate1(t_stack	*s, int cmd)
{
	int	i;

	if (cmd == ss)
	{
		i = s->a[s->a_len - 1];
		s->a[s->a_len - 1] = s->a[s->a_len - 2];
		s->a[s->a_len - 2] = i;
		i = s->b[s->b_len - 1];
		s->b[s->b_len - 1] = s->b[s->b_len - 2];
		s->b[s->b_len - 2] = i;
		if (write(fd, "ss\n", 3) < 0)
			return (1);
	}
	else if (cmd == pa)
	{
		pop_push(s->b, &s->b_len, s->a, &s->a_len);
		if (write(fd, "pa\n", 3) < 0)
			return (1);
	}
	else
	{
		if (manipulate2(s, cmd))
			return (1);
	}
	return (0);
}

int	manipulate2(t_stack	*s, int cmd)
{
	if (cmd == pb)
	{
		pop_push(s->a, &s->a_len, s->b, &s->b_len);
		if (write(fd, "pb\n", 3) < 0)
			return (1);
	}
	else if (cmd == ra)
	{
		pop_push(s->a, &s->a_len, s->a_back, &s->a_back_len);
		if (write(fd, "ra\n", 3) < 0)
			return (1);
	}
	else if (cmd == rb)
	{
		pop_push(s->b, &s->b_len, s->b_back, &s->b_back_len);
		if (write(fd, "rb\n", 3) < 0)
			return (1);
	}
	else
	{
		if (manipulate3(s, cmd))
			return (1);
	}
	return (0);
}

int	manipulate3(t_stack	*s, int cmd)
{
	if (cmd == rr)
	{
		pop_push(s->a, &s->a_len, s->a_back, &s->a_back_len);
		pop_push(s->b, &s->b_len, s->b_back, &s->b_back_len);
		if (write(fd, "rr\n", 3) < 0)
			return (1);
	}
	else if (cmd == rra)
	{
		pop_push(s->a_back, &s->a_back_len, s->a, &s->a_len);
		if (write(fd, "rra\n", 4) < 0)
			return (1);
	}
	else if (cmd == rrb)
	{
		pop_push(s->b_back, &s->b_back_len, s->b, &s->b_len);
		if (write(fd, "rrb\n", 4) < 0)
			return (1);
	}
	else
	{
		if (manipulate4(s, cmd))
			return (1);
	}
	return (0);
}

int manipulate4(t_stack	*s, int cmd)
{
	if (cmd == rrr)
	{
		pop_push(s->a_back, &s->a_back_len, s->a, &s->a_len);
		pop_push(s->b_back, &s->b_back_len, s->b, &s->b_len);
		if (write(fd, "rrr\n", 4) < 0)
			return (1);
	}
	else
		return (1);
	return (0);
}
