/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:04:50 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/13 18:54:42 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	main(int argc, char **argv)
{
	t_stk	*a;
	t_stk	*b;
	char	*buf;

	if (argc < 2)
		exit (0);
	checker_init(&a, &b, argc, argv);
	// print_stack(*a, *b);
	while (1)
	{
		buf = (char *)ft_calloc(4, sizeof(char));
		if (!read(0, buf, 4))
		{
			// print_stack(*a, *b);
			check_sort(a, b);
			ft_exit(a, b, 0);
		}
		operate_stack(a, b, buf);
		// print_stack(*a, *b);
	}
	ft_exit(a, b, 0);
}

void	checker_init(t_stk **a, t_stk **b, int argc, char **argv)
{
	*a = struct_init();
	*b = struct_init();
	if (!(*a) || !(*b))
		ft_exit(*a, *b, 1);
	(*a)->len = count_args(argc, argv);
	if ((*a)->len == 0)
		ft_exit(*a, *b, 1);
	if (!make_stack_a(*a, argc, argv))
		ft_exit(*a, *b, 1);
	if (!make_stack_b(*b, (*a)->len))
		ft_exit(*a, *b, 1);
	(*b)->len = 0;
}

t_stk	*struct_init(void)
{
	t_stk	*stk;

	stk = (t_stk *)malloc(sizeof(t_stk));
	if (!stk)
		return (NULL);
	return (stk);
}

void	check_sort(t_stk *a, t_stk *b)
{
	int	i;

	if (b->len != 0)
	{
		write(1, "KO\n", 3);
		return ;
	}
	i = a->len - 1;
	while (a->len - 1 > 0)
	{
		if (a->stack[i].n < a->stack[i - 1].n)
			--i;
		else
		{
			write(1, "KO\n", 3);
			return ;
		}
		--(a->len);
	}
	write(1, "OK\n", 3);
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
