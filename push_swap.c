#include "push_swap.h"

int push_swap(t_stack	*s, int ms)//ms: main_stack()
{
	t_stack	next;
	size_t	mount;

	if (ms <= _a && s->a_len <= 2)
	{
		if(swaptwo(s))
			return(1);
		return(0);
	}
	ft_bzero(&next, sizeof(t_stack));
	mount = divide_mount();/* 分ける基準を決める(それぞれどれだけの量の数があるかも求めたい←次でも可) */
	xxx(/*  */); /* ２つに分ける処理 */
	if (ms != _a_first)
		xxx();/* 底にあるものを上まで持ってくる処理 */
	xxx();/* スタックを整える処理(_firstのために存在する) */
	xxx();/* _aのためのnextを設定する処理 */
	push_swap(&next, _a);
	xxx();/* _bのためのnextを設定する処理 */
	push_swap(&next, _b);

}
