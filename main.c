/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:05:52 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/26 01:57:45 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*stack_a;

	if (argc < 2)
		return (ft_printf("Error\n"));
	stack_a = make_stack_a(argc, argv);
	if (!stack_a)
		return (ft_printf("Error\n"));
	swap_stack(&stack_a);
	int	j = 6;
	while (--j >= 0)
		ft_printf(" %d\n", stack_a[j]);
	ft_printf("---\n a \n");
	free(stack_a);
	return (0);
}

int	*make_stack_a(int argc, char **argv)
{
	int	*stack_a;
	int	i;
	int	j;

	stack_a = (int *)malloc(sizeof(int) * argc - 1);
	if (!stack_a)
		return (NULL);
	i = 0;
	j = 0;
	while (++i < argc)
	{
		stack_a[j] = ft_atoi(argv[i]);
		if ((*(argv[i]) != '0' && stack_a[j] == 0) || dup_check(stack_a, j))
		{
			free(stack_a);
			return (NULL);
		}
		++j;
	}
	while (--j >= 0)
		ft_printf(" %d\n", stack_a[j]);
	ft_printf("---\n a \n\n");
	return (stack_a);
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
