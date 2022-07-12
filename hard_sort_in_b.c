/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort_in_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:07:54 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/12 23:37:20 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		sort_three_in_b(a, b, len);
		// print_stack(*a, *b);
	}
	push_stack(b, a);
}

int	sort_three_in_b(t_stk *a, t_stk *b, int len)
{
	int	first;
	int	second;
	int	third;

	first = b->stack[len - 1].n;
	second = b->stack[len - 2].n;
	third = b->stack[len - 3].n;
	if (first < second && second < third)
		b_sort_1_2_3(a, b);
	else if (first < third && third < second)
		b_sort_1_3_2(a, b);
	else if (second < first && first < third)
		b_sort_2_1_3(a, b);
	else if (third < first && first < second)
		b_sort_2_3_1(a, b);
	else if (second < third && third < first)
		b_sort_3_1_2(a, b);
	else
	{
		push_stack(b, a);
		push_stack(b, a);
	}
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
