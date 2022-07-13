/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:19:18 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/13 18:53:47 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	operate_stack(t_stk *a, t_stk *b, char *buf)
{
	if (!ft_strncmp(buf, "sa\n", 3))
		swap_stack(a, a->len, NULL, 0);
	else if (!ft_strncmp(buf, "sb\n", 3))
		swap_stack(NULL, 0, b, b->len);
	else if (!ft_strncmp(buf, "ss\n", 3))
		swap_stack(a, a->len, b, b->len);
	else if (!ft_strncmp(buf, "pa\n", 3))
		push_stack(b, a);
	else if (!ft_strncmp(buf, "pb\n", 3))
		push_stack(a, b);
	else if (!ft_strncmp(buf, "ra\n", 3))
		rotate_stack(a, a->len, NULL, 0);
	else if (!ft_strncmp(buf, "rb\n", 3))
		rotate_stack(NULL, 0, b, b->len);
	else if (!ft_strncmp(buf, "rr\n", 3))
		rotate_stack(a, a->len, b, b->len);
	else if (!ft_strncmp(buf, "rra\n", 4))
		reverse_rotate_stack(a, a->len, NULL, 0);
	else if (!ft_strncmp(buf, "rrb\n", 4))
		reverse_rotate_stack(NULL, 0, b, b->len);
	else if (!ft_strncmp(buf, "rrr\n", 4))
		reverse_rotate_stack(a, a->len, b, b->len);
	free(buf);
}
