/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 05:20:01 by ryoakira          #+#    #+#             */
/*   Updated: 2022/04/30 11:01:09 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
int		mkenv(int argc, char *argv[], t_checker *s);
void	mkgoal(int	*nums, size_t	len);
int		set_stack(int argc, char *argv[], t_checker *s);
int		isover(char *s);
int		isdup(size_t argc, char *argv[]);
void	befor_check(int argc, char *argv[], t_checker *s);
int		treat_arg(int *argc, char **argv[]);

int	main(int argc, char *argv[])
{
	t_checker	s;

	befor_check(argc, argv, &s);
	if (checker(&s))
		write(STDOUT_FILENO, "Error\n", 6);
	free(s.freefrom);
	return (0);
}

void	befor_check(int argc, char *argv[], t_checker *s)
{
	int	r;

	r = treat_arg(&argc, &argv);
	if (checkarg(argc, argv))
	{
		if (r)
			freesplit(argv);
		write(STDOUT_FILENO, "Error\n", 6);
		exit (1);
	}
	if (mkenv(argc, argv, s))
	{
		if (r)
			freesplit(argv);
		write(STDOUT_FILENO, "Error\n", 6);
		free(s->freefrom);
		exit (1);
	}
	if (r)
		freesplit(argv);
	return ;
}

int	treat_arg(int *argc, char **argv[])
{
	int	r;

	r = 0;
	if (*argc == 2)
	{
		r = 1;
		*argv = ft_split((*argv)[1], ' ');
		if (!(*argv))
		{
			write(STDOUT_FILENO, "malloc Error\n", 13);
			exit(1);
		}
		*argc = splitlen((*argv));
	}
	else
	{
		(*argv)++;
		(*argc)--;
	}
	return (r);
}

int	mkenv(int argc, char *argv[], t_checker *s)
{
	if (set_stack(argc, argv, s))
		return (1);
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
