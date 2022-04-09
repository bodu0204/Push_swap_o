#include "push_swap.h"
int manipulate1(t_stack	*s, int cmd);
int manipulate2(t_stack	*s, int cmd);
int manipulate3(t_stack	*s, int cmd);
int manipulate4(t_stack	*s, int cmd);

int manipulate(t_stack	*s, int cmd)
{
	int i;

	if (cmd == sa)
	{/* test */if (s->a_len < 2) write(fd, "error\n", 7);/* test */
		i = s->a[s->a_len - 1];
		s->a[s->a_len - 1] = s->a[s->a_len - 2];
		s->a[s->a_len - 1] = i;
		if (write(fd, "sa\n", 3) < 0)
			return (1);
	}
	else if(cmd == sb)
	{/* test */if (s->b_len < 2) write(fd, "error\n", 7);/* test */
		i = s->b[s->b_len - 1];
		s->b[s->b_len - 1] = s->b[s->b_len - 2];
		s->b[s->b_len - 1] = i;
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

int manipulate1(t_stack	*s, int cmd)
{
	int i;

	if (cmd == ss)
	{/* test */if (s->a_len < 2 && s->b_len < 2) write(fd, "error\n", 7);/* test */
		i = s->a[s->a_len - 1];
		s->a[s->a_len - 1] = s->a[s->a_len - 2];
		s->a[s->a_len - 1] = i;
		i = s->b[s->b_len - 1];
		s->b[s->b_len - 1] = s->b[s->b_len - 2];
		s->b[s->b_len - 1] = i;
		if (write(fd, "ss\n", 3) < 0)
			return (1);
	}
	else if(cmd == pa)
	{/* test */if (s->b_len < 1) write(fd, "error\n", 7);/* test */
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

int manipulate2(t_stack	*s, int cmd)
{
	if(cmd == pb)
	{/* test */if (s->a_len < 1) write(fd, "error\n", 7);/* test */
		pop_push(s->b, &s->b_len, s->a, &s->a_len);
		if (write(fd, "pb\n", 3) < 0)
			return (1);
	}
	else if(cmd == ra)
	{/* test */if (s->a_len < 1) write(fd, "error\n", 7);/* test */
		pop_push(s->a, &s->a_len, s->a_back, &s->a_back_len);
		if (write(fd, "rb\n", 3) < 0)
			return (1);
	}
	else if(cmd == rb)
	{/* test */if (s->b_len < 1) write(fd, "error\n", 7);/* test */
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

int manipulate3(t_stack	*s, int cmd)
{
	if(cmd == rr)
	{/* test */if (s->a_len < 1 || s->b_len < 1) write(fd, "error\n", 7);/* test */
		pop_push(s->a, &s->a_len, s->a_back, &s->a_back_len);
		pop_push(s->b, &s->b_len, s->b_back, &s->b_back_len);
		if (write(fd, "rr\n", 3) < 0)
			return (1);
	}
	else if(cmd == rra)
	{/* test */if (s->a_back_len < 1) write(fd, "error\n", 7);/* test */
		pop_push(s->a_back, &s->a_back_len, s->a, &s->a_len);
		if (write(fd, "rra\n", 4) < 0)
			return (1);
	}
	else if(cmd == rrb)
	{/* test */if (s->b_back_len < 1) write(fd, "error\n", 7);/* test */
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
	if(cmd == rrr)
	{/* test */if (s->a_back_len || s->b_back_len < 1) write(fd, "error\n", 7);/* test */
		pop_push(s->a_back, &s->a_back_len, s->a, &s->a_len);
		pop_push(s->b_back, &s->b_back_len, s->b, &s->b_len);
		if (write(fd, "rrr\n", 4) < 0)
			return (1);
	}
	else
	{/* test */
		write(fd, "error\n", 7);/* test */
		return (1);
	}/* test */
	return (0);
}
