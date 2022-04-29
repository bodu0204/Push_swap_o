/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   omitmplA.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 08:34:30 by ryoakira          #+#    #+#             */
/*   Updated: 2022/04/30 07:45:51 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "debug.h"/* test */
t_mplc	*omitmpl1(t_mplc	*one, t_mplc	*two, int *flag);
t_mplc	*omitmpl2(t_mplc	*one, t_mplc	*two, int *flag);
t_mplc	*omitmpl3(t_mplc	*one, t_mplc	*two, int *flag);
t_mplc	*omitmpl4(t_mplc	*one, t_mplc	*two, int *flag);
t_mplc	*omitmpl5(t_mplc	*one, t_mplc	*two, int *flag);

t_mplc	*omitmpl(t_mplc	*one, int *flag)
{
TEST_
TESTn("one->mpl",one->mpl)
TESTn("one->next",one->next)
	t_mplc	*two;

	if (!one)
		return (NULL);
	two = one->next;
	if (!two)
		return (one);
	if ((one->mpl == sa && two->mpl == sb) \
	|| (one->mpl == sb && two->mpl == sa))
	{
TEST
		*flag = 1;
		two->mpl = ss;
		free(one);
		return (two);
	}
	else if ((one->mpl == ra && two->mpl == rb) \
	|| (one->mpl == rb && two->mpl == ra))
	{
TEST
		*flag = 1;
		two->mpl = rr;
		free(one);
		return (two);
	}
	else
		return (omitmpl1(one, two, flag));
}

t_mplc	*omitmpl1(t_mplc	*one, t_mplc	*two, int *flag)
{
	if ((one->mpl == rra && two->mpl == rrb) \
	|| (one->mpl == rrb && two->mpl == rra))
	{
TEST
		*flag = 1;
		two->mpl = rrr;
		free(one);
		return (two);
	}
	else if ((one->mpl == ss && two->mpl == sa) \
	|| (one->mpl == sa && two->mpl == ss))
	{
TEST
		*flag = 1;
		two->mpl = sb;
		free(one);
		return (two);
	}
	else
		return (omitmpl2(one, two, flag));
}

t_mplc	*omitmpl2(t_mplc	*one, t_mplc	*two, int *flag)

{
	if ((one->mpl == ss && two->mpl == sb) \
	|| (one->mpl == sb && two->mpl == ss))
	{
TEST
		*flag = 1;
		two->mpl = sa;
		free(one);
		return (two);
	}
	else if ((one->mpl == rr && two->mpl == rra) \
	|| (one->mpl == rra && two->mpl == rr))
	{
TEST
		*flag = 1;
		two->mpl = rb;
		free(one);
		return (two);
	}
	else
		return (omitmpl3(one, two, flag));
}

t_mplc	*omitmpl3(t_mplc	*one, t_mplc	*two, int *flag)
{
	if ((one->mpl == rr && two->mpl == rrb) \
	|| (one->mpl == rrb && two->mpl == rr))
	{
TEST
		*flag = 1;
		two->mpl = ra;
		free(one);
		return (two);
	}
	else if ((one->mpl == rrr && two->mpl == rb) \
	|| (one->mpl == rb && two->mpl == rrr))
	{
TEST
		*flag = 1;
		two->mpl = rra;
		free(one);
		return (two);
	}
	else
		return (omitmpl4(one, two, flag));
}

t_mplc	*omitmpl4(t_mplc	*one, t_mplc	*two, int *flag)
{
	if ((one->mpl == rrr && two->mpl == ra) \
	|| (one->mpl == ra && two->mpl == rrr))
	{
TEST
		*flag = 1;
		two->mpl = rrb;
		free(one);
		return (two);
	}
	else
		return (omitmpl5(one, two, flag));
}
