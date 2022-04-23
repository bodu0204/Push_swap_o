#include "push_swap.h"
#include "debug.h" //test

char	*mkout(t_mplh *h)
{
	int flag;
	t_mplc	*m;
	char	*s;

	flag = 1;
	while(flag && h->cnt)
	{
		flag = 0;
		h->cnt = omitmpl(h->cnt, &flag);
		m = h->cnt;
		while (m)
		{
			m->next = omitmpl(m->next, &flag);
			m = m->next;
		}
	}
	s = malloc(mpllen(h->cnt) + 1);
	if (!s)
		{
		free_all(h);
		write(STDOUT_FILENO, "malloc Error\n", 13);
		exit(1);
	}
	mkoutstr(s, h->cnt);
	return (s);
}

t_mplc	*omitmpl(t_mplc	*one, int *flag)
{
	t_mplc	*two;
	t_mplc	*rtn;

if (!one)
{printf("found error");TEST exit(2);}
	two = one->next;
	if (!two)
		return (NULL);
	if ((one->mpl == pa && two->mpl == pb) || (one->mpl == pb && two->mpl == pa) \
	|| (one->mpl == sa && two->mpl == sa) \
	|| (one->mpl == sb && two->mpl == sb) \
	|| (one->mpl == ss && two->mpl == ss) \
	|| (one->mpl == ra && two->mpl == rra) || (one->mpl == rra && two->mpl == ra) \
	|| (one->mpl == rb && two->mpl == rrb) || (one->mpl == rrb && two->mpl == rb) \
	|| (one->mpl == rr && two->mpl == rrr) || (one->mpl == rrr && two->mpl == rr))
	{
		*flag = 1;
		rtn = two->next;
		free(one);
		free(two);
		return (rtn);
	}
	else
		return(omitmpl1(one, two, flag));
}

t_mplc	*omitmpl1(t_mplc	*one, t_mplc	*two, int *flag)
{
	if ((one->mpl == sa && two->mpl == sb) || (one->mpl == sb && two->mpl == sa))
	{
		*flag = 1;
		two->mpl = ss;
		free(one);
		return (two);
	}
	else if ((one->mpl == ra && two->mpl == rb) || (one->mpl == rb && two->mpl == ra))
	{
		*flag = 1;
		two->mpl = rr;
		free(one);
		return (two);
	}
	else if ((one->mpl == rra && two->mpl == rrb) || (one->mpl == rrb && two->mpl == rra))
	{
		*flag = 1;
		two->mpl = rrr;
		free(one);
		return (two);
	}
	else
		return(one);
}

size_t mkoutstr(t_mplc	*m)
{
	size_t	len;

	len = 0;
	while (m)
	{
		if (m->mpl == sa || m->mpl == sb || m->mpl == ss || m->mpl == pa \
		|| m->mpl == pb || m->mpl == ra || m->mpl == rb || m->mpl == rr)
		{
			len += 3;
		}
		else
			len += 4;
		m = m->next;
	}
	return (len);
}

size_t mpllen(char	*s, t_mplc	*m)
{
	while (m)
	{
		if (m->mpl == sa)
		{
			
			s += 3;
		}
		else
			i += 4;
		m = m->next;
	}
	return (i);
}