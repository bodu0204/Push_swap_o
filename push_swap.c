#include "push_swap.h"

int push_swap(t_stack	*s, int ms)//ms: main_stack()
{
	t_stack		next;
	t_dividing	d;

	if (little_push_swap(/* 未完 */))/* -> a_len != 1 a_len != 2 g_lenも同様*/ /* _a を上げる機能 + _a swap */
		return (1);
	set_divide_fmt(&d, s->g, s->g_len);/* 分ける基準を決める(= うち片方にどれだけの量の数があるか) */
	if (divide(s, &d, ms)) /* ２つに分ける処理 */
		return (1);
	if (treatstack(s, ms)) /* 底にあるものを上まで持ってくる処理 or スタックを整える処理(x = x_baseの時) + _a を上げる機能 */
		return (1);
	if (s->g_len <= 4)/* g以外で考える */
	{
		if(swaptwo(s))// 要修正
			return(1);
		return(0);
	}
	set_next_stack(s, &next, ms);/* _aのためのnextを設定する処理(= mainじゃない方のベースポインターを上げる, ) */ /* bzeroを忘れすに */
	if (push_swap(&next, _a))
		return (1);
	set_next_stack(s, &next, ms);/* _bのためのnextを設定する処理 */
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

void	set_divide_fmt(t_dividing	*d, int	*goal, size_t	l)/* 分ける基準を決める(= うち片方にどれだけの量の数があるか) */
{
	size_t	i;

	ft_bzero(d, sizeof(t_dividing));
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

int divide(t_stack	*s, t_dividing *d, int ms)
{
	t_dividing	next;

	if (ms == _a)
	{
		set_divide_fmt(&next, s->g + d->dm + d->inc, d->dm);
		return (divide_from_a(s, d, &next));
	}
	set_divide_fmt(&next, s->g, d->dm + d->inc);
	return(divide_from_b(s, d, &next));
}

int divide_from_a(t_stack	*s, t_dividing *d, t_dividing *next)
{
	size_t		ib;/*  mount of push to b  */
	int			flag;/*  */

	ib = 0;
	while(s->a_len > 0 && ib < d->dm) /* "s->a_len > 0" 理論上いらない */
	{
		if (s->a[s->a_len - 1] < d->dn \
		|| (s->a[s->a_len - 1] == d->dn && d->use < d->for_a))
		{
			if (s->a[s->a_len - 1] == d->dn)
				d->use++;
			if (rotate(s, &flag, _a)) /* a↓ or ab↓ */
				return (1);
		}
		else
		{
			ib++;
			if (push_from_a(s, &flag, next))/* a→b */
				return (1);
		}
	}
	if (flag)
		if (manipulate(s, rb))
			return (1);
	return(0);
}

int push_from_a(t_stack	*s, int *flag, t_dividing *next)
{
	int i;

	if (*flag)
		if (manipulate(s, rb))
			return (1);
	*flag = 0;
	i = s->a[s->a_len - 1];
	if (manipulate(s, pb))
		return (1);
	if (s->b_len - 1 <= next->dm / 4 \
	&& i <= next->dn && s->a != s->a_base)
	{
		if (i == next->dn && next->use < next->for_b)
			*flag = 1;
		else
			next->use++;
	}
	return (0);
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
		if(/* a↓ */0)
			return (1)
	}
	else if (ms == _b)
	{
		if(/* b↓ */0)
			return (1)
	}
	else
		return (1);
	*flag = 0;
	return (0);
}

int divide_from_b(t_stack	*s, t_dividing *d, t_dividing *next)
{
	size_t		ibb;/*  mount of push to b_back  */
	int			flag;/*  */

	ibb = 0;
	while(s->b_len > 0 && ibb < d->dm)/* "s->b_len > 0" 理論上いらない */
	{
		if (s->b[s->b_len - 1] > d->dn \
		|| (s->b[s->b_len - 1] == d->dn && d->use < d->for_b))
		{
			ibb++;
			if (s->b[s->b_len - 1] == d->dn)
				d->use++;
			if (rotate(s, &flag, _b))/* b↓ or ab↓ */
				return (1);
		}
		else
		{
			if (push_from_b(s, &flag, next))/* b→a */
				return (1);
		}
	}
	if (flag)
		if (manipulate(s, ra))
			return (1);
	return(0);
}

int push_from_b(t_stack	*s, int *flag, t_dividing *next)
{
	int i;

	if (*flag)
		if (manipulate(s, ra))
			return (1);
	*flag = 0;
	i = s->b[s->b_len - 1];
	if (manipulate(s, pa))
		return (1);
	if (s->a_len - 1 <= next->dm / 4 \
	&& i <= next->dn && s->b != s->b_base)
	{
		if (i == next->dn && next->use < next->for_a)
			*flag = 1;
		else
			next->use++;
	}
	return (0);
}

int treatstack(t_stack	*s, int ms)
{
	if (ms == _a && s->a == s->a_base \
	|| ms == _b && s->b == s->b_base)
	{
		mvstack(s->a, &s->a_len, s->a_base, &s->a_back_len);
		mvstack(s->b, &s->b_len, s->b_base, &s->b_back_len);
		return (0);
	}
	while (s->a_back_len && s->b_back_len)
		if (manipulate(s, rrr))
			return(1);
	while (s->a_back_len)
		if (manipulate(s, rra))
			return(1);
	while (s->b_back_len)
		if (manipulate(s, rrb))
			return(1);
	return (0);
}

void	mvstack(int *mst, size_t *msl, int *bst, size_t *bsl)
{
	size_t	i;

	i = 0;
	ft_memmove(mst + *bsl, mst, *msl * sizeof(int));
	while (i < *bsl)
	{
		mst[*bsl - i] = bst[i];
		i++;
	}
	*msl += *bsl;
	*bsl = 0;
	return ;
}

void set_next_stack(t_stack *s, t_stack *next, int ms)/* _a or _b のためのnextを設定する処理(= mainじゃない方のベースポインターを上げる, ) */ /* bzeroを忘れすに */
{
	ft_memcpy(next, s, sizeof(t_stack));
	next->a_back_len = 0;/* 前の処理がしっかりしていれば必要ない */
	next->b_back_len = 0;/* 前の処理がしっかりしていれば必要ない */
	if (ms == _a)
	{
		next->g_len -= next->b_len;
		next->b += next->b_len;
		next->b_len = 0;
	}
	else
	{
		next->g += next->a_len;
		next->g_len -= next->a_len;
		next->a += next->a_len;
		next->a_len = 0;
	}
	return ;
}

int swaptwo(t_stack *s)
{
	int i;

	if ((s->a[s->a_len - 1] < s->a[s->a_len - 1]) \
	&& (s->g_len == 4 && s->b[s->b_len - 1] < s->b[s->a_len - 2]))
	{
		if (manipulate(s, ss))
			return(1);
	}
	else if (s->a[s->a_len -1] < s->a[s->a_len -1])
	{
		if (manipulate(s, sa))
			return(1);
	}
	else if (s->g_len == 4 && s->b[s->b_len - 1] < s->b[s->a_len - 2])
	{
		if (manipulate(s, sb))
			return(1);
	}
	i = s->g_len - 2;
	while (i--)
		if (manipulate(s, pa))
			return (1);
	return (0);
}
