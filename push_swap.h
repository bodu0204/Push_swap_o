#include <unistd.h>
#include <stdlib.h>
# define BUFFER 32

enum
{
	_a_first = -1,
	_a = 0,
	_b = 1,
};

typedef struct s_stack
{
	int		*a;
	size_t	a_len;
	int		*b;
	size_t	b_len;
	int		*goal;
	size_t	g_len;
	int		*ra_back;
	size_t	ra_len;
	int		*rb;
	size_t	rb_len;
	void	*freefrom;
}	t_stack;

void	ft_bzero(void *s, size_t n);
