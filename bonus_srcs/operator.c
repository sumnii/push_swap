/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 00:33:25 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/13 18:43:23 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	swap_stack(t_stk *a, int a_len, t_stk *b, int b_len)
{
	if (a)
	{
		swap_a_b(&(a->stack[a_len - 1].n), &(a->stack[a_len - 2].n));
		swap_a_b(&(a->stack[a_len - 1].flag), &(a->stack[a_len - 2].flag));
	}
	if (b)
	{
		swap_a_b(&(b->stack[b_len - 1].n), &(b->stack[b_len - 2].n));
		swap_a_b(&(b->stack[b_len - 1].flag), &(b->stack[b_len - 2].flag));
	}
}

void	push_stack(t_stk *stack_f, t_stk *stack_t)
{
	int	len_from;
	int	len_to;

	len_from = stack_f->len;
	len_to = stack_t->len;
	stack_t->stack[len_to] = stack_f->stack[len_from - 1];
	stack_f->stack[len_from - 1].n = 0;
	stack_f->stack[len_from - 1].flag = 0;
	stack_t->len += 1;
	stack_f->len -= 1;
}

void	rotate_stack(t_stk *a, int a_len, t_stk *b, int b_len)
{
	while (a && a_len - 2 >= 0)
	{
		swap_a_b(&(a->stack[a_len - 1].n), &(a->stack[a_len - 2].n));
		swap_a_b(&(a->stack[a_len - 1].flag), &(a->stack[a_len - 2].flag));
		--a_len;
	}
	while (b && b_len - 2 >= 0)
	{
		swap_a_b(&(b->stack[b_len - 1].n), &(b->stack[b_len - 2].n));
		swap_a_b(&(b->stack[b_len - 1].flag), &(b->stack[b_len - 2].flag));
		--b_len;
	}
}

void	reverse_rotate_stack(t_stk *a, int a_len, t_stk *b, int b_len)
{
	int	i;

	i = 0;
	while (a && i + 1 < a_len)
	{
		swap_a_b(&(a->stack[i].n), &(a->stack[i + 1].n));
		swap_a_b(&(a->stack[i].flag), &(a->stack[i + 1].flag));
		++i;
	}
	i = 0;
	while (b && i + 1 < b_len)
	{
		swap_a_b(&(b->stack[i].n), &(b->stack[i + 1].n));
		swap_a_b(&(b->stack[i].flag), &(b->stack[i + 1].flag));
		++i;
	}
}

void	swap_a_b(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
