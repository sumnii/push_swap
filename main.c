/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:05:52 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/01 15:52:18 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stk	a;
	t_stk	b;

	if (argc < 2)
		return (ft_printf("Error\n"));
	a.len = argc - 1;
	if (!make_stack_a(&a, argv))
		return (ft_printf("Error\n"));
	if (!make_stack_b(&b, a.len))
		ft_exit(a.stack, b.stack, 1);
	b.len = 0;
	// pivoting(&a, a.len / 2, &b);
	// print_stack(a, b);
	test_operator(a, b);
	ft_exit(a.stack, b.stack, 0);
	return (0);
}

void	ft_exit(t_nb *stack_a, t_nb *stack_b, int flag)
{
	if (stack_a)
		free(stack_a);
	if (stack_b)
		free(stack_b);
	if (flag == 1)
		ft_printf("Error\n");
	exit (1);
}

// This is temporary func for checking stack status.
void	print_stack(t_stk a, t_stk b)
{
	--a.len;
	--b.len;
	ft_printf("\n");
	while (a.len >= 0 || b.len >= 0)
	{
		if (a.len >= b.len)
		{
			if (a.len >= 0 && b.len == a.len)
				ft_printf("%d %d\n", a.stack[a.len--], b.stack[b.len--]);
			else
				ft_printf("%d\n", a.stack[a.len--]);
		}
		else if (b.len > a.len)
		{
			if (b.len >= 0 && b.len == a.len)
				ft_printf("%d %d\n", a.stack[a.len--], b.stack[b.len--]);
			else
				ft_printf("  %d\n", b.stack[b.len--]);
		}
	}
	ft_printf("- -\na b\n\n");
}

void	test_operator(t_stk a, t_stk b)
{
	print_stack(a, b);
	swap_stack(a, a.len);
	print_stack(a, b);
	push_stack(a, b, &a.len, &b.len);
	push_stack(a, b, &a.len, &b.len);
	push_stack(a, b, &a.len, &b.len);
	print_stack(a, b);
	rotate_stack(a, a.len);
	rotate_stack(b, b.len);
	print_stack(a, b);
	reverse_rotate_stack(a, a.len);
	reverse_rotate_stack(b, b.len);
	print_stack(a, b);
	swap_stack(a, a.len);
	print_stack(a, b);
	push_stack(b, a, &b.len, &a.len);
	push_stack(b, a, &b.len, &a.len);
	push_stack(b, a, &b.len, &a.len);
	print_stack(a, b);
}
