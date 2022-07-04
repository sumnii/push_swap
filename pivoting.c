/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivoting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:44:02 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/04 14:04:17 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pivoting_a(t_stk *a, t_stk *b, int cnt)
{
	int			pivot;
	int			i;
	int			pb;
	int			ra;
	static int	new = 0;

	ft_printf("---- a : %d, b : %d, cnt : %d\n", a->len, b->len, cnt);
	if (cnt == 2)
	{
		cnt = sort_two_in_a(a, a->len);
		print_stack(*a, *b);
	}
	if (cnt <= 1)
		return ;
	pivot = a->stack[(a->len) - (cnt / 2) - 1].n;
	i = a->len - 1;
	++new;
	ra = 0;
	pb = 0;
	ft_printf("pivot : %d\n", pivot);
	while (cnt)
	{
		ft_printf("stack[%d] : %d\n", i, a->stack[i].n);
		if (a->stack[i].n <= pivot)
		{
			a->stack[i--].flag = new;
			push_stack(a, b);
			++pb;
		}
		else if (a->stack[i].n > pivot)
		{
			rotate_stack(*a, a->len);
			++ra;
		}
		print_stack(*a, *b);
		--cnt;
	}
	print_stack(*a, *b);
	i = ra;
	while (i--)
		reverse_rotate_stack(*a, a->len);
	ft_printf("< recall > a to b-------------------------\n\n");
	pivoting_a(a, b, ra);
	ft_printf("<  call  > b to a-------------------------\n\n");
	pivoting_b(a, b, pb);
}

void	pivoting_b(t_stk *a, t_stk *b, int cnt)
{
	int			pivot;
	int			i;
	int			pa;
	int			rb;
	static int	new = 0;

	ft_printf("---- a : %d, b : %d, cnt : %d\n", a->len, b->len, cnt);
	if (cnt == 2)
	{
		cnt = sort_two_in_b(b, b->len);
		print_stack(*a, *b);
		push_stack(b, a);
	}
	if (cnt == 1)
	{
		push_stack(b, a);
		return ;
	}
	pivot = b->stack[(b->len) - (cnt / 2) - 1].n;
	i = b->len - 1;
	++new;
	pa = 0;
	rb = 0;
	ft_printf("pivot : %d\n", pivot);
	while (cnt)
	{
		ft_printf("stack[%d] : %d\n", i, b->stack[i].n);
		if (b->stack[i].n >= pivot)
		{
			b->stack[i--].flag = new;
			push_stack(b, a);
			++pa;
		}
		else if (b->stack[i].n < pivot)
		{
			rotate_stack(*b, b->len);
			++rb;
		}
		print_stack(*a, *b);
		--cnt;
	}
	i = rb;
	while (i--)
		reverse_rotate_stack(*b, b->len);
	print_stack(*a, *b);
	pivoting_a(a, b, pa);
	pivoting_b(a, b, rb);
}

int	sort_two_in_a(t_stk *a, int len)
{
	ft_printf(" ----------- hard sort A!\n\n");
	if (a->stack[len - 1].n > a->stack[len - 2].n)
	{
		swap_stack(a, a->len);
		return (1);
	}
	else
		return (1);
}

int	sort_two_in_b(t_stk *b, int len)
{
	ft_printf(" ----------- hard sort B!\n\n");
	if (b->stack[len - 1].n > b->stack[len - 2].n)
		return (1);
	else
	{
		swap_stack(b, b->len);
		return (1);
	}
}
