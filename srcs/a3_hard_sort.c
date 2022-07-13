/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a3_hard_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:53:38 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/13 16:45:42 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	a_sort_1_3_2(t_stk *a)
{
	rotate_stack(*a, a->len);
	swap_stack(a, a->len);
	reverse_rotate_stack(a, a->len, NULL, 0);
}

void	a_sort_2_1_3(t_stk *a)
{
	swap_stack(a, a->len);
}

void	a_sort_2_3_1(t_stk *a)
{
	rotate_stack(*a, a->len);
	swap_stack(a, a->len);
	reverse_rotate_stack(a, a->len, NULL, 0);
	swap_stack(a, a->len);
}

void	a_sort_3_1_2(t_stk *a)
{
	swap_stack(a, a->len);
	a_sort_1_3_2(a);
}

void	a_sort_3_2_1(t_stk *a)
{
	swap_stack(a, a->len);
	a_sort_2_3_1(a);
}
