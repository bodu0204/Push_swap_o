#include "push_swap.h"
#include "debug.h"/* test */
int manipulate1(t_stack	*s, int cmd);
int manipulate2(t_stack	*s, int cmd);
int manipulate3(t_stack	*s, int cmd);
int manipulate4(t_stack	*s, int cmd);

int manipulate(t_stack	*s, int cmd)
{
	int i;
/* test */static	size_t stc = 0;
/* test */stc++;
/* test */if (stc > 30 + 0)
/* test */{
/* test */	printf("the number is too big"); TEST
/* test */	exit(0);
/* test */}
	if (cmd == sa)
	{/* test */if (s->a_len < 2) TEST/* test */
		i = s->a[s->a_len - 1];
		s->a[s->a_len - 1] = s->a[s->a_len - 2];
		s->a[s->a_len - 2] = i;
		write(fd, "  a>  \n", 7);/* test */
		/* if (write(fd, "sa\n", 3) < 0)
			return (1); */
	tests(s);
	}
	else if(cmd == sb)
	{/* test */if (s->b_len < 2) TEST/* test */
		i = s->b[s->b_len - 1];
		s->b[s->b_len - 1] = s->b[s->b_len - 2];
		s->b[s->b_len - 2] = i;
		write(fd, "  b>  \n", 7);/* test */
		/* if (write(fd, "sb\n", 3) < 0)
			return (1); */
	tests(s);
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
	{/* test */if (s->a_len < 2 && s->b_len < 2) TEST/* test */
		i = s->a[s->a_len - 1];
		s->a[s->a_len - 1] = s->a[s->a_len - 2];
		s->a[s->a_len - 2] = i;
		i = s->b[s->b_len - 1];
		s->b[s->b_len - 1] = s->b[s->b_len - 2];
		s->b[s->b_len - 2] = i;
		write(fd, "  ab>  \n", 8);/* test */
		/* if (write(fd, "ss\n", 3) < 0)
			return (1); */
	tests(s);
	}
	else if(cmd == pa)
	{/* test */if (s->b_len < 1) TEST/* test */
		pop_push(s->b, &s->b_len, s->a, &s->a_len);
		write(fd, "  b→a  \n", 10);/* test */
		/* if (write(fd, "pa\n", 3) < 0)
			return (1); */
	tests(s);
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
	{/* test */if (s->a_len < 1) TEST/* test */
		pop_push(s->a, &s->a_len, s->b, &s->b_len);
		write(fd, "  a→b  \n", 10);/* test */
		/* if (write(fd, "pb\n", 3) < 0)
			return (1); */
	tests(s);
	}
	else if(cmd == ra)
	{/* test */if (s->a_len < 1) TEST/* test */
		pop_push(s->a, &s->a_len, s->a_back, &s->a_back_len);
		write(fd, "  a↓  \n", 9);/* test */
		/* if (write(fd, "ra\n", 3) < 0)
			return (1); */
	tests(s);
	}
	else if(cmd == rb)
	{/* test */if (s->b_len < 1) TEST/* test */
		pop_push(s->b, &s->b_len, s->b_back, &s->b_back_len);
		write(fd, "  b↓  \n", 9);/* test */
		/* if (write(fd, "rb\n", 3) < 0)
			return (1); */
	tests(s);
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
	{/* test */if (s->a_len < 1 || s->b_len < 1) TEST/* test */
		pop_push(s->a, &s->a_len, s->a_back, &s->a_back_len);
		pop_push(s->b, &s->b_len, s->b_back, &s->b_back_len);
		write(fd, "  ab↓  \n", 10);/* test */
		/* if (write(fd, "rr\n", 3) < 0)
			return (1); */
	tests(s);
	}
	else if(cmd == rra)
	{/* test */if (s->a_back_len < 1) TEST/* test */
		pop_push(s->a_back, &s->a_back_len, s->a, &s->a_len);
		write(fd, "  a↑  \n", 9);/* test */
		/* if (write(fd, "rra\n", 4) < 0)
			return (1); */
	tests(s);
	}
	else if(cmd == rrb)
	{/* test */if (s->b_back_len < 1) TEST/* test */
		pop_push(s->b_back, &s->b_back_len, s->b, &s->b_len);
		write(fd, "  b↑  \n", 9);/* test */
		/* if (write(fd, "rrb\n", 4) < 0)
			return (1); */
	tests(s);
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
	{/* test */if (s->a_back_len || s->b_back_len < 1) TEST/* test */
		pop_push(s->a_back, &s->a_back_len, s->a, &s->a_len);
		pop_push(s->b_back, &s->b_back_len, s->b, &s->b_len);
		write(fd, "  ab↑  \n", 10);/* test */
		/* if (write(fd, "rrr\n", 4) < 0)
			return (1); */
	tests(s);
	}
	else
	{/* test */
		write(fd, "manipulate error\n", 20);/* test */
		return (1);
	}/* test */
	return (0);
}
