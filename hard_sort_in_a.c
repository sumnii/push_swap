/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort_in_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:02:30 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/12 22:36:44 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hard_sort_in_a(t_stk *a, int len, int cnt)
{
	// ft_printf("--- hard sort A! cnt %d\n\n", cnt);
	if (cnt == 2)
		sort_two_in_a(a, len);
	else if (cnt == 3)
		sort_three_in_a(a, len);
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
