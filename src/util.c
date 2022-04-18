#include "push_swap.h"

void pop_push(int *pops, size_t *pol, int *pushs, size_t *pul)
{
	(*pol)--;
	pushs[*pul] = pops[*pol];
	(*pul)++;
}

void raise_a(t_stack *s)
{
	while (*(s->a) == *(s->g) && s->a_len)
	{
		s->a++;
		s->g++;
		s->g_len--;
		s->a_len--;
	}
	return ;
}

int rotate(t_stack *s, int *flag, int ms)
{
	if (*flag)
	{
		if(manipulate(s, rr))
			return (1);
	}
	else if (ms == _a)
	{
		if(manipulate(s, ra))
			return (1);
	}
	else if (ms == _b)
	{
		if(manipulate(s, rb))
			return (1);
	}
	else
		return (1);
	*flag = 0;
	return (0);
}

void	mvstack(int *mst, size_t *msl, int *bst, size_t *bsl)
{
	size_t	i;

	i = 0;
	ft_memmove(mst + *bsl, mst, *msl * sizeof(int));
	while (i < *bsl)
	{
		mst[*bsl - i - 1] = bst[i];
		i++;
	}
	*msl += *bsl;
	*bsl = 0;
	return ;
}

