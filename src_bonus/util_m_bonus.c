/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_m_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 05:20:18 by ryoakira          #+#    #+#             */
/*   Updated: 2022/04/30 11:00:57 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	isover(char *s)
{
	int		i;
	size_t	len;

	i = 0;
	if (*s == '-')
	{
		s++;
		i = 1;
	}
	len = ft_strlen(s);
	if (len < 10)
		return (0);
	if (len > 11)
		return (1);
	if (!i)
		return (ft_strncmp(s, "2147483647", 11) > 0);
	return (ft_strncmp(s, "2147483648", 11) > 0);
}

int	isdup(size_t argc, char *argv[])
{
	size_t	i;
	size_t	ii;
	size_t	l;
	size_t	ll;

	i = 0;
	while (i < argc)
	{
		ii = i + 1;
		l = ft_strlen(argv[i]);
		while (ii < argc)
		{
			ll = ft_strlen(argv[ii]);
			if (l > ll)
				ll = l;
			if (!ft_strncmp(argv[i], argv[ii], ll))
				return (1);
			ii++;
		}
		i++;
	}
	return (0);
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

int	checkarg(size_t argc, char *argv[])
{
	size_t	i;
	size_t	ii;
	char	*s;

	i = 0;
	while (i < argc)
	{
		s = argv[i];
		ii = 0;
		if (!*s)
			return (1);
		while (s[ii])
		{
			if (!((s[ii] >= '0' && s[ii] <= '9') || (s[ii] == '-' && !ii)))
				return (1);
			ii++;
		}
		if (isover(s))
			return (1);
		i++;
	}
	return (isdup(argc, argv));
}
