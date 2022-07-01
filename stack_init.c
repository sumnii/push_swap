/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:52:50 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/01 14:17:04 by sumsong          ###   ########.fr       */
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
	j = len;
	while (++i < len)
	{
		if ((ft_strlen(argv[j]) == 10 && argv[j][0] != '-'
			&& ft_strncmp("2147483647", argv[j], 10) < 0)
		|| (ft_strlen(argv[j]) == 11 && argv[j][0] == '-'
		&& ft_strncmp("-2147483648", argv[j], 11) < 0))
			return (error_return(stack_a));
		stack_a[i] = ft_atoi(argv[j]);
		if ((*(argv[j]) != '0' && stack_a[i] == 0) || dup_check(stack_a, i))
			return (error_return(stack_a));
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

int	*error_return(int *stack)
{
	if (stack)
		free(stack);
	return (NULL);
}
