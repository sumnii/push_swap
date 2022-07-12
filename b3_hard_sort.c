/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b3_hard_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:53:38 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/11 21:31:23 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_sort_1_2_3(t_stk *b)
{
	swap_stack(b, b->len);
	b_sort_2_1_3(b);
}

void	b_sort_1_3_2(t_stk *b)
{
	swap_stack(b, b->len);
	b_sort_3_1_2(b);
}

void	b_sort_2_1_3(t_stk *b)
{
	b_sort_3_1_2(b);
	swap_stack(b, b->len);
}

void	b_sort_2_3_1(t_stk *b)
{
	swap_stack(b, b->len);
}

void	b_sort_3_1_2(t_stk *b)
{
	rotate_stack(*b, b->len);
	swap_stack(b, b->len);
	reverse_rotate_stack(NULL, 0, b, b->len);
}
