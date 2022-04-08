#include <unistd.h>
#include <stdlib.h>
# define BUFFER 32
# define fd 1

enum
{
	_a,
	_b,
};


typedef struct s_stack
{
	int		*a_base;
	int		*b_base;
	int		*a;
	size_t	a_len;
	int		*b;
	size_t	b_len;
	int		*g;
	size_t	g_len;
	int		*a_back;
	size_t	a_back_len;
	int		*b_back;
	size_t	b_back_len;
	void	*freefrom;
}	t_stack;

typedef struct s_dividing
{
	int		dn;
	size_t	for_a;
	size_t	for_b;
	size_t	dm;
	size_t	inc;
}	t_dividing;

void	ft_bzero(void *s, size_t n);
