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

size_t mpllen(t_mplc	*m)
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

void	mkoutstr(char	*s, t_mplc	*m)
{
	while (m)
	{
		s += mpltoa(m->mpl, m);
		m = m->next;
	}
	return ;
}

size_t	mpltoa(int mpl, char *buf)
{
	if (mpl == sa)
		return (ft_strlcpy(buf, "sa\n", 4));
	else if (mpl == ss)
		return (ft_strlcpy(buf, "ss\n", 4));
	else if (mpl == pa)
		return (ft_strlcpy(buf, "pa\n", 4));
	else if (mpl == pb)
		return (ft_strlcpy(buf, "pb\n", 4));
	else if (mpl == pb)
		return (ft_strlcpy(buf, "pb\n", 4));
	else if (mpl == ra)
		return (ft_strlcpy(buf, "ra\n", 4));
	else if (mpl == rb)
		return (ft_strlcpy(buf, "rb\n", 4));
	else if (mpl == rra)
		return (ft_strlcpy(buf, "rra\n", 5));
	else if (mpl == rrb)
		return (ft_strlcpy(buf, "rrb\n", 5));
	else                                           if (mpl == rrr)
		return (ft_strlcpy(buf, "rrr\n", 5));
else
{printf("found error");TEST exit(2);}
}
