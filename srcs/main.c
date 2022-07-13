/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:05:52 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/13 17:57:46 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stk	*a;
	t_stk	*b;

	if (argc < 2)
		return (ft_printf("Error\n"));
	a = struct_init();
	b = struct_init();
	if (!a || !b)
		ft_exit(a, b, 1);
	a->len = count_args(argc, argv);
	if (a->len == 0)
		ft_exit(a, b, 1);
	if (!make_stack_a(a, argc, argv))
		ft_exit(a, b, 1);
	if (!make_stack_b(b, a->len))
		ft_exit(a, b, 1);
	b->len = 0;
	if (a->len == 3)
		sort_3_arg(a, a->len);
	else if (a->len == 5)
		sort_5_arg(a, b, a->len);
	else
		a_to_b(a, b, a->len);
	ft_exit(a, b, 0);
}

t_stk	*struct_init(void)
{
	t_stk	*stk;

	stk = (t_stk *)malloc(sizeof(t_stk));
	if (!stk)
		return (NULL);
	return (stk);
}

void	ft_exit(t_stk *stack_a, t_stk *stack_b, int flag)
{
	if (stack_a->stack)
		free(stack_a->stack);
	if (stack_a)
		free(stack_a);
	if (stack_b->stack)
		free(stack_b->stack);
	if (stack_b)
		free(stack_b);
	if (flag == 1)
		write(2, "Error\n", 6);
	exit (1);
}
