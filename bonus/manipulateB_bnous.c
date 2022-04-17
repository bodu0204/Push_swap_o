#include "checker.h"
#include "debug.h"/* test */
int	manipulate5(t_checker	*s, char *order, int *ko);
int	manipulate6(t_checker	*s, char *order, int *ko);
int	check(t_checker *s);
void tests(t_checker *s);/* test */

int	manipulate4(t_checker	*s, char *order, int *ko)
{
	int	i;

	if (!ft_memcmp(order, "rrb\n", 4))
	{
		if (s->b_len)
		{
			i = s->b[s->b_base];
			s->b_base = (s->b_base + 1) % s->buf_len;
			s->b[(s->b_base + s->b_len + (s->buf_len - 1)) % s->buf_len] = i;
		}
		*ko = check(s);
tests(s); TESTn(*ko)
		return (4);
	}
	return (manipulate5(s, order, ko));
}

int	manipulate5(t_checker	*s, char *order, int *ko)
{
	int	i;

	if (!ft_memcmp(order, "pa\n", 3))
	{
		if (s->b_len)
		{
			i = s->b[(s->b_base + s->b_len + (s->buf_len - 1)) % s->buf_len];
			s->a[(s->a_base + s->a_len) % s->buf_len] = i;
			s->a_len++;
			s->b_len--;
		}
		*ko = check(s);
tests(s); TESTn(*ko)
		return (3);
	}
	return (manipulate6(s, order, ko));
}

int	manipulate6(t_checker	*s, char *order, int *ko)
{
	int	i;

	if (!ft_memcmp(order, "pb\n", 3))
	{
		if (s->a_len)
		{
			i = s->a[(s->a_base + s->a_len + (s->buf_len - 1)) % s->buf_len];
			s->b[(s->b_base + s->b_len) % s->buf_len] = i;
			s->b_len++;
			s->a_len--;
		}
		*ko = check(s);
tests(s); TESTn(*ko)
		return (3);
	}
	*ko = -1;
tests(s); TESTn(*ko)
	return (0);
}
