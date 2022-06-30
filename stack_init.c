/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:52:50 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/30 15:06:10 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*make_stack_a(int len, char **argv)
{
	int	*stack_a;
	int	i;
	int	j;

	stack_a = (int *)malloc(len * sizeof(int));
	if (!stack_a)
		return (NULL);
	i = -1;
	j = len - 1;
	while (++i < len)
	{
		stack_a[i] = ft_atoi(argv[j]);
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
