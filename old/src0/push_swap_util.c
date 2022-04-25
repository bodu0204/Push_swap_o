/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 05:20:43 by ryoakira          #+#    #+#             */
/*   Updated: 2022/04/26 06:50:11 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_divide_fmt(t_divid	*d, int	*goal, size_t	l)
{
	size_t	i;

	ft_bzero(d, sizeof(t_divid));
	i = (l / 2) + (l % 2) - 1;
	d->dn = goal[i];
	while (goal[i] == d->dn && i < l)
		i++;
	d->mb = l - i;
	d->ma = i;
	if (!d->mb)
	{
		i = 0;
		while (goal[i] > d->dn)
			i++;
		d->dn = goal[i - 1];
		d->mb = l - i;
		d->ma = i;
	}
	return ;
}

int	treatstack(t_stack	*s, int ms)
{
	if ((ms == _a && s->a == s->a_base) \
	|| (ms == _b && s->b == s->b_base))
	{
		mvstack(s->a_base, &s->a_len, s->a_back, &s->a_back_len);
		mvstack(s->b_base, &s->b_len, s->b_back, &s->b_back_len);
		raise_a(s);
		return (0);
	}
	while (s->a_back_len && s->b_back_len)
		if (manipulate(s, rrr))
			return (1);
	while (s->a_back_len)
		if (manipulate(s, rra))
			return (1);
	while (s->b_back_len)
		if (manipulate(s, rrb))
			return (1);
	raise_a(s);
	return (0);
}

void	set_next_stack(t_stack *s, t_stack *next, int ms)
{
	ft_memcpy(next, s, sizeof(t_stack));
	next->a_back_len = 0;
	next->b_back_len = 0;
	if (ms == _a)
	{
		next->g_len -= s->b_len;
		next->b += s->b_len;
		next->b_len = 0;
	}
	else
	{
		next->g += s->a_len;
		next->g_len -= s->a_len;
		next->a += s->a_len;
		next->a_len = 0;
	}
	return ;
}

int	swaptwo(t_stack *s, t_divid *d)
{
	if (s->a_len == 2 && (s->a[s->a_len - 1] > s->a[s->a_len - 2]) \
	&& (s->b_len == 2 && s->b[s->b_len - 1] < s->b[s->a_len - 2]))
	{
		if (manipulate(s, ss))
			return (1);
	}
	else if (s->a_len == 2 && s->a[s->a_len - 1] > s->a[s->a_len - 2])
	{
		if (manipulate(s, sa))
			return (1);
	}
	else if (s->b_len == 2 && s->b[s->b_len - 1] < s->b[s->b_len - 2])
	{
		if (manipulate(s, sb))
			return (1);
	}
	while (d->ma && s->b_len <= 2 && s->b_len)
		if (manipulate(s, pa))
			return (1);
	return (0);
}

int	little_push_swap(t_stack *s)
{
	raise_a(s);
	if (s->a_len && s->a_len <= 2)
	{
		if (s->a_len == 2)
		{
			if (manipulate(s, sa))
				return (1);
		}
		s->a += s->a_len;
		s->g += s->g_len;
		s->a_len = 0;
		s->g_len = 0;
	}
	return (0);
}
