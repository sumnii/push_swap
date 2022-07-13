/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_5_arg_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 23:48:12 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/13 16:45:42 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3_arg(t_stk *a, int len)
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
}

void	sort_5_arg(t_stk *a, t_stk *b, int len)
{
	t_pivot	pv;
	int		i;

	pivoting(a, 5, &pv);
	i = len - 1;
	while (len--)
	{
		if (a->stack[i].n < pv.l)
		{
			push_stack(a, b);
			--i;
		}
		else
			rotate_stack(*a, a->len);
	}
	sort_3_arg(a, a->len);
	hard_sort_in_b(a, b, b->len, 2);
}
