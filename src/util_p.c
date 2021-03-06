/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 08:35:19 by ryoakira          #+#    #+#             */
/*   Updated: 2022/04/26 08:35:20 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	raise(t_situ	*s)
{
	while (s->a.len && getn(&s->a, 0, DEAL) == getn(&s->g, 0, DEAL))
	{
		s->a.grd++;
		s->g.grd++;
		s->a.len--;
		s->g.len--;
	}
	return ;
}

void	set_divide_fmt(t_divid *d, t_stack *g, int flag)
{
	size_t	i;

	d->mut = g->len / 2;
	d->inc = g->len % 2;
	d->num = getn(g, d->mut + d->inc - 1, DEAL);
	d->use = 0;
	if (flag == _none)
		return ;
	i = d->mut;
	if (flag == _a)
		i += d->inc;
	d->mut = i / 2;
	d->inc = i % 2;
	if (flag == _a)
		d->num = getn(g, d->mut + d->inc - 1, DEAL);
	else
		d->num = getn(g, i + d->mut + d->inc - 1, DEAL);
	return ;
}

void	treatstack(t_situ	*s, t_mplh *h)
{
	while (s->a.udr && s->b.udr)
		manipulate(rrr, s, h);
	while (s->a.udr)
		manipulate(rra, s, h);
	while (s->b.udr)
		manipulate(rrb, s, h);
	raise(s);
}

void	set_next_stack(t_situ	*s, t_situ	*next, int ms)
{
	ft_memcpy(next, s, sizeof(t_situ));
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
	return ;
}
