#include "push_swap.h"
#include "debug.h"/* test */

void push(t_stack *o, t_stack *u)
{
	int i;

if (!o->len)
{printf("found error");TEST exit(2);}
	o->len--;
	i = o->phs[(o->img + o->udr + o->grd + o->len) % o->phl];
	u->phs[(u->img + u->udr + u->grd + u->len) % u->phl] = i;
	u->len++;
if (u->udr + u->grd + u->len > u->phl)
{printf("found error");TEST exit(1);}
	return ;
}

void swap(t_stack *s)
{
	int i;
	int ii;

if (s->len < 2)
{printf("found error");TEST exit(2);}
	i = s->phs[(s->img + s->udr + s->grd + s->len - 1) % s->phl];
	ii = s->phs[(s->img + s->udr + s->grd + s->len - 2) % s->phl];
	s->phs[(s->img + s->udr + s->grd + s->len - 1) % s->phl] = ii;
	s->phs[(s->img + s->udr + s->grd + s->len - 2) % s->phl] = i;
	return ;
}

void rotate(t_stack *s)
{
	int i;

if (!s->len && s->grd)
{printf("found error");TEST exit(2);}
	i = s->phs[(s->img + s->udr + s->grd + s->len + s->phl - 1) % s->phl];
	s->img = (s->img + s->phl - 1) % s->phl;
	s->phs[s->img] = i;
	if (s->grd)
	{
		s->len--;
		s->udr++;
	}
	return ;
}

void revrotate(t_stack *s)
{
	int i;

if (!s->udr && s->grd)
{printf("found error");TEST exit(2);}
	i = s->phs[s->img];
	s->img = (s->img + 1) % s->phl;
	s->phs[(s->img + s->udr + s->grd + s->len) % s->phl] = i;
	if (s->grd)
	{
		s->udr--;
		s->len++;
	}
	return ;
}

int	getn(t_stack *s, size_t l, int flag)
{
TESTn("flag", flag)
TESTn("s->len + s->grd + s->udr", s->len + s->grd + s->udr)
TESTn("l", l)
	if (flag == TOP)
		l = s->img + s->udr + s->grd + s->len + s->phl - 1;
	else if (flag == DEAL)
		l += s->img + s->udr + s->grd;
	else if (flag == GIRD)
		l += s->img + s->udr;
	else if(flag == UNDER)
		l += s->img;
	else if(flag == BOTTOM)
		l = s->img;
else
{printf("found error");TEST exit(2);}
if (l >= s->len + s->grd + s->udr)
{printf("found error");TEST exit(2);}
	return (s->phs[l % s->phl]);
}
