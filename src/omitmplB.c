/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   omitmplB.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 08:34:37 by ryoakira          #+#    #+#             */
/*   Updated: 2022/04/30 07:57:33 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_mplc	*omitmpl5(t_mplc	*one, t_mplc	*two, int *flag)
{
	t_mplc	*rtn;

	if ((one->mpl == pa && two->mpl == pb) \
	|| (one->mpl == pb && two->mpl == pa) \
	|| (one->mpl == sa && two->mpl == sa) \
	|| (one->mpl == sb && two->mpl == sb) \
	|| (one->mpl == ss && two->mpl == ss) \
	|| (one->mpl == ra && two->mpl == rra) \
	|| (one->mpl == rra && two->mpl == ra) \
	|| (one->mpl == rb && two->mpl == rrb) \
	|| (one->mpl == rrb && two->mpl == rb) \
	|| (one->mpl == rr && two->mpl == rrr) \
	|| (one->mpl == rrr && two->mpl == rr))
	{
		*flag = 1;
		rtn = two->next;
		free(one);
		free(two);
		return (rtn);
	}
	else
		return (one);
}
