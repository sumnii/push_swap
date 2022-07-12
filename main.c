/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:05:52 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/12 23:37:57 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (!make_stack_a(a, argc, argv))
		ft_exit(a, b, 1);
	if (!make_stack_b(b, a->len))
		ft_exit(a, b, 1);
	b->len = 0;
	a_to_b(a, b, a->len);
	// print_stack(*a, *b);
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
		ft_printf("Error\n");
	exit (1);
}
