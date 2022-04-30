/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_m.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 08:35:12 by ryoakira          #+#    #+#             */
/*   Updated: 2022/04/30 10:51:03 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	mkgoal(int	*nums, size_t	len)
{
	size_t	i;
	size_t	ii;
	size_t	max;
	int		buf;

	i = 0;
	while (i < len)
	{
		max = i;
		ii = i;
		while (ii < len)
		{
			if (nums[ii] > nums[max])
				max = ii;
			ii++;
		}
		buf = nums[i];
		nums[i] = nums[max];
		nums[max] = buf;
		i++;
	}
	return ;
}

int	set_stack(int argc, char *argv[], t_situ *s, t_mplh *h)
{
	int	i;

	h->freefrom = ft_calloc((argc * sizeof(int)) + sizeof(size_t) + 16, 3);
	if (!h->freefrom)
		return (1);
	s->a.phs = h->freefrom;
	s->a.img = (void *)s->a.phs + (argc * sizeof(int)) + 8;
	s->b.phs = (void *)s->a.img + sizeof(size_t) + 8;
	s->b.img = (void *)s->b.phs + (argc * sizeof(int)) + 8;
	s->g.phs = (void *)s->b.img + sizeof(size_t) + 8;
	s->g.img = (void *)s->g.phs + (argc * sizeof(int)) + 8;
	i = 0;
	while (i < argc)
	{
		s->g.phs[i] = ft_atoi(argv[argc - i - 1]);
		i++;
	}
	ft_memcpy(s->a.phs, s->g.phs, (argc * sizeof(int)));
	s->g.len = argc;
	s->a.len = argc;
	s->g.phl = argc;
	s->a.phl = argc;
	s->b.phl = argc;
	return (0);
}
