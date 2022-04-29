/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 08:34:10 by ryoakira          #+#    #+#             */
/*   Updated: 2022/04/30 07:25:09 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "debug.h"/* test */
void	befor_push_swap(int argc, char *argv[], t_situ *s, t_mplh *h);
int		treat_arg(int *argc, char **argv[]);
int		mkenv(int argc, char *argv[], t_situ *s, t_mplh *h);
void	mkgoal(int	*nums, size_t	len);
int		set_stack(int argc, char *argv[], t_situ *s, t_mplh *h);
int		checkarg(size_t argc, char *argv[]);

int	main(int argc, char *argv[])
{
	t_situ	s;
	t_mplh	h;
	char	*op;
	int		r;

	befor_push_swap(argc, argv, &s, &h);
tests(&s);
	push_swap(&s, &h, _a);
	op = mkout(&h);
	free_all(&h);
	r = write(STDOUT_FILENO, op, ft_strlen(op));
	free(op);
	return (r < 0);
}

void	befor_push_swap(int argc, char *argv[], t_situ *s, t_mplh *h)
{
	int r;

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
TEST
	return ;
}

int treat_arg(int *argc, char **argv[])
{
TEST_
	int r;

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
		*argc =splitlen((*argv));
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
TEST_
	ft_bzero(s, sizeof(t_situ));
	ft_bzero(h, sizeof(t_mplh));
	if (set_stack(argc, argv, s, h))
		return (1);
	mkgoal(s->g.phs, argc);
	return (0);
}

void	mkgoal(int	*nums, size_t	len)
{
TEST_
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
TEST_
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

int	checkarg(size_t argc, char *argv[])
{
TEST_
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
