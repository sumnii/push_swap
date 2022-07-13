/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:00:34 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/13 18:48:09 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	a_is_sorted(t_stk *a, int cnt)
{
	int	i;

	i = a->len - 1;
	while (cnt > 0)
	{
		if (a->stack[i].n < a->stack[i - 1].n)
			--i;
		else
			return (0);
		--cnt;
	}
	return (1);
}

void	a_to_b_dividing(t_stk *a, t_stk *b, int cnt, t_opr *opr)
{
	t_pivot		pv;
	int			i;

	i = a->len;
	pivoting(a, cnt, &pv);
	while (cnt-- && --i)
	{
		if (a->stack[i].n <= pv.s)
		{
			push_stack(a, b);
			++(opr->pb);
		}
		else if (pv.l < a->stack[i++].n)
		{
			rotate_stack(*a, a->len);
			++(opr->ra);
		}
		else
		{
			push_stack(a, b);
			rotate_stack(*b, b->len);
			++(opr->pb);
			++(opr->rb);
		}
	}
}

void	b_to_a_dividing(t_stk *a, t_stk *b, int cnt, t_opr *opr)
{
	t_pivot		pv;
	int			i;

	i = b->len;
	pivoting(b, cnt, &pv);
	while (cnt-- && --i)
	{
		if (pv.l <= b->stack[i].n)
		{
			push_stack(b, a);
			++(opr->pa);
		}
		else if (b->stack[i++].n < pv.s)
		{
			rotate_stack(*b, b->len);
			++(opr->rb);
		}
		else
		{
			push_stack(b, a);
			rotate_stack(*a, a->len);
			++(opr->pa);
			++(opr->ra);
		}
	}
}

void	pivoting(t_stk *stk, int set_len, t_pivot *pv)
{
	int	i;
	int	j;
	int	cnt;

	i = stk->len;
	while (--i >= (stk->len - set_len))
	{
		cnt = 0;
		j = stk->len;
		while (--j >= (stk->len - set_len))
			if (stk->stack[i].n > stk->stack[j].n)
				++cnt;
		stk->stack[i].flag = cnt;
	}
	i = stk->len;
	while (--i >= (stk->len - set_len))
	{
		if (stk->stack[i].flag == (set_len / 3))
			pv->s = stk->stack[i].n;
		else if (stk->stack[i].flag == (set_len / 3 * 2))
			pv->l = stk->stack[i].n;
	}
}

void	rrr_stack(t_stk *a, t_stk *b, t_opr opr)
{
	int	i;

	if (opr.ra > opr.rb)
	{
		i = opr.rb;
		while (i-- > 0)
			reverse_rotate_stack(a, a->len, b, b->len);
		i = opr.ra - opr.rb;
		while (i-- > 0)
			reverse_rotate_stack(a, a->len, NULL, 0);
	}
	else if (opr.ra <= opr.rb)
	{
		i = opr.ra;
		while (i-- > 0)
			reverse_rotate_stack(a, a->len, b, b->len);
		i = opr.rb - opr.ra;
		while (i-- > 0)
			reverse_rotate_stack(NULL, 0, b, b->len);
	}
}
