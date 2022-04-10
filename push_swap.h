#include <unistd.h>
#include <stdlib.h>
# define BUFFER 32
# define fd 1

enum
{
	_a,
	_b,
};

enum
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
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
	size_t	use;
}	t_dividing;

int		manipulate(t_stack	*s, int cmd);
int		pop_push(int *pops, size_t *pol, int *pushs, size_t *pul);
void	*ft_memmove(void	*dest, const void	*src, size_t	n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
