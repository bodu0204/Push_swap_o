#include "checker.h"

int checker (t_checker *s)
{
	char	*order;
	size_t	olen;
	int		ko;

	olen = 0;
	ko = 0;
	order = get_order(0);
	if (!order)
		return(1);
	while (!order[olen] && ko != -1)
		olen += manipulate(s, order + olen , &ko);
	free(order);
	if (ko == -1)
		return (1);
	else if (ko)
		write(STDOUT_FILENO, "KO\n", 3);
	else
		write(STDOUT_FILENO, "0K\n", 3);
	return (0);
}

char	*update_order(char *old)
{
	char	*new;


}
