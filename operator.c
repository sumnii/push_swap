/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 00:33:25 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/27 11:33:12 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(int **stack)
{
	int	i;
	int	last_i;
	int	*s;

	i = 0;
	s = *stack;
	while (s[i] != 0)
		++i;
	last_i = i - 1;
	swap_a_b(&(s[last_i - 1]), &(s[last_i]));
	*stack = s;
}

void	push_stack(int *stack_f, int *stack_t);

void	rotate_stack(int *stack);

void	reverse_rotate_stack(int *stack);

void	swap_a_b(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
