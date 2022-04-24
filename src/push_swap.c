#include "push_swap.h"
#include "debug.h" //test

void	push_swap(t_situation	*s, t_mplh *h, int ms)
{
	t_situation	next;
	t_dividing	d;

	rase(s);
	set_divide_fmt(&d, &s->g);
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
	size_t	i;

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

void	rase(t_situation	*s)
{
	while (getn(&s->a, 0, DEAL) == getn(&s->g, 0, DEAL) && s->a.len)
	{
		s->a.grd++;
		s->g.grd++;
		s->a.len--;
		s->g.len--;
	}
	return ;
}

void	set_divide_fmt(t_dividing *d, t_stack *g)
{
	d->mut = g->len / 2;
	d->inc = g->len % 2;
	d->num = getn(g, d->mut + d->inc - 1, DEAL);
	d->use = 0;
}

void	treatstack(t_situation	*s, t_mplh *h)
{
	while (s->a.udr && s->b.udr)
		manipulate(rrr, s, h);
	while (s->a.udr)
		manipulate(rra, s, h);
	while (s->b.udr)
{
		manipulate(rrb, s, h);
TEST
}
	raise(s);
}


void	set_next_stack(t_situation	*s, t_situation	*next, int ms)
{
	ft_memcpy(next, s, sizeof(t_situation));
	next->a.udr = 0;
	next->b.udr = 0;
	if (ms == _a)
	{
		next->g.len -= s->b.len;
		next->b.grd += s->b.len;
		next->b.len = 0;
	}
	else
	{
		next->g.grd += s->a.len;
		next->g.len -= s->a.len;
		next->a.grd += s->a.len;
		next->a.len = 0;
	}
	return (0);
}
