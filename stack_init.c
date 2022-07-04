/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:52:50 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/05 00:24:59 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_stack_a(t_stk *a, int argc, char **argv)
{
	static int	i = -1;
	int			j;
	char		**split;

	a->stack = (t_nb *)malloc(a->len * sizeof(t_nb));
	if (!(a->stack))
		return (0);
	a->name = 'a';
	j = a->len - 1;
	while (--argc)
	{
		split = ft_split(*(++argv), ' ');
		i = -1;
		while (split[++i])
		{
			a->stack[j].n = ft_atoi(split[i]);
			if (!int_range_check(split[i]) || !dup_check(a->stack, a->len, j)
				|| !atoi_error_check(split[i], a->stack[j]))
				return (error_return(a->stack, split));
			--j;
		}
		free_split(split);
	}
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

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
			free(split[i++]);
		free(split);
	}
}

int	error_return(t_nb *stack, char **split)
{
	int	i;

	if (stack)
		free(stack);
	i = 0;
	while (split[i])
		free(split[++i]);
	free(split);
	return (0);
}
