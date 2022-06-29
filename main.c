/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:05:52 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/29 18:23:54 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	len_a;
	int	len_b;

	if (argc < 2)
		return (ft_printf("Error\n"));
	len_a = argc - 1;
	stack_a = make_stack_a(len_a, argv);
	if (!stack_a)
		return (ft_printf("Error\n"));
	stack_b = make_stack_b(len_a);
	len_b = 0;
	if (!stack_b)
		ft_exit(stack_a, stack_b, 1);
	test_operator(stack_a, stack_b, len_a, len_b);
	ft_exit(stack_a, stack_b, 0);
	return (0);
}

void	ft_exit(int *stack_a, int *stack_b, int flag)
{
	if (stack_a && *stack_a)
		free(stack_a);
	if (stack_b && *stack_b)
		free(stack_b);
	if (flag == 1)
		ft_printf("Error\n");
	exit (1);
}

// This is temporary func for checking stack status.
void	print_stack(int *stack_a, int *stack_b, int len_a, int len_b)
{
	--len_a;
	--len_b;
	while (len_a >= 0 || len_b >= 0)
	{
		if (len_a >= len_b)
		{
			if (len_a >= 0 && len_b == len_a)
				ft_printf("%d %d\n", stack_a[len_a--], stack_b[len_b--]);
			else
				ft_printf("%d\n", stack_a[len_a--]);
		}
		else if (len_b > len_a)
		{
			if (len_b >= 0 && len_b == len_a)
				ft_printf("%d %d\n", stack_a[len_a--], stack_b[len_b--]);
			else
				ft_printf("  %d\n", stack_b[len_b--]);
		}
	}
	ft_printf("- -\na b\n\n");
}

void	test_operator(stack_a, stack_b, len_a, len_b)
{
	print_stack(stack_a, stack_b, len_a, len_b);
	swap_stack(stack_a, len_a);
	print_stack(stack_a, stack_b, len_a, len_b);
	push_stack(stack_a, stack_b, &len_a, &len_b);
	push_stack(stack_a, stack_b, &len_a, &len_b);
	push_stack(stack_a, stack_b, &len_a, &len_b);
	print_stack(stack_a, stack_b, len_a, len_b);
	rotate_stack(stack_a, len_a);
	rotate_stack(stack_b, len_b);
	print_stack(stack_a, stack_b, len_a, len_b);
	reverse_rotate_stack(stack_a, len_a);
	reverse_rotate_stack(stack_b, len_b);
	print_stack(stack_a, stack_b, len_a, len_b);
	swap_stack(stack_a, len_a);
	print_stack(stack_a, stack_b, len_a, len_b);
	push_stack(stack_b, stack_a, &len_b, &len_a);
	push_stack(stack_b, stack_a, &len_b, &len_a);
	push_stack(stack_b, stack_a, &len_b, &len_a);
	print_stack(stack_a, stack_b, len_a, len_b);
}
