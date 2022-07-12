/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivoting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:44:02 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/12 20:59:00 by sumsong          ###   ########.fr       */
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
	while (cnt-- && --i)
	{
		// ft_printf("[%d] :     %d vs sp%d vs lp%d\n", i, a->stack[i].n, pv.s, pv.l);
		if (a->stack[i].n < pv.s && ++opr.pb)
			push_stack(a, b);
		else if (pv.s <= a->stack[i].n && a->stack[i].n <= pv.l && ++opr.pb && ++opr.rb)
		{
			push_stack(a, b);
			rotate_stack(*b, b->len);
		}
		else if (pv.l < a->stack[i].n && ++opr.ra && ++i)
			rotate_stack(*a, a->len);
		// print_stack(*a, *b);
	}
	print_stack(*a, *b);
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
	print_stack(*a, *b);
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
		// ft_printf("b cnt <= 3! hard coding!\n");
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
		if (pv.l < b->stack[i].n && ++opr.pa)
			push_stack(b, a);
		else if (pv.s <= b->stack[i].n && b->stack[i].n <= pv.l && ++opr.pa && ++opr.ra)
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
	print_stack(*a, *b);
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
	print_stack(*a, *b);
	// ft_printf("---- call a to b : ra%d ----\n\n", opr.ra);
	a_to_b(a, b, opr.ra);
	// ft_printf("---- call b to a : rb%d ----\n\n", opr.rb);
	b_to_a(a, b, opr.rb);
}

void	hard_sort_in_a(t_stk *a, int len, int cnt)
{
	// ft_printf("--- hard sort A! cnt %d\n\n", cnt);
	if (cnt == 2)
		sort_two_in_a(a, len);
	else if (cnt == 3)
		sort_three_in_a(a, len);
}

void	hard_sort_in_b(t_stk *a, t_stk *b, int len, int cnt)
{
	// ft_printf("--- hard sort B! cnt %d\n\n", cnt);
	if (cnt == 0)
		return ;
	else if (cnt == 2)
	{
		sort_two_in_b(b, len);
		push_stack(b, a);
	}
	else if (cnt == 3)
	{
		sort_three_in_b(b, len);
		// print_stack(*a, *b);
		push_stack(b, a);
		push_stack(b, a);
	}
	push_stack(b, a);
}

int	sort_three_in_a(t_stk *a, int len)
{
	int	first;
	int	second;
	int	third;

	first = a->stack[len - 1].n;
	second = a->stack[len - 2].n;
	third = a->stack[len - 3].n;
	if (first < third && third < second)
		a_sort_1_3_2(a);
	else if (second < first && first < third)
		a_sort_2_1_3(a);
	else if (third < first && first < second)
		a_sort_2_3_1(a);
	else if (second < third && third < first)
		a_sort_3_1_2(a);
	else if (third < second && second < first)
		a_sort_3_2_1(a);
	return (1);
}

int	sort_two_in_a(t_stk *a, int len)
{
	int	first;
	int	second;

	first = a->stack[len - 1].n;
	second = a->stack[len - 2].n;
	if (first < second)
		return (1);
	else
	{
		swap_stack(a, a->len);
		return (1);
	}
}

int	sort_three_in_b(t_stk *b, int len)
{
	int	first;
	int	second;
	int	third;

	first = b->stack[len - 1].n;
	second = b->stack[len - 2].n;
	third = b->stack[len - 3].n;
	if (first < second && second < third)
		b_sort_1_2_3(b);
	else if (first < third && third < second)
		b_sort_1_3_2(b);
	else if (second < first && first < third)
		b_sort_2_1_3(b);
	else if (third < first && first < second)
		b_sort_2_3_1(b);
	else if (second < third && third < first)
		b_sort_3_1_2(b);
	return (1);
}

int	sort_two_in_b(t_stk *b, int len)
{
	if (b->stack[len - 1].n > b->stack[len - 2].n)
		return (1);
	else
	{
		swap_stack(b, b->len);
		return (1);
	}
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
