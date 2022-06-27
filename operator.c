/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 00:33:25 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/27 12:48:07 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(int *stack, int len)
{
	ft_printf("swap %d <-> %d\n\n", stack[len - 1], stack[len - 2]);
	swap_a_b(&(stack[len - 1]), &(stack[len - 2]));
}

void	push_stack(int *stack_from, int *stack_to);

void	rotate_stack(int *stack);

void	reverse_rotate_stack(int *stack);
