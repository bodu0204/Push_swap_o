#include "push_swap.h"
#include "debug.h" //test
void	divide_from_a(t_situation *s, t_mplh *h, t_dividing *d, t_dividing *next);
void	divide_from_b(t_situation *s, t_mplh *h, t_dividing *d, t_dividing *next);
size_t	rotate_mount_a(t_situation *s, t_dividing *d);
size_t	rotate_mount_b(t_situation *s, t_dividing *d);

void divide(t_situation *s, t_mplh *h, t_dividing *d, int ms)
{
TEST_
	t_dividing	next;

	if (ms == _a)
	{
		set_divide_fmt(&next, &s->g, _a);
		divide_from_a(s, h, d, &next);
	}
	else
	{
		set_divide_fmt(&next, &s->g, _b);
		divide_from_b(s, h, d, &next);
	}
	return ;
}

void	divide_from_a(t_situation *s, t_mplh *h, t_dividing *d, t_dividing *next)
{
	next->use = rotate_mount_a(s, d);
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
			else if (!s->b.grd && getn(&s->b, 0, TOP) < next->num && s->b.len > 1)
				manipulate(rb, s, h);
			d->use++;
		}
	}
	return ;
}

void	divide_from_b(t_situation *s, t_mplh *h, t_dividing *d, t_dividing *next)
{
	next->use = rotate_mount_b(s, d);
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
			if (s->a.grd && getn(&s->a, 0, TOP) < next->num && next->use)
			{
				manipulate(ra, s, h);
				next->use--;
			}
			else if (!s->a.grd && getn(&s->a, 0, TOP) >= next->num && s->a.len > 1)
				manipulate(ra, s, h);
			d->use++;
		}
	}
	return ;
}

size_t	rotate_mount_a(t_situation *s, t_dividing *d)
{
	size_t	i;
	size_t	pi;
	size_t	ri;

	i = s->a.len;
	pi = 0;
	ri = 0;
	while(pi < d->mut && i)
	{
		if (getn(&s->a, i - 1, DEAL) >= d->num)
			ri++;
		else
			pi++;
		i--;
	}
	if (getn(&s->a, i + 1, DEAL) >= d->num && ri)
		ri--;
	return (ri);
}

size_t	rotate_mount_b(t_situation *s, t_dividing *d)
{
	size_t	i;
	size_t	pi;
	size_t	ri;

	i = s->b.len;
	pi = 0;
	ri = 0;
	while(pi < d->mut + d->inc && i)
	{
		if (getn(&s->a, i - 1, DEAL) < d->num)
			ri++;
		else
			pi++;
		i--;
	}
	if (getn(&s->a, i + 1, DEAL) < d->num && ri)
		ri--;
	return (ri);
}
