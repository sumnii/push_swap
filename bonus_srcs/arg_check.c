/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:00:41 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/22 17:59:17 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	arg_check(char **split, int i, int j, t_stk a)
{
	if (!int_range_check(split[i]))
		return (0);
	else if (!dup_check(a.stack, a.len, j))
		return (0);
	else if (!atoi_error_check(split[i], a.stack[j]))
		return (0);
	else if (!sort_check(a.stack, j, a.len))
		return (0);
	else
		return (1);
}

int	int_range_check(char *str)
{
	if ((ft_strlen(str) == 10 && str[0] != '-'
			&& ft_strncmp("2147483647", str, 10) < 0)
		|| (ft_strlen(str) == 11 && str[0] == '-'
			&& ft_strncmp("-2147483648", str, 11) < 0)
		|| (ft_strlen(str) > 11))
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

int	sort_check(t_nb *stack, int j, int len)
{
	static int	flag = 0;

	if (j == len - 1)
		return (1);
	if (stack[j].n < stack[j + 1].n)
		flag = 1;
	if (j == 0)
		return (flag);
	else
		return (1);
}
