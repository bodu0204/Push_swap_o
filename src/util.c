#include "push_swap.h"
#include "debug.h" //test

void	free_all(t_mplh *h)
{
	t_mplc	*m;
	t_mplc	*n;

	free(h->freefrom);
	m = h->cnt;
	while (m)
	{
		n = m->next;
		free(m);
		m = n;
	}
	h->cnt = NULL;
	h->sc = NULL;
	h->freefrom = NULL;
	return ;
}
