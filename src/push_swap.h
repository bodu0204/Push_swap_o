  #ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

enum
{
	_a,
	_b,
};

enum
{
	TOP,
	GIRD,
	UNDER,
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
	size_t	len;//length(+)
	size_t	grd; //guard(+)
	size_t	udr; //under(+)
	size_t	img; //imagin(+-)
	int		*phs;
	size_t	phl;
}	t_stack;

typedef struct s_situation
{
	struct s_stack	a;
	struct s_stack	b;
	struct s_stack	g;
	int				exp;
}	t_situation;

typedef struct s_dividing
{
	int		num;
	size_t	mut;
	size_t	inc;
	size_t	use;
}	t_dividing;

typedef struct s_manipulate_header
{
	int							flag;
	struct s_manipulate_content	*cnt;
	struct s_manipulate_content	*sc;
	void						*freefrom;/* free以外いじらない */
}	t_mplh;

typedef struct s_manipulate_content
{
	int							mpl;
	struct s_manipulate_content	*next;
}	t_mplc;

void push(t_stack *o, t_stack *u);
void swap(t_stack *s);
void rotate(t_stack *s);
void revrotate(t_stack *s);
int	getn(t_stack *s, size_t l, int flag);

#endif


//ショートカット

/*

#include "push_swap.h"
#include "debug.h" //test

t_stack *s

t_mplh *h

t_mplc	*m;

 */