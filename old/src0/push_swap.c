/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 05:20:49 by ryoakira          #+#    #+#             */
/*   Updated: 2022/04/26 06:50:11 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	push_swap1(t_stack	*s);

int	push_swap(t_stack	*s, int ms)
{
	t_divid	d;

	if (little_push_swap(s))
		return (1);
	if (!s->a_len && !s->b_len)
		return (0);
	set_divide_fmt(&d, s->g, s->g_len);
	if (divide(s, &d, ms))
		return (1);
	if (treatstack(s, ms))
		return (1);
	if (s->a_len <= 2)
	{
		if (swaptwo(s, &d))
			return (1);
		if (!s->b_len)
			return (0);
	}
	return (push_swap1(s));
}

int	push_swap1(t_stack	*s)
{
	t_stack		next;

	set_next_stack(s, &next, _a);
	if (s->a_len)
		if (push_swap(&next, _a))
			return (1);
	set_next_stack(s, &next, _b);
	if (s->b_len)
		if (push_swap(&next, _b))
			return (1);
	return (0);
}
