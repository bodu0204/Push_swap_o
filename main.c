#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	s;


	ft_bzero(&s, sizeof(t_stack));
	if (mkenv(argc, argv, &s))
	{
		free(s.freefrom);
		return (1);
	}
	if (push_swap(&s, _a_first))
	{
		free(s.freefrom);
		return (1);
	}
	return (0);
}

void	mkgoal(int	*nums, int	len)
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
