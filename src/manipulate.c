/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 05:20:37 by ryoakira          #+#    #+#             */
/*   Updated: 2022/04/21 05:20:38 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	manipulate1(t_stack	*s, int cmd);
int	manipulate2(t_stack	*s, int cmd);
int	manipulate3(t_stack	*s, int cmd);
int	manipulate4(t_stack	*s, int cmd);
void tests(t_stack *s);

int	manipulate(t_stack	*s, int cmd)
{
	int	i;

	if (cmd == sa)
	{
		i = s->a[s->a_len - 1];
		s->a[s->a_len - 1] = s->a[s->a_len - 2];
		s->a[s->a_len - 2] = i;
		if (write(STDOUT_FILENO, "sa\n", 3) < 0)
			return (1);
	}
	else if (cmd == sb)
	{
		i = s->b[s->b_len - 1];
		s->b[s->b_len - 1] = s->b[s->b_len - 2];
		s->b[s->b_len - 2] = i;
		if (write(STDOUT_FILENO, "sb\n", 3) < 0)
			return (1);
	}
	else
	{
		if (manipulate1(s, cmd))
			return (1);
	}
	return (0);
}

int	manipulate1(t_stack	*s, int cmd)
{
	int	i;

	if (cmd == ss)
	{
		i = s->a[s->a_len - 1];
		s->a[s->a_len - 1] = s->a[s->a_len - 2];
		s->a[s->a_len - 2] = i;
		i = s->b[s->b_len - 1];
		s->b[s->b_len - 1] = s->b[s->b_len - 2];
		s->b[s->b_len - 2] = i;
		if (write(STDOUT_FILENO, "ss\n", 3) < 0)
			return (1);
	}
	else if (cmd == pa)
	{
		pop_push(s->b, &s->b_len, s->a, &s->a_len);
		if (write(STDOUT_FILENO, "pa\n", 3) < 0)
			return (1);
	}
	else
	{
		if (manipulate2(s, cmd))
			return (1);
	}
	return (0);
}

int	manipulate2(t_stack	*s, int cmd)
{
	if (cmd == pb)
	{
		pop_push(s->a, &s->a_len, s->b, &s->b_len);
		if (write(STDOUT_FILENO, "pb\n", 3) < 0)
			return (1);
	}
	else if (cmd == ra)
	{
		pop_push(s->a, &s->a_len, s->a_back, &s->a_back_len);
		if (write(STDOUT_FILENO, "ra\n", 3) < 0)
			return (1);
	}
	else if (cmd == rb)
	{
		pop_push(s->b, &s->b_len, s->b_back, &s->b_back_len);
		if (write(STDOUT_FILENO, "rb\n", 3) < 0)
			return (1);
	}
	else
	{
		if (manipulate3(s, cmd))
			return (1);
	}
	return (0);
}

int	manipulate3(t_stack	*s, int cmd)
{
	if (cmd == rr)
	{
		pop_push(s->a, &s->a_len, s->a_back, &s->a_back_len);
		pop_push(s->b, &s->b_len, s->b_back, &s->b_back_len);
		if (write(STDOUT_FILENO, "rr\n", 3) < 0)
			return (1);
	}
	else if (cmd == rra)
	{
		pop_push(s->a_back, &s->a_back_len, s->a, &s->a_len);
		if (write(STDOUT_FILENO, "rra\n", 4) < 0)
			return (1);
	}
	else if (cmd == rrb)
	{
		pop_push(s->b_back, &s->b_back_len, s->b, &s->b_len);
		if (write(STDOUT_FILENO, "rrb\n", 4) < 0)
			return (1);
	}
	else
	{
		if (manipulate4(s, cmd))
			return (1);
	}
	return (0);
}

int	manipulate4(t_stack	*s, int cmd)
{
	if (cmd == rrr)
	{
		pop_push(s->a_back, &s->a_back_len, s->a, &s->a_len);
		pop_push(s->b_back, &s->b_back_len, s->b, &s->b_len);
		if (write(STDOUT_FILENO, "rrr\n", 4) < 0)
			return (1);
	}
	else
		return (1);
	return (0);
}
