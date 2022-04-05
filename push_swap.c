#include "push_swap.h"

int push_swap(t_stack	s/* 参照渡し不可 */, int ms)//ms: main_stack()
{
	t_stack	*next;/* これを応用すれば参照渡しが可能に... */

	if (ms <= _a && s->a_len <= 2)
	{
		if(swaptwo(s))
			return(1);
		return(0);
	}
	ft_bzero(next, sizeof(t_stack));
	/* _aで再帰 */
	/* _bで再帰 */
}
