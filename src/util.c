/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 08:35:25 by ryoakira          #+#    #+#             */
/*   Updated: 2022/04/29 17:46:14 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_mplh *h)
{
	t_mplc	*m;
	t_mplc	*n;

	free(h->freefrom);
	m = h->cnt;
	while (m)
	{
		n = m->next;
		free(m);
		m = n;
	}
	h->cnt = NULL;
	h->sc = NULL;
	h->freefrom = NULL;
	return ;
}

size_t	splitlen(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	freesplit(char **s)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (*(s + i))
	{
		free(*(s + i));
		i++;
	}
	free(s);
	return ;
}
