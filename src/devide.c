#include "push_swap.h"
#include "debug.h" //test

void divide(t_situation *s, t_mplh *h, t_dividing *d, int ms)
{
	t_dividing	next;

	if (ms == _a)
	{
		set_divide_fmt(&next, s, _a);
		divide_from_a(s, h, d, &next);
	}
	else
	{
		set_divide_fmt(&next, s, _b);
		divide_from_b(s, h, d, &next);
	}
	return ;
}

void	divide_from_a(t_situation *s, t_mplh *h, t_dividing *d, t_dividing *next)
{
	next->use = rotate_mount(s, d, _a);
	while (d->use < d->mut)
	{
		if (d->use + 1 == d->mut && s->a.len >= 2)
		{
			if (getn(&s->a, s->a.len - 2, DEAL) < d->num)
				manipulate(sa, s, h);
		}
		if (getn(&s->a, 0, TOP) >= d->num)
			manipulate(ra, s, h);
		else
		{
			manipulate(pb, s, h);
			if (s->b.grd && getn(&s->b, 0, TOP) >= next->num && next->use)
			{
				manipulate(rb, s, h);
				next->use--;
			}
			else if (!s->b.grd && getn(&s->b, 0, TOP) < next->num)
				manipulate(rb, s, h);
			d->use++;
		}
	}
	return ;
}

void	divide_from_b(t_situation *s, t_mplh *h, t_dividing *d, t_dividing *next)
{
	next->use = rotate_mount(s, d, _b);
	while (d->use < d->mut + d->inc)
	{
		if (d->use + 1 == d->mut + d->inc && s->b.len >= 2)
		{
			if (getn(&s->a, s->b.len - 2, DEAL) >= d->num)
				manipulate(sb, s, h);
		}
		if (getn(&s->b, 0, TOP) < d->num)
			manipulate(rb, s, h);
		else
		{
			manipulate(pa, s, h);
			if (s->a.grd && getn(&s->b, 0, TOP) < next->num && next->use)
			{
				manipulate(ra, s, h);
				next->use--;
			}
			else if (!s->a.grd && getn(&s->b, 0, TOP) >= next->num)
				manipulate(ra, s, h);
			d->use++;
		}
	}
	return ;
}

size_t