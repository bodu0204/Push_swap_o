#include "push_swap.h"
#include "debug.h"/* test */

void push(t_stack *s, int n)
{
	s->phs[(s->img + s->udr + s->grd + s->len) % s->phl] = n;
	s->len++;
if (s->udr + s->grd + s->len > s->phl)
{printf("found error");TEST}
	return ;
}

int pop(t_stack *s)
{
	int i;

if (!s->len)
{printf("found error");TEST}
	s->len--;
	i = s->phs[(s->img + s->udr + s->grd + s->len) % s->phl];
	return (i);
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

void rotate(t_stack *s)//未完
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
