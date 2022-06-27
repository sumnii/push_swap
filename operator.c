/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 00:33:25 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/27 13:45:08 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(int *stack, int len)
{
	ft_printf("swap %d <-> %d\n\n", stack[len - 1], stack[len - 2]);
	swap_a_b(&(stack[len - 1]), &(stack[len - 2]));
}

void	push_stack(int *stack_from, int *stack_to, int *len_from, int *len_to)
{
	ft_printf("push %d to another stack\n\n", stack_from[*len_from - 1]);
	stack_to[*len_to] = stack_from[*len_from - 1];
	stack_to[*len_from] = 0;
	*len_to += 1;
	*len_from -= 1;
}

void	rotate_stack(int *stack, int len)
{
	while (len - 2 >= 0)
	{
		swap_a_b(&(stack[len - 1]), &(stack[len - 2]));
		--len;
	}
}

void	reverse_rotate_stack(int *stack);
