/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 00:33:25 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/04 14:05:25 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stk *stack, int len)
{
	ft_printf("s%c\n", stack->name);
	swap_a_b(&(stack->stack[len - 1].n), &(stack->stack[len - 2].n));
}

void	push_stack(t_stk *stack_f, t_stk *stack_t)
{
	int	len_from;
	int	len_to;

	len_from = stack_f->len;
	len_to = stack_t->len;
	ft_printf("p%c\n", stack_t->name);
	stack_t->stack[len_to] = stack_f->stack[len_from - 1];
	stack_f->stack[len_from - 1].n = 0;
	stack_f->stack[len_from - 1].flag = 0;
	stack_t->len += 1;
	stack_f->len -= 1;
}

void	rotate_stack(t_stk stack, int len)
{
	ft_printf("r%c\n", stack.name);
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
	while (i + 1 < len)
	{
		swap_a_b(&(stack.stack[i].n), &(stack.stack[i + 1].n));
		++i;
	}
}
