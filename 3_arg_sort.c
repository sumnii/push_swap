/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_arg_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 23:48:12 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/13 00:03:17 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three_in_arg(t_stk *a, int len)
{
	int	first;
	int	second;
	int	third;

	first = a->stack[len - 1].n;
	second = a->stack[len - 2].n;
	third = a->stack[len - 3].n;
	if (first < third && third < second)
	{
		reverse_rotate_stack(a, len, NULL, 0);
		swap_stack(a, len);
	}
	else if (second < first && first < third)
		swap_stack(a, len);
	else if (third < first && first < second)
		reverse_rotate_stack(a, len, NULL, 0);
	else if (second < third && third < first)
		rotate_stack(*a, len);
	else if (third < second && second < first)
	{
		swap_stack(a, len);
		reverse_rotate_stack(a, len, NULL, 0);
	}
	return (1);
}
