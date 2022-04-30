/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 08:34:10 by ryoakira          #+#    #+#             */
/*   Updated: 2022/04/30 10:51:43 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	befor_push_swap(int argc, char *argv[], t_situ *s, t_mplh *h);
int		treat_arg(int *argc, char **argv[]);
int		mkenv(int argc, char *argv[], t_situ *s, t_mplh *h);
int		checkarg(size_t argc, char *argv[]);

int	main(int argc, char *argv[])
{
	t_situ	s;
	t_mplh	h;
	char	*op;
	int		r;

	befor_push_swap(argc, argv, &s, &h);
	push_swap(&s, &h, _a);
	op = mkout(&h);
	free_all(&h);
	r = write(STDOUT_FILENO, op, ft_strlen(op));
	free(op);
	return (r < 0);
}

void	befor_push_swap(int argc, char *argv[], t_situ *s, t_mplh *h)
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
	if (mkenv(argc, argv, s, h))
	{
		if (r)
			freesplit(argv);
		write(STDOUT_FILENO, "Error\n", 6);
		exit (1);
	}
	if (r)
		freesplit(argv);
	return ;
}

int	treat_arg(int *argc, char **argv[])
{
	int	r;

	if (*argc == 1)
		exit (0);
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

int	mkenv(int argc, char *argv[], t_situ *s, t_mplh *h)
{
	ft_bzero(s, sizeof(t_situ));
	ft_bzero(h, sizeof(t_mplh));
	if (set_stack(argc, argv, s, h))
		return (1);
	mkgoal(s->g.phs, argc);
	return (0);
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
