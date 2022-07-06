/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivoting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:44:02 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/05 00:59:34 by sumsong          ###   ########.fr       */
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
	int			len_cpy;

	// ft_printf("---- cnt : %d\n\n", cnt);
	if (cnt <= 3)
	{
		hard_sort_in_a(a, a->len, cnt);
		// print_stack(*a, *b);
		return ;
	}
	len_cpy = a->len;
	pivot = a->stack[(a->len) - 1].n;
	// ft_printf("---- pivot : %d\n\n", pivot);
	i = a->len - 1;
	++new;
	ra = 0;
	pb = 0;
	while (cnt)
	{
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
		--cnt;
	}
	// print_stack(*a, *b);
	if (len_cpy - pb != ra)
	{
		// ft_printf("len%d - (ra+pb)%d = %d vs ra%d\n\n", len_cpy, ra+pb, len_cpy-ra-pb, ra);
		if (len_cpy - (ra + pb) > ra)
		{
			i = ra;
			while (i--)
				reverse_rotate_stack(*a, a->len);
		}
		else
		{
			i = len_cpy - (ra + pb);
			while (i--)
				rotate_stack(*a, a->len);
		}
	}
	// print_stack(*a, *b);
	// ft_printf("---- call a to b ----\n\n");
	pivoting_a(a, b, ra);
	// ft_printf("---- call b to a ----\n\n");
	pivoting_b(a, b, pb);
}

void	pivoting_b(t_stk *a, t_stk *b, int cnt)
{
	int			pivot;
	int			i;
	int			pa;
	int			rb;
	static int	new = 0;
	int			len_cpy;

	// ft_printf("---- cnt : %d\n\n", cnt);
	if (cnt <= 3)
	{
		hard_sort_in_b(a, b, b->len, cnt);
		// print_stack(*a, *b);
		return ;
	}
	len_cpy = b->len;
	pivot = b->stack[(b->len) - cnt].n;
	// ft_printf("---- pivot : %d\n\n", pivot);
	i = b->len - 1;
	++new;
	pa = 0;
	rb = 0;
	while (cnt)
	{
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
		--cnt;
		// print_stack(*a, *b);
	}
	// print_stack(*a, *b);
	i = rb;
	if (len_cpy - pa != rb)
	{
		// ft_printf("len%d - (rb+pa)%d = %d vs rb%d\n\n", len_cpy, rb+pa, len_cpy-rb-pa, rb);
		if (len_cpy - (rb + pa) > rb)
		{
			i = rb;
			while (i--)
				reverse_rotate_stack(*b, b->len);
		}
		else
		{
			i = len_cpy - (rb + pa);
			while (i--)
				rotate_stack(*b, b->len);
		}
	}
	// print_stack(*a, *b);
	// ft_printf("---- call a to b ----\n\n");
	pivoting_a(a, b, pa);
	// ft_printf("---- call b to a ----\n\n");
	pivoting_b(a, b, rb);
}

void	hard_sort_in_a(t_stk *a, int len, int cnt)
{
	// ft_printf("--- hard sort A! cnt %d\n\n", cnt);
	if (cnt == 2)
		sort_two_in_a(a, len);
	else if (cnt == 3)
		sort_three_in_a(a, len);
}

void	hard_sort_in_b(t_stk *a, t_stk *b, int len, int cnt)
{
	// ft_printf("--- hard sort B! cnt %d\n\n", cnt);
	if (cnt == 0)
		return ;
	else if (cnt == 2)
	{
		sort_two_in_b(b, len);
		push_stack(b, a);
	}
	else if (cnt == 3)
	{
		sort_three_in_b(b, len);
		push_stack(b, a);
		push_stack(b, a);
	}
	push_stack(b, a);
}

int	sort_three_in_a(t_stk *a, int len)
{
	int	first;
	int	second;
	int	third;

	first = a->stack[len - 1].n;
	second = a->stack[len - 2].n;
	third = a->stack[len - 3].n;
	if (first < third && third < second)
		a_sort_1_3_2(a);
	else if (second < first && first < third)
		a_sort_2_1_3(a);
	else if (third < first && first < second)
		a_sort_2_3_1(a);
	else if (second < third && third < first)
		a_sort_3_1_2(a);
	else if (third < second && second < first)
		a_sort_3_2_1(a);
	return (1);
}

int	sort_two_in_a(t_stk *a, int len)
{
	int	first;
	int	second;

	first = a->stack[len - 1].n;
	second = a->stack[len - 2].n;
	if (first < second)
		return (1);
	else
	{
		swap_stack(a, a->len);
		return (1);
	}
}

int	sort_three_in_b(t_stk *b, int len)
{
	int	first;
	int	second;
	int	third;

	first = b->stack[len - 1].n;
	second = b->stack[len - 2].n;
	third = b->stack[len - 3].n;
	if (first < second && second < third)
		b_sort_1_2_3(b);
	else if (first < third && third < second)
		b_sort_1_3_2(b);
	else if (second < first && first < third)
		b_sort_2_1_3(b);
	else if (third < first && first < second)
		b_sort_2_3_1(b);
	else if (second < third && third < first)
		b_sort_3_1_2(b);
	return (1);
}

int	sort_two_in_b(t_stk *b, int len)
{
	if (b->stack[len - 1].n > b->stack[len - 2].n)
		return (1);
	else
	{
		swap_stack(b, b->len);
		return (1);
	}
}
