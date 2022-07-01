/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivoting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:44:02 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/01 14:59:56 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pivoting(t_stack *the, int p, t_stack *other)
{
	int	pivot;
	int	i;
	int	flag;

	pivot = the->stack[p];
	ft_printf("pivot : %d, the : %d, other : %d\n", pivot, the->len, other->len);
	i = the->len;
	flag = 0;
	while (the->stack[--i])
	{
		ft_printf("stack[%d] : %d\n", i, the->stack[i]);
		if (the->stack[i] <= pivot)
		{
			if (flag == 0)
				++flag;
			push_stack(the->stack, other->stack, &(the->len), &(other->len));
		}
		else if (the->stack[i] > pivot)
			rotate_stack(the->stack, other->len);
	}
	ft_printf("len : %d %d\n", the->len, other->len);
}
