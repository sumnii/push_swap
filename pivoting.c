/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivoting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:44:02 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/01 15:50:54 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pivoting(t_stk *the, int p, t_stk *other)
{
	int	pivot;
	int	i;
	int	flag;

	pivot = the->stack[p].n;
	ft_printf("pivot : %d, the : %d, other : %d\n", pivot, the->len, other->len);
	i = the->len;
	flag = 0;
	while (the->stack[--i].n)
	{
		// ft_printf("stack[%d] : %d\n", i, the->stack[i].n);
		if (the->stack[i].n <= pivot)
		{
			if (flag == 0)
				++flag;
			push_stack(*the, *other, &(the->len), &(other->len));
		}
		else if (the->stack[i].n > pivot)
			rotate_stack(*the, the->len);
	}
	// ft_printf("len : %d %d\n", the->len, other->len);
}
