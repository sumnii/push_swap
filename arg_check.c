/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:00:41 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/06 16:32:55 by sumsong          ###   ########.fr       */
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

int	int_range_check(char *str)
{
	if ((ft_strlen(str) == 10 && str[0] != '-'
			&& ft_strncmp("2147483647", str, 10) < 0)
		|| (ft_strlen(str) == 11 && str[0] == '-'
			&& ft_strncmp("-2147483648", str, 11) < 0))
		return (0);
	else
		return (1);
}

int	atoi_error_check(char *str, t_nb nb)
{
	if (*str != '0' && nb.n == 0)
		return (0);
	return (1);
}

int	dup_check(t_nb *stack, int s_len, int idx)
{
	int	i;

	i = s_len - 1;
	while (idx < i)
	{
		if (stack[i].n == stack[idx].n)
			return (0);
		--i;
	}
	return (1);
}
