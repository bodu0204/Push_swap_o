/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 08:34:16 by ryoakira          #+#    #+#             */
/*   Updated: 2022/04/26 08:34:17 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	operation(int cmd, t_situ *s);
void	operation1(int cmd, t_situ *s);

void	manipulate(int cmd, t_situ *s, t_mplh *h)
{
	t_mplc	*new;
	t_mplc	*m;

	new = malloc(sizeof(t_mplc));
	if (!new)
	{
		free_all(h);
		write(STDOUT_FILENO, "malloc Error\n", 13);
		exit(1);
	}
	m = h->sc;
	if (!h->cnt)
		h->cnt = new;
	else
		m->next = new;
	h->sc = new;
	new->mpl = cmd;
	operation(cmd, s);
	return ;
}

void	operation(int cmd, t_situ *s)
{
	if (cmd == sa)
		swap(&s->a);
	else if (cmd == sb)
		swap(&s->b);
	else if (cmd == ss)
	{
		swap(&s->a);
		swap(&s->b);
	}
	else if (cmd == pa)
		push(&s->b, &s->a);
	else if (cmd == pb)
		push(&s->a, &s->b);
	else if (cmd == ra)
		rotate(&s->a);
	else if (cmd == rb)
		rotate(&s->b);
	else if (cmd == rr)
	{
		rotate(&s->a);
		rotate(&s->b);
	}
	else
		operation1(cmd, s);
	return ;
}

void	operation1(int cmd, t_situ *s)
{
	if (cmd == rra)
		revrotate(&s->a);
	else if (cmd == rrb)
		revrotate(&s->b);
	else
	{
		revrotate(&s->a);
		revrotate(&s->b);
	}
	return ;
}
