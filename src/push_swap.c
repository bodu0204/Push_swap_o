#include "push_swap.h"
#include "debug.h" //test
int	push_swap_five(t_situation	*s, t_mplh *h, t_dividing	*d);
int	swap_thrtwo(t_situation	*s, t_mplh *h);

void	push_swap(t_situation	*s, t_mplh *h, int ms)
{
TEST_
	t_situation	next;
	t_dividing	d;

	raise(s);
	set_divide_fmt(&d, &s->g, _none);
	if (push_swap_five(s, h, &d))
		return ;
	if (swap_thrtwo(s, h))
		return ;
	divide(s, h, &d, ms);
	treatstack(s, h);
	if (swap_thrtwo(s, h))
		return ;
	set_next_stack(s, &next, _a);
	push_swap(&next, h, _a);
	set_next_stack(s, &next, _b);
	push_swap(&next, h, _b);
	return ;
}

int	push_swap_five(t_situation	*s, t_mplh *h, t_dividing	*d)
{
TEST_
	size_t	i;

TESTn("s->a.len", s->a.len)
TESTn("s->a.grd", s->a.grd)
TESTn("s->a.udr", s->a.udr)
	if (s->a.grd || s->a.len != 5)
		return (0);
	while (getn(&s->a, 0, BOTTOM) < d->num)
		manipulate(rra, s, h);
	i = 0;
	while (i < d->mut)
	{
		if (getn(&s->a, 0, TOP) < d->num)
		{
			manipulate(pb, s , h);
			i++;
		}
		else
			manipulate(ra, s , h);
	}
	swap_thrtwo(s, h);
	return (1);
}

int	swap_thrtwo(t_situation	*s, t_mplh *h)
{
TEST_
	if (!s->a.len && !s->b.len)
		return (1);
	if (s->a.len == 3 && !s->a.grd && s->b.len <= 2)
	{
		if (getn(&s->a, 1, DEAL) == getn(&s->g, 0, DEAL))
		manipulate(rra, s , h);
		else if(getn(&s->a, 2, DEAL) == getn(&s->g, 0, DEAL))
			manipulate(ra, s , h);
		s->a.grd++;
		s->a.len--;
		return (swap_thrtwo(s, h));
	}
	if ((s->a.len < 2 || (s->a.len == 2 && getn(&s->a, 0, DEAL) >= getn(&s->a, 1, DEAL))) && s->b.len <= 2)
	{
		s->a.grd += s->a.len;
		s->a.len = 0;
		return(swap_thrtwo(s, h));
	}
	if (s->a.len == 2 && getn(&s->a, 0, DEAL) < getn(&s->a, 1, DEAL) && s->b.len <= 2)
	{
		manipulate(sa, s, h);
		return(swap_thrtwo(s, h));
	}
	if (!s->a.len && (s->b.len < 2 || (s->b.len == 2 && getn(&s->b, 0, DEAL) <= getn(&s->b, 1, DEAL))))
	{
		while (s->b.len)
			manipulate(pa, s, h);
		return (swap_thrtwo(s, h));
	}
	if (!s->a.len && (s->b.len < 2 || (s->b.len == 2 && getn(&s->b, 0, DEAL) > getn(&s->b, 1, DEAL))))
	{
		manipulate(sb, s, h);
		return (swap_thrtwo(s, h));
	}
	return (0);
}
