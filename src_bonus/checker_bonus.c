/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 05:19:35 by ryoakira          #+#    #+#             */
/*   Updated: 2022/04/30 07:13:12 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
char	*get_order(size_t	len);

int	checker(t_checker *s)
{
	char	*order;
	size_t	olen;
	int		ko;

	olen = 0;
	ko = check(s);
	order = get_order(0);
	if (!order)
		return (1);
	while (order[olen] && (ko != -1))
		olen += manipulate(s, order + olen, &ko);
	free(order);
	if (ko == -1)
		return (1);
	else if (ko)
		write(STDOUT_FILENO, "KO\n", 3);
	else
		write(STDOUT_FILENO, "OK\n", 3);
	return (0);
}

char	*get_order(size_t	len)
{
	size_t	new;
	char	buf[BUFFER];
	char	*ret;

	new = read(STDIN_FILENO, buf, BUFFER);
	if (new)
		ret = get_order(len + new);
	else
	{
		ret = malloc(len + new + 1);
		if (ret)
			ret[len + new] = '\0';
	}
	if (ret)
		ft_memcpy(ret + len, buf, new);
	return (ret);
}
