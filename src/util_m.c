#include "push_swap.h"

int isover(char *s)
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
		return (ft_strncmp(s, "2147483647", 10) > 0);
	return (ft_strncmp(s, "2147483648", 10) > 0);
}

int isdup(size_t argc, char *argv[])
{
	size_t	i;
	size_t	ii;

	i = 1;
	while (i < argc)
	{
		ii = i + 1;
		while (ii < argc)
		{
			if (!ft_strncmp(argv[i], argv[ii], ft_strlen(argv[i])))
				return (1);
			ii++;
		}
		i++;
	}
	return (0);

}
