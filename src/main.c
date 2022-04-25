
#include "push_swap.h"
//#include "debug.h" //test
int		mkenv(int argc, char *argv[], t_situation *s, t_mplh *h);
void	mkgoal(int	*nums, size_t	len);
int		set_stack(int argc, char *argv[], t_situation *s, t_mplh *h);
int		checkarg(size_t argc, char *argv[]);

int	main(int argc, char *argv[])
{
	t_situation	s;
	t_mplh		h;
	char		*op;
	int			r;

	if (argc == 1 || checkarg(argc, argv))
	{
		write(STDOUT_FILENO, "Error\n", 6);
		return (1);
	}
	if (mkenv(argc, argv, &s, &h))
	{
		write(STDOUT_FILENO, "Error\n", 6);
		return (1);
	}
//TESTp("s.img", s.a.img)
//TESTp("s.img", s.b.img)
//TESTp("s.img", s.g.img)
	push_swap(&s, &h, _a);
	op = mkout(&h);//確保できなかった時はexit
	free_all(&h);
	r = write(STDOUT_FILENO, op, ft_strlen(op));
	free(op);
	return (r < 0);
}

int	mkenv(int argc, char *argv[], t_situation *s, t_mplh *h)
{
	ft_bzero(s, sizeof(t_situation));
	ft_bzero(h, sizeof(t_mplh));
	if (set_stack(argc - 1, argv + 1, s, h))
		return (1);
	mkgoal(s->g.phs, argc);
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

int	set_stack(int argc, char *argv[], t_situation *s, t_mplh *h)
{
	int	i;

	h->freefrom = malloc(((argc * sizeof(int)) + sizeof(size_t)) * 3);
	if (!h->freefrom)
		return (1);
	s->a.phs = h->freefrom;
	s->a.img = (void *)s->a.phs + (argc * sizeof(int));
	s->b.phs = (void *)s->a.img + sizeof(size_t);
	s->b.img = (void *)s->b.phs + (argc * sizeof(int));
	s->g.phs = (void *)s->b.img + sizeof(size_t);
	s->g.img = (void *)s->g.phs + (argc * sizeof(int));
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
	s->exp = 1; //使わない
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
