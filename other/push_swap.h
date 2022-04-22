/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 05:21:11 by ryoakira          #+#    #+#             */
/*   Updated: 2022/04/22 09:07:55 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

enum
{
	_a,
	_b,
};

enum
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
};

typedef struct s_stack
{
	size_t	len;//length(+)
	size_t	grd; //guard(+)
	size_t	udr; //under(+)
	size_t	img; //imagin(+-)
	int		*phs;
	size_t	phl;
}	t_stack;

typedef struct s_situation
{
	struct s_stack	a;
	struct s_stack	b;
	struct s_stack	g;
	int				exp;
	void			*freefrom;
}	t_situation;

typedef struct s_dividing
{
	int		num;
	size_t	mut;
	size_t	inc;
	size_t	use;
}	t_dividing;

typedef struct s_manipulate_header
{
	int							flag;
	struct s_manipulate_content	*cnt;
	struct s_manipulate_content	*sc;
}	t_mplh;

typedef struct s_manipulate_content
{
	int							mpl;
	struct s_manipulate_content	*next;
}	t_mplc;


#endif
