/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:52:50 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/11 15:15:10 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_args(int argc, char **argv)
{
	static int	i = 0;
	int			j;
	static int	cnt = 0;
	char		**res;

	while (++i < argc)
	{
		j = -1;
		res = ft_split(argv[i], ' ');
		if (!res)
			return (0);
		while (res[++j])
			++cnt;
		free_split(res);
	}
	return (cnt);
}

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
			if (!arg_check(split, i, j, *a))
				return (error_return(a, split));
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

int	error_return(t_stk *a, char **split)
{
	int	i;

	if (a->stack)
		free(a->stack);
	a->stack = NULL;
	i = 0;
	while (split[i])
		free(split[++i]);
	free(split);
	return (0);
}
