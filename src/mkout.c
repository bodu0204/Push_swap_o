#include "push_swap.h"
#include "debug.h" //test

char	*mkout(t_mplh *h)
{

}

t_mplc	*omitmpl(t_mplc	*one, int *flag)
{
	t_mplc	*two;
	t_mplc	*rtn;

if (!one)
{printf("found error");TEST exit(1);}
	two = one->next;
	if (!two)
		return (NULL);
	if ((one->mpl == pa && two->mpl == pb) || (one->mpl == pb && two->mpl == pa) \
	|| (one->mpl == sa && two->mpl == sa) \
	|| (one->mpl == sb && two->mpl == sb) \
	|| (one->mpl == ss && two->mpl == ss) \
	|| (one->mpl == ra && two->mpl == rra) || (one->mpl == rra && two->mpl == ra) \
	|| (one->mpl == rb && two->mpl == rrb) || (one->mpl == rrb && two->mpl == rb) \
	|| (one->mpl == rr && two->mpl == rrr) || (one->mpl == rrr && two->mpl == rr))
	{
		*flag = 1;
		rtn = two->next;
		free(one);
		free(two);
		return (rtn);
	}
	else
		return(omitmpl1(one, two, flag));
}

t_mplc	*omitmpl1(t_mplc	*one, t_mplc	*two, int *flag)
{
	if ((one->mpl == sa && two->mpl == sb) || (one->mpl == sb && two->mpl == sa))
	{
		*flag = 1;
		two->mpl = ss;
		free(one);
		return (two);
	}
	else if ((one->mpl == ra && two->mpl == rb) || (one->mpl == rb && two->mpl == ra))
	{
		*flag = 1;
		two->mpl = rr;
		free(one);
		return (two);
	}
	else if ((one->mpl == rra && two->mpl == rrb) || (one->mpl == rrb && two->mpl == rra))
	{
		*flag = 1;
		two->mpl = rrr;
		free(one);
		return (two);
	}
	else
		return(one);
}