/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:42:17 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/03 22:42:59 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// This is temporary func for checking stack status.
void	print_stack(t_stk a, t_stk b)
{
	--a.len;
	--b.len;
	ft_printf("\n");
	while (a.len >= 0 || b.len >= 0)
	{
		if (a.len >= b.len)
		{
			if (a.len >= 0 && b.len == a.len)
			{
				ft_printf("%d[%d] %d[%d]\n", a.stack[a.len].n, a.stack[a.len].flag, b.stack[b.len].n, b.stack[b.len].flag);
				--b.len;
			}
			else
				ft_printf("%d[%d]\n", a.stack[a.len].n, a.stack[a.len].flag);
			--a.len;
		}
		else if (b.len > a.len)
		{
			if (b.len >= 0 && b.len == a.len)
			{
				ft_printf("%d[%d] %d[%d]\n", a.stack[a.len].n, a.stack[a.len].flag, b.stack[b.len]);
				--a.len;
			}
			else
				ft_printf("     %d[%d]\n", b.stack[b.len].n, b.stack[b.len].flag);
			--b.len;
		}
	}
	ft_printf("-    -\na    b\n\n");
}

/* void	test_operator(t_stk a, t_stk b)
{
	print_stack(a, b);
	swap_stack(a, a.len);
	print_stack(a, b);
	push_stack(a, b);
	push_stack(a, b);
	push_stack(a, b);
	print_stack(a, b);
	rotate_stack(a, a.len);
	rotate_stack(b, b.len);
	print_stack(a, b);
	reverse_rotate_stack(a, a.len);
	reverse_rotate_stack(b, b.len);
	print_stack(a, b);
	swap_stack(a, a.len);
	print_stack(a, b);
	push_stack(b, a);
	push_stack(b, a);
	push_stack(b, a);
	print_stack(a, b);
} */
