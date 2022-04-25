#include "push_swap.h"
int	push_swap_five(t_situ	*s, t_mplh *h, t_divid	*d);
int	swap_thrtwo(t_situ	*s, t_mplh *h);

void	push_swap(t_situ	*s, t_mplh *h, int ms)
{
	t_situ	next;
	t_divid	d;

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

int	push_swap_five(t_situ	*s, t_mplh *h, t_divid	*d)
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
			manipulate(pb, s, h);
			i++;
		}
		else
			manipulate(ra, s, h);
	}
	swap_thrtwo(s, h);
	return (1);
}

int	swap_thrtwo(t_situ	*s, t_mplh *h)
{
	raise(s);
	if (!((s->a.len == 3 && !s->a.grd) || s->a.len <= 2 ) || s->b.len > 2 )
		return (0);
	if (s->a.len == 3)
	{
		if (getn(&s->a, 1, DEAL) == getn(&s->g, 0, DEAL))
			manipulate(rra, s, h);
		else if (getn(&s->a, 2, DEAL) == getn(&s->g, 0, DEAL))
			manipulate(ra, s, h);
	}
	raise(s);
	if (s->a.len == 2)
	{
		if (s->b.len == 2 && getn(&s->b, 0, DEAL) > getn(&s->b, 1, DEAL))
			manipulate(ss, s, h);
		else
			manipulate(sa, s, h);
	}
	raise(s);
	while (s->b.len)
		manipulate(pa, s, h);
	raise(s);
	if (s->a.len == 2)
		manipulate(sa, s, h);
	return (1);
}
