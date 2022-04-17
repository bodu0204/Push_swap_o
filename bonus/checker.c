#include "checker.h"
#include "debug.h"/* test */
char	*get_order(size_t	len);
int		manipulate(t_checker	*s, char *order, int *ko);

int checker (t_checker *s)
{
	char	*order;
	size_t	olen;
	int		ko;

	olen = 0;
	ko = 0;
	order = get_order(0);
TEST
printf("%s", order); fflush(stdout);
	if (!order)
		return(1);
	while (order[olen] && (ko != -1))
		olen += manipulate(s, order + olen , &ko);
	free(order);
TESTn(ko)
	if (ko == -1)
		return (1);
	else if (ko)
		write(STDOUT_FILENO, "KO\n", 3);
	else
		write(STDOUT_FILENO, "0K\n", 3);
	return (0);
}

char	*get_order(size_t	len)
{
	size_t	new;
	char	buf[BUFFER];
	char	*ret;

	new = read(STDIN_FILENO, buf, BUFFER);
	if (new == BUFFER)
		ret = get_order(len + BUFFER);
	else
	{
		ret = malloc(len + new + 1);
		if (ret)
			ret[len + new] = '\0';
	}
	if (ret)
		ft_memcpy(ret + len, buf, new);
	return (ret);
}

int check(t_checker *s)
{
	size_t	i;

	if (!s->b_len)
	{
		i = 1;
		while(i < s->a_len && \
		s->a[(s->a_base + i - 1) % s->buf_len] >= s->a[(s->a_base + i) % s->buf_len])
			i++;
		if (i == s->a_len)
			return (0);
	}
	return (1);
}