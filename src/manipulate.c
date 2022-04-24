#include "push_swap.h"
#include "debug.h" //test
void	operation(int cmd, t_situation *s);
void	operation1(int cmd, t_situation *s);

void manipulate(int cmd, t_situation *s, t_mplh *h)
{
	t_mplc	*new;
	t_mplc	*m;

	new = malloc(sizeof(t_mplc));
	if (!new)
	{
		free_all(h);
		write(STDOUT_FILENO, "malloc Error\n", 13);
		exit(1);
	}
	m = h->sc;
	if (!h->cnt)
		h->cnt = new;
	else
		m->next = new;
	h->sc = new;
	new->mpl = cmd;
TESTn(cmd,cmd)
	operation(cmd, s);
TEST
	return ;
}

void	operation(int cmd, t_situation *s)
{
	if (cmd == sa)
		swap(&s->a);
	else if (cmd == sb)
		swap(&s->b);
	else if (cmd == ss)
	{
		swap(&s->a);
		swap(&s->b);
	}
	else if (cmd == pa)
		push(&s->b, &s->a);
	else if (cmd == pb)
		push(&s->a, &s->b);
	else if (cmd == ra)
		rotate(&s->a);
	else if (cmd == rb)
		rotate(&s->b);
	else if (cmd == rr)
	{
		rotate(&s->a);
		rotate(&s->b);
	}
	else
		operation1(cmd, s);
	return ;
}

void	operation1(int cmd, t_situation *s)
{
	if (cmd == rra)
		revrotate(&s->a);
	else if (cmd == rrb)
		revrotate(&s->b);
	else                                         if (cmd == rrr)
	{
		revrotate(&s->a);
		revrotate(&s->b);
	}
else
{printf("found error");TEST exit(2);}
	return ;
}
