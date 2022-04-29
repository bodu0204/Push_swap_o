/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 05:20:01 by ryoakira          #+#    #+#             */
/*   Updated: 2022/04/29 18:35:38 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
int		mkenv(int argc, char *argv[], t_checker *s);
void	mkgoal(int	*nums, size_t	len);
int		set_stack(int argc, char *argv[], t_checker *s);
int		checkarg(size_t argc, char *argv[]);
int		isover(char *s);
int		isdup(size_t argc, char *argv[]);

int	main(int argc, char *argv[])
{
	t_checker	s;

	if (checkarg(argc, argv))
	{
		write(STDOUT_FILENO, "Error\n", 6);
		return (1);
	}
	if (mkenv(argc, argv, &s))
	{
		write(STDOUT_FILENO, "Error\n", 6);
		free(s.freefrom);
		return (1);
	}
	if (checker(&s))
		write(STDOUT_FILENO, "Error\n", 6);
	free(s.freefrom);
	return (0);
}

int	mkenv(int argc, char *argv[], t_checker *s)
{
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (1);
		if (set_stack(splitlen(argv), argv, s))
		{
			freesplit(argv);
			return (1);
		}
		freesplit(argv);
	}
	else
	{
		if (set_stack(argc - 1, argv + 1, s))
			return (1);
	}
	return (0);
}

int	set_stack(int argc, char *argv[], t_checker *s)
{
	int	i;

	ft_bzero(s, sizeof(t_checker));
	s->freefrom = malloc(((argc * sizeof(int)) + 8) * 2);
	if (!s->freefrom)
		return (1);
	s->a = s->freefrom;
	s->b = s->freefrom + ((argc * sizeof(int)) + 8);
	i = 0;
	while (i < argc)
	{
		s->a[i] = ft_atoi(argv[argc - i - 1]);
		i++;
	}
	s->buf_len = argc;
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
