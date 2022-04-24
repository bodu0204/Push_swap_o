#include "push_swap.h"
#include "debug.h" //test
size_t mpllen(t_mplc	*m);
void	mkoutstr(char	*s, t_mplc	*m);
size_t	mpltoa(int mpl, char *buf);

char	*mkout(t_mplh *h)
{
	int flag;
	t_mplc	*m;
	char	*s;

mpllen(h->cnt);TEST
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
mpllen(h->cnt);TEST
	}
	s = malloc(mpllen(h->cnt) + 1);
TEST
	if (!s)
	{
		free_all(h);
		write(STDOUT_FILENO, "malloc Error\n", 13);
		exit(1);
	}
	mkoutstr(s, h->cnt);
	return (s);
}

size_t mpllen(t_mplc	*m)
{
	size_t	len;

	len = 0;
	while (m)
	{
printf("%d", m->mpl);
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
		s += mpltoa(m->mpl, s);
		m = m->next;
	}
	return ;
}

size_t	mpltoa(int mpl, char *buf)
{
	if (mpl == sa)
		return (ft_strlcpy(buf, "sa\n", 4));
	else if (mpl == sb)
		return (ft_strlcpy(buf, "sb\n", 4));
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
