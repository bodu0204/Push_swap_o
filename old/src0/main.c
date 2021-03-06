/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 05:20:33 by ryoakira          #+#    #+#             */
/*   Updated: 2022/04/21 05:20:34 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int		mkenv(int argc, char *argv[], t_stack *s);
void	mkgoal(int	*nums, size_t	len);
int		set_stack(int argc, char *argv[], t_stack *s);
int		checkarg(size_t argc, char *argv[]);
int		isover(char *s);
int		isdup(size_t argc, char *argv[]);

int	main(int argc, char *argv[])
{
	t_stack	s;
	int		r;

	if (argc == 1 || checkarg(argc, argv))
	{
		write(STDOUT_FILENO, "Error\n", 6);
		return (1);
	}
	ft_bzero(&s, sizeof(t_stack));
	if (mkenv(argc, argv, &s))
	{
		write(STDOUT_FILENO, "Error\n", 6);
		free(s.freefrom);
		return (1);
	}
	r = push_swap(&s, _a);
	free(s.freefrom);
	if (r)
		return (1);
	return (0);
}

int	mkenv(int argc, char *argv[], t_stack *s)
{
	if (set_stack(argc - 1, argv + 1, s))
		return (1);
	mkgoal(s->g, s->g_len);
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

int	set_stack(int argc, char *argv[], t_stack *s)
{
	int	i;

	ft_bzero(s, sizeof(t_stack));
	s->freefrom = malloc(((argc * sizeof(int)) + 8) * 5);
	if (!s->freefrom)
		return (1);
	s->a_base = s->freefrom;
	s->b_base = s->freefrom + ((argc * sizeof(int)) + 8);
	s->a_back = s->freefrom + (((argc * sizeof(int)) + 8) * 2);
	s->b_back = s->freefrom + (((argc * sizeof(int)) + 8) * 3);
	s->g = s->freefrom + (((argc * sizeof(int)) + 8) * 4);
	i = 0;
	while (i < argc)
	{
		s->g[i] = ft_atoi(argv[argc - i - 1]);
		i++;
	}
	ft_memcpy(s->a_base, s->g, (argc * sizeof(int)));
	s->a = s->a_base;
	s->b = s->b_base;
	s->g_len = argc;
	s->a_len = argc;
	return (0);
}

int	checkarg(size_t argc, char *argv[])
{
	size_t	i;
	size_t	ii;
	char	*s;

	i = 1;
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
