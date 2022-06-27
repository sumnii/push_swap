/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:05:52 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/27 13:06:57 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	len;

	if (argc < 2)
		return (ft_printf("Error\n"));
	len = argc - 1;
	stack_a = make_stack_a(len, argv);
	if (!stack_a)
		return (ft_printf("Error\n"));
	stack_b = make_stack_b(len);
	if (!stack_b)
		return (ft_printf("Error\n"));
	print_stack(stack_a, stack_b, len);
	swap_stack(stack_a, len);
	print_stack(stack_a, stack_b, len);
	free(stack_a);
	free(stack_b);
	return (0);
}

int	*make_stack_a(int len, char **argv)
{
	int	*stack_a;
	int	i;
	int	j;

	stack_a = (int *)malloc(len * sizeof(int));
	if (!stack_a)
		return (NULL);
	i = 0;
	j = len - 1;
	while (++i <= len)
	{
		stack_a[j] = ft_atoi(argv[i]);
		if ((*(argv[i]) != '0' && stack_a[j] == 0) || dup_check(stack_a, j))
		{
			free(stack_a);
			return (NULL);
		}
		--j;
	}
	return (stack_a);
}

int	*make_stack_b(int len)
{
	int	*stack_b;

	stack_b = (int *)malloc(len * sizeof(int));
	if (!stack_b)
		return (NULL);
	return (stack_b);
}

int	dup_check(int *stack, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		if (stack[i] == stack[idx])
			return (1);
		++i;
	}
	return (0);
}

// This is temporary func for checking stack status.
void	print_stack(int *stack_a, int *stack_b, int len)
{
	while (--len >= 0)
		ft_printf("%d %d\n", stack_a[len], stack_b[len]);
	ft_printf("- -\na b\n");
}
