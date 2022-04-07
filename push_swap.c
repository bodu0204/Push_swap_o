#include "push_swap.h"

int push_swap(t_stack	*s, int ms)//ms: main_stack()
{
	t_stack		next;
	t_dividing	d;

	if (s->g_len <= 2)
	{
		if(swaptwo(s))//aのときは普通に入れ替え, bのときはaにpushしてaを再帰
			return(1);
		return(0);
	}
	ft_bzero(&next, sizeof(t_stack));
	mk_divide_fmt(&d, s->g, s->g_len);/* 分ける基準を決める(= うち片方にどれだけの量の数があるか) */
	if (divide(s, &d, ms)) /* ２つに分ける処理 */
		return (1);
	if (xxx()) /* 底にあるものを上まで持ってくる処理 or スタックを整える処理(x = x_baseの時) */
		return (1);
	xxx();/* _aのためのnextを設定する処理(= mainじゃない方のベースポインターを上げる, ) */
	if (push_swap(&next, _a))
		return (1);
	xxx();/* _bのためのnextを設定する処理 */
	if (push_swap(&next, _b))
		return (1);
	return (0);
}

int pop_push(int *pops, size_t *pol, int *pushs, size_t *pul)
{
	*pol--;
	pushs[*pul] = pops[*pol];
	*pul++;
}

void	mk_divide_fmt(t_dividing	*d, int	*goal, size_t	l)/* 分ける基準を決める(= うち片方にどれだけの量の数があるか) */
{
	size_t	i;

	d->dm = l / 2;
	d->inc = l % 2;
	i = d->dm + d->inc - 1;
	d->dn = goal[i];
	d->for_b = 0;
	while (goal[i] == d->dn && i < l)
	{
		i++;
		d->for_b++;
	}
	i = d->dm + d->inc;
	d->for_a = 1;
	while (goal[i] == d->dn && i > 0)
	{
		i--;
		d->for_a++;
	}
	return ;
}

int devide(t_stack	*s, t_dividing *d, int ms)
{
	if (ms == _a)
		return (divide_from_a(s, d));
	return(divide_from_b(s, d));
}

int divide_from_a(t_stack	*s, t_dividing *d)
{
	size_t	ib;/*  mount of push to b  */
	size_t	ida;/* mount of divide-nuumber at a */
	int		flag;/*  */

	ib = 0;
	ida = 0;
	while(s->a_len > 0 && ib < d->dm)
	{
		if (s->a[s->a_len - 1] < d->dn \
		|| (s->a[s->a_len - 1] == d->dn && ida < d->for_a))
		{
			/* a↓ */
		}
		else
		{
			/* a→b */
			ib++;
		}
	}
	if (flag)
		/* b↓ */
	return(0)
}
