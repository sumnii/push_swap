/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:52:50 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/01 18:34:56 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_stack_a(t_stk *stack_a, char **argv)
{
	t_nb	*new;
	int		i;
	int		j;

	new = (t_nb *)malloc(stack_a->len * sizeof(t_nb));
	if (!new)
		return (0);
	stack_a->name = 'a';
	i = -1;
	j = stack_a->len;
	while (++i < stack_a->len)
	{
		if ((ft_strlen(argv[j]) == 10 && argv[j][0] != '-'
			&& ft_strncmp("2147483647", argv[j], 10) < 0)
		|| (ft_strlen(argv[j]) == 11 && argv[j][0] == '-'
		&& ft_strncmp("-2147483648", argv[j], 11) < 0))
			return (error_return(new));
		new[i].n = ft_atoi(argv[j]);
		if ((*(argv[j]) != '0' && new[i].n == 0) || dup_check(new, i))
			return (error_return(new));
		--j;
	}
	(*stack_a).stack = new;
	return (1);
}

int	make_stack_b(t_stk *stack_b, int len)
{
	t_nb	*stack;

	stack = (t_nb *)malloc(len * sizeof(t_nb));
	if (!stack)
		return (0);
	stack_b->stack = stack;
	stack_b->name = 'b';
	return (1);
}

int	dup_check(t_nb *stack, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		if (stack[i].n == stack[idx].n)
			return (1);
		++i;
	}
	return (0);
}

int	error_return(t_nb *stack)
{
	if (stack)
		free(stack);
	return (0);
}
