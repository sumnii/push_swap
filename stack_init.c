/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:52:50 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/04 23:43:10 by sumsong          ###   ########.fr       */
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

int	make_stack_a(t_stk *stack_a, int argc, char **argv)
{
	t_nb	*new;
	int		i;
	int		j;
	int		k;
	char	**split;

	new = (t_nb *)malloc(stack_a->len * sizeof(t_nb));
	if (!new)
		return (0);
	stack_a->name = 'a';
	i = -1;
	j = stack_a->len - 1;
	k = 0;
	while (k < argc - 1)
	{
		split = ft_split(argv[++k], ' ');
		i = -1;
		while (split[++i])
		{
			if ((ft_strlen(split[i]) == 10 && split[i][0] != '-'
				&& ft_strncmp("2147483647", split[i], 10) < 0)
			|| (ft_strlen(split[i]) == 11 && split[i][0] == '-'
			&& ft_strncmp("-2147483648", split[i], 11) < 0))
				return (error_return(new, split));
			new[j].n = ft_atoi(split[i]);
			if ((*(split[i]) != '0' && new[j].n == 0)
				|| dup_check(new, stack_a->len, j))
				return (error_return(new, split));
			--j;
		}
		free_split(split);
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

int	dup_check(t_nb *stack, int s_len, int idx)
{
	int	i;

	i = s_len - 1;
	while (idx < i)
	{
		if (stack[i].n == stack[idx].n)
			return (1);
		--i;
	}
	return (0);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split++);
	free(split);
}

int	error_return(t_nb *stack, char **split)
{
	if (stack)
		free(stack);
	if (split)
	{
		while (*split)
		{
			free(*split);
			++split;
		}
		free(split);
	}
	return (0);
}
