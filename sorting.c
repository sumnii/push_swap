/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:44:02 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/12 23:17:23 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_stk *a, t_stk *b, int cnt)
{
	t_pivot		pv;
	t_opr		opr;
	int			i;
	
	// ft_printf("---- cnt : %d\n\n", cnt);
	if (cnt <= 3)
	{
		hard_sort_in_a(a, a->len, cnt);
		// print_stack(*a, *b);
		return ;
	}
	pivoting(a, cnt, &pv);
	// ft_printf("---- sp : %d, lp : %d\n\n", pv.s, pv.l);
	i = a->len;
	opr.ra = 0;
	opr.pb = 0;
	opr.rb = 0;
	if (!(a_is_sorted(a, cnt)))
	{
		while (cnt-- && --i)
		{
			// ft_printf("[%d] :     %d vs sp%d vs lp%d\n", i, a->stack[i].n, pv.s, pv.l);
			if (a->stack[i].n <= pv.s && ++opr.pb)
				push_stack(a, b);
			else if (pv.s < a->stack[i].n && a->stack[i].n <= pv.l && ++opr.pb && ++opr.rb)
			{
				push_stack(a, b);
				rotate_stack(*b, b->len);
			}
			else if (pv.l < a->stack[i].n && ++opr.ra && ++i)
				rotate_stack(*a, a->len);
			// print_stack(*a, *b);
		}
		// print_stack(*a, *b);
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
	// print_stack(*a, *b);
	// ft_printf("---- call a to b : ra %d ----\n\n", opr.ra);
	a_to_b(a, b, opr.ra);
	// ft_printf("---- call b to a : rb %d ----\n\n", opr.rb);
	b_to_a(a, b, opr.rb);
	b_to_a(a, b, opr.pb - opr.rb);
}

void	b_to_a(t_stk *a, t_stk *b, int cnt)
{
	t_pivot		pv;
	t_opr		opr;
	int			i;

	// ft_printf("---- cnt : %d\n\n", cnt);
	if (cnt <= 3)
	{
		hard_sort_in_b(a, b, b->len, cnt);
		// print_stack(*a, *b);
		return ;
	}
	pivoting(b, cnt, &pv);
	// ft_printf("---- sp : %d, lp : %d\n\n", pv.s, pv.l);
	i = b->len;
	opr.pa = 0;
	opr.rb = 0;
	opr.ra = 0;
	while (cnt-- && --i)
	{
		if (pv.l <= b->stack[i].n && ++opr.pa)
			push_stack(b, a);
		else if (pv.s <= b->stack[i].n && b->stack[i].n < pv.l && ++opr.pa && ++opr.ra)
		{
			push_stack(b, a);
			rotate_stack(*a, a->len);
		}
		else if (b->stack[i].n < pv.s && ++opr.rb && ++i)
		{
			rotate_stack(*b, b->len);
		}
		// print_stack(*a, *b);
	}
	a_to_b(a, b, opr.pa - opr.ra);
	// print_stack(*a, *b);
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
	// print_stack(*a, *b);
	// ft_printf("---- call a to b : ra%d ----\n\n", opr.ra);
	a_to_b(a, b, opr.ra);
	// ft_printf("---- call b to a : rb%d ----\n\n", opr.rb);
	b_to_a(a, b, opr.rb);
}

void	pivoting(t_stk *stk, int set_len, t_pivot *pv)
{
	int	i;
	int	j;
	int	cnt;

	i = stk->len;
	// ft_printf("len : %d, set_len : %d\n", stk->len, set_len);
	while (--i >= (stk->len - set_len))
	{
		cnt = 0;
		j = stk->len;
		while (--j >= (stk->len - set_len))
			if (stk->stack[i].n > stk->stack[j].n)
				++cnt;
		stk->stack[i].flag = cnt;
		// ft_printf("stack[%d].%d : %d\n", i, stk->stack[i].n, cnt);
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

int	a_is_sorted(t_stk *a, int cnt)
{
	int	i;

	i = a->len - 1;
	// ft_printf("i : %d, cnt : %d\n", i, cnt);
	while (cnt > 0)
	{
		// ft_printf("a[%d] : %d, a[%d] : %d\n", i, a->stack[i].n, i-1, a->stack[i - 1].n);
		if (a->stack[i].n < a->stack[i - 1].n)
			--i;
		else
		{
			// ft_printf("it's not sorted.\n");
			return (0);
		}
		--cnt;
	}
	// ft_printf("\n--- it's sorted.\n");
	return (1);
}