#include "push_swap.h"
#include "debug.h"/* test */

void push(t_stack *o, t_stack *u)
{
	int i;

if (!o->len)
{printf("found error");TEST}
	o->len--;
	i = o->phs[(o->img + o->udr + o->grd + o->len) % o->phl];
	u->phs[(u->img + u->udr + u->grd + u->len) % u->phl] = i;
	u->len++;
if (u->udr + u->grd + u->len > u->phl)
{printf("found error");TEST}
	return ;
}

void swap(t_stack *s)
{
	int i;
	int ii;

if (s->len < 2)
{printf("found error");TEST}
	i = s->phs[(s->img + s->udr + s->grd + s->len - 1) % s->phl];
	ii = s->phs[(s->img + s->udr + s->grd + s->len - 2) % s->phl];
	s->phs[(s->img + s->udr + s->grd + s->len - 1) % s->phl] = ii;
	s->phs[(s->img + s->udr + s->grd + s->len - 2) % s->phl] = i;
	return ;
}

void rotate(t_stack *s)
{
	int i;

if (!s->len)
{printf("found error");TEST}
	s->len--;
	i = s->phs[(s->img + s->udr + s->grd + s->len) % s->phl];
	s->img = (s->img + s->phl - 1) % s->phl;
	s->phs[s->img] = i;
	s->udr++;
	return ;
}

void revrotate(t_stack *s)
{
	int i;

if (!s->udr)
{printf("found error");TEST}
	i = s->phs[s->img];
	s->img = (s->img + 1) % s->phl;
	s->udr--;
	s->phs[(s->img + s->udr + s->grd + s->len) % s->phl] = i;
	s->len++;
	return ;
}

int	getn(t_stack *s, size_t l)
{
	int i;

if (l >= s->len)
{printf("found error");TEST}
	i = s->phs[(s->img + s->udr + s->grd + l) % s->phl];
	return (i);
}
