#include <unistd.h>
#include <stdlib.h>
# define BUFFER 32

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

typedef struct s_checker
{
	int		*a;
	int		*b;
	size_t	a_base;
	size_t	a_len;
	size_t	b_base;
	size_t	b_len;
	size_t	buf_len;
	void	*freefrom;
}	t_checker;
int	ft_atoi(const char	*str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int	ft_memcmp(const void	*s1, const void	*s2, size_t	n);

