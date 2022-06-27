/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:05:52 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/27 12:51:49 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	len;

	if (argc < 2)
		return (ft_printf("Error\n"));
	len = argc - 1;
	stack_a = make_stack_a(len, argv);
	if (!stack_a)
		return (ft_printf("Error\n"));
	swap_stack(stack_a, len);
	int	j = 6;
	while (--j >= 0)
		ft_printf("%d\n", stack_a[j]);
	ft_printf("-\na \n");
	free(stack_a);
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
	j = len;
	while (--j >= 0)
		ft_printf("%d\n", stack_a[j]);
	ft_printf("-\na \n\na is made!\n\n");
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
