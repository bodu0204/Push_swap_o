#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
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
	size_t	ma;
	size_t	mb;
	size_t	use;
}	t_dividing;

void	*ft_memmove(void	*dest, const void	*src, size_t	n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char	*str);

int		push_swap(t_stack	*s, int ms);

void	set_divide_fmt(t_dividing	*d, int	*goal, size_t	l);
int		treatstack(t_stack	*s, int ms);
void	set_next_stack(t_stack *s, t_stack *next, t_dividing *d, int ms);
int		swaptwo(t_stack *s, t_dividing *d);
int		little_push_swap(t_stack *s);

int		divide(t_stack	*s, t_dividing *d, int ms);

int		manipulate(t_stack	*s, int cmd);

void	pop_push(int *pops, size_t *pol, int *pushs, size_t *pul);
int		rotate(t_stack *s, int *flag, int ms);
void	raise_a(t_stack *s);
void	mvstack(int *mst, size_t *msl, int *bst, size_t *bsl);
#endif
