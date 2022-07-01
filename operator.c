/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 00:33:25 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/01 15:52:41 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stk stack, int len)
{
	ft_printf("s%c\n", stack.name);
	// ft_printf(": swap %d <-> %d\n", stack.stack[len - 1].n, stack.stack[len - 2].n);
	swap_a_b(&(stack.stack[len - 1].n), &(stack.stack[len - 2].n));
}

void	push_stack(t_stk stack_f, t_stk stack_t, int *len_f, int *len_t)
{
	ft_printf("p%c\n", stack_t.name);
	// ft_printf(": push %d to another stack\n", stack_f.stack[*len_f - 1].n);
	stack_t.stack[*len_t].n = stack_f.stack[*len_f - 1].n;
	stack_f.stack[*len_f - 1].n = 0;
	*len_t += 1;
	*len_f -= 1;
}

void	rotate_stack(t_stk stack, int len)
{
	ft_printf("r%c\n", stack.name);
	// ft_printf(": rotate stack\n");
	while (len - 2 >= 0)
	{
		swap_a_b(&(stack.stack[len - 1].n), &(stack.stack[len - 2].n));
		--len;
	}
}

void	reverse_rotate_stack(t_stk stack, int len)
{
	int	i;

	i = 0;
	ft_printf("rr%c\n", stack.name);
	// ft_printf(": reverse_rotate_stack\n");
	while (i + 1 < len)
	{
		swap_a_b(&(stack.stack[i].n), &(stack.stack[i + 1].n));
		++i;
	}
}
