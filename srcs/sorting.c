/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:44:02 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/14 14:53:36 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	a_to_b(t_stk *a, t_stk *b, int cnt)
{
	t_opr		opr;

	if (cnt <= 3)
	{
		hard_sort_in_a(a, a->len, cnt);
		return ;
	}
	opr.ra = 0;
	opr.pb = 0;
	opr.rb = 0;
	if (!(a_is_sorted(a, cnt)))
	{
		a_to_b_dividing(a, b, cnt, &opr);
		rrr_stack(a, b, opr);
	}
	a_to_b(a, b, opr.ra);
	b_to_a(a, b, opr.rb);
	b_to_a(a, b, opr.pb - opr.rb);
}

void	b_to_a(t_stk *a, t_stk *b, int cnt)
{
	t_opr		opr;

	if (cnt <= 3)
	{
		hard_sort_in_b(a, b, b->len, cnt);
		return ;
	}
	opr.pa = 0;
	opr.rb = 0;
	opr.ra = 0;
	b_to_a_dividing(a, b, cnt, &opr);
	a_to_b(a, b, opr.pa - opr.ra);
	rrr_stack(a, b, opr);
	a_to_b(a, b, opr.ra);
	b_to_a(a, b, opr.rb);
}
