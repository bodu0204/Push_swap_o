#include "push_swap.h"

void	push_swap(t_situation	*s, t_mplh *h, int ms)
{
	t_situation	next;
	t_dividing	d;

	rase(s);
	set_divide_fmt(&d, &s->g);
	if (ms = _a && !s->a.grd && s->a.len == 5)
	{
		push_swap_five(s, h, &d);
		return ;
	}
	if ((ms = _a && s->a.len <= 4) || (ms = _b && s->b.len <= 4))
	{
		little_push_swap(s, h, &d, ms);
		return ;
	}
	divide(s, h, &d, ms);
	treatstack(s, h, ms);
	if (swap_twotwo(s, h))
		return ;
	set_next_stack(s, &next, _a);
	push_swap(&next, h, _a);
	set_next_stack(s, &next, _b);
	push_swap(&next, h, _b);
	return ;
}

void	push_swap_five(t_situation	*s, t_mplh *h, t_dividing	*d)
{
	size_t	i;

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
	if (getn(&s->a, 1, DEAL) == getn(&s->g, 0, DEAL))
		manipulate(rra, s , h);
	else if(getn(&s->a, 2, DEAL) == getn(&s->g, 0, DEAL))
		manipulate(ra, s , h);
	s->a.grd++;
	s->a.len--;
}

int	swap_twotwo(t_situation	*s, t_mplh *h)
{
	if (!s->a.len && !s->b.len)
		return (1);
	if ((s->a.len < 2 || (s->a.len == 2 && getn(s->a, 0, DEAL) >= getn(s->a, 1, DEAL))) && !s->b.len)
	{
		s->a.grd += s->a.len;
		s->a.len = 0;
		return(1);
	}
	if (s->a.len < 2 && s->b.len <= 2)
	{
		s->a.grd += s->a.len;
		s->a.len = 0;
		while (s->b.len)
			manipulate(pa, s, h);
		
	}
	else
}