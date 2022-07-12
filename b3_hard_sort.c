/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b3_hard_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:53:38 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/12 23:30:03 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_sort_1_2_3(t_stk *a, t_stk *b)
{
	swap_stack(b, b->len);
	push_stack(b, a);
	swap_stack(b, b->len);
	push_stack(b, a);
	swap_stack(a, a->len);
}

void	b_sort_1_3_2(t_stk *a, t_stk *b)
{
	swap_stack(b, b->len);
	push_stack(b, a);
	swap_stack(b, b->len);
	push_stack(b, a);
}

void	b_sort_2_1_3(t_stk *a, t_stk *b)
{
	push_stack(b, a);
	swap_stack(b, b->len);
	push_stack(b, a);
	swap_stack(a, a->len);
}

void	b_sort_2_3_1(t_stk *a, t_stk *b)
{
	swap_stack(b, b->len);
	push_stack(b, a);
	push_stack(b, a);
}

void	b_sort_3_1_2(t_stk *a, t_stk *b)
{
	push_stack(b, a);
	swap_stack(b, b->len);
	push_stack(b, a);
}
