#include "push_swap.h"

int push_swap(t_stack	*s, int ms)//ms: main_stack()
{
	t_stack	next;
	size_t	mount;

	if (s->g_len <= 2)
	{
		if(swaptwo(s))//swaptwo(s)
			return(1);
		return(0);
	}
	ft_bzero(&next, sizeof(t_stack));
	mount = divide_mount(s->g, s->g_len);/* 分ける基準を決める(= うち片方にどれだけの量の数があるか) */
	if (xxx()) /* ２つに分ける処理 */
		return (1);
	if (xxx()) /* 底にあるものを上まで持ってくる処理 or スタックを整える処理(x = x_baseの時) */
		return (1);
	xxx();/* _aのためのnextを設定する処理 */
	if (push_swap(&next, _a))
		return (1);
	xxx();/* _bのためのnextを設定する処理 */
	if (push_swap(&next, _b))
		return (1);
	return (0);
}
