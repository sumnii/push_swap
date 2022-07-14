/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:29:24 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/13 19:01:27 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "bonus_srcs/gnl/get_next_line.h"

typedef struct s_nb {
	int	n;
	int	flag;
}				t_nb;

typedef struct s_stk {
	t_nb	*stack;
	int		len;
	char	name;
}				t_stk;

void	checker_init(t_stk **a, t_stk **b, int argc, char **argv);
t_stk	*struct_init(void);
void	check_sort(t_stk *a, t_stk *b);
void	ft_exit(t_stk *stack_a, t_stk *stack_b, int flag);

int		arg_check(char **split, int i, int j, t_stk a);
int		int_range_check(char *str);
int		atoi_error_check(char *str, t_nb nb);
int		dup_check(t_nb *stack, int s_len, int idx);
int		sort_check(t_nb *stack, int j, int len);

int		count_args(int argc, char **argv);
int		make_stack_a(t_stk *stack_a, int argc, char **argv);
int		make_stack_b(t_stk *stack_b, int len);
void	free_split(char **split);
int		error_return(t_stk *a, char **split);

void	operate_stack(t_stk *a, t_stk *b, char *buf);

void	swap_stack(t_stk *a, int a_len, t_stk *b, int b_len);
void	push_stack(t_stk *stack_f, t_stk *stack_t);
void	rotate_stack(t_stk *a, int a_len, t_stk *b, int b_len);
void	reverse_rotate_stack(t_stk *a, int a_len, t_stk *b, int b_len);
void	swap_a_b(int *a, int *b);

void	print_stack(t_stk a, t_stk b); // for testing func
void	test_operator(t_stk a, t_stk b); // for testing func

#endif