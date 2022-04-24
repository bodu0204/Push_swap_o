  #ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

enum
{
	_a,
	_b,
	_none
};

enum
{
	TOP,
	DEAL,
	GIRD,
	UNDER,
	BOTTOM,
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
	struct s_manipulate_content	*cnt;
	struct s_manipulate_content	*sc;
	void						*freefrom;/* free以外いじらない */
}	t_mplh;

typedef struct s_manipulate_content
{
	int							mpl;
	struct s_manipulate_content	*next;
}	t_mplc;

int		isover(char *s);
int		isdup(size_t argc, char *argv[]);

void	push_swap(t_situation	*s, t_mplh *h, int ms);

void	rase(t_situation	*s);
void	set_divide_fmt(t_dividing *d, t_stack *g, int flag);
void	treatstack(t_situation	*s, t_mplh *h);
void	set_next_stack(t_situation	*s, t_situation	*next, int ms);

void	manipulate(int cmd, t_stack *s, t_mplh *h);

char	*mkout(t_mplh *h)

t_mplc	*omitmpl(t_mplc	*one, int *flag);

void	push(t_stack *o, t_stack *u);
void	swap(t_stack *s);
void	rotate(t_stack *s);
void	revrotate(t_stack *s);
int		getn(t_stack *s, size_t l, int flag);

void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif


//ショートカット

/*


t_stack *s

t_situation	*s

t_mplh *h

t_mplc	*m;


manipulate(, s, h);


{printf("found error");TEST exit(2);}


	{
		free_all(h);
		write(STDOUT_FILENO, "malloc Error\n", 13);
		exit(1);
	}


 */
