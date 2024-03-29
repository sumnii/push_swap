/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:30:27 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/26 21:29:43 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_nb {
	int	n;
	int	flag;
}				t_nb;

typedef struct s_stk {
	t_nb	*stack;
	int		len;
	char	name;
}				t_stk;

typedef struct s_pivot {
	int	s;
	int	l;
}				t_pivot;

typedef struct s_opr {
	int	pa;
	int	pb;
	int	ra;
	int	rb;
}				t_opr;

t_stk	*struct_init(void);
void	stack_init(t_stk **a, t_stk **b, int argc, char **argv);
void	ft_exit(t_stk *stack_a, t_stk *stack_b, int flag);

int		arg_check(char **split, int i, int j, t_stk a);
int		int_range_check(char *str);
int		atoi_error_check(char *str, t_nb nb);
int		dup_check(t_nb *stack, int s_len, int idx);
int		sorted_arg_check(t_nb *stack, int len);

int		count_args(int argc, char **argv);
int		make_stack_a(t_stk *stack_a, int argc, char **argv);
int		make_stack_b(t_stk *stack_b, int len);
void	free_split(char **split);
int		error_return(t_stk *a, char **split);

void	swap_stack(t_stk *stack, int len);
void	push_stack(t_stk *stack_f, t_stk *stack_t);
void	rotate_stack(t_stk stack, int len);
void	reverse_rotate_stack(t_stk *a, int a_len, t_stk *b, int b_len);
void	swap_a_b(int *a, int *b);

void	a_to_b(t_stk *a, t_stk *b, int cnt);
void	b_to_a(t_stk *a, t_stk *b, int cnt);

int		a_is_sorted(t_stk *a, int cnt);
void	a_to_b_dividing(t_stk *a, t_stk *b, int cnt, t_opr *opr);
void	b_to_a_dividing(t_stk *a, t_stk *b, int cnt, t_opr *opr);
void	pivoting(t_stk *stk, int set_len, t_pivot *pv);
void	rrr_stack(t_stk *a, t_stk *b, t_opr opr);

int		hard_sort_in_a(t_stk *a, int len, int cnt);
int		sort_three_in_a(t_stk *a, int len);
int		sort_two_in_a(t_stk *a, int len);

int		hard_sort_in_b(t_stk *a, t_stk *b, int len, int cnt);
int		sort_three_in_b(t_stk *a, t_stk *b, int len);
int		sort_two_in_b(t_stk *b, int len);

void	a_sort_1_3_2(t_stk *a);
void	a_sort_2_1_3(t_stk *a);
void	a_sort_2_3_1(t_stk *a);
void	a_sort_3_1_2(t_stk *a);
void	a_sort_3_2_1(t_stk *a);

void	b_sort_1_2_3(t_stk *a, t_stk *b);
void	b_sort_1_3_2(t_stk *a, t_stk *b);
void	b_sort_2_1_3(t_stk *a, t_stk *b);
void	b_sort_2_3_1(t_stk *a, t_stk *b);
void	b_sort_3_1_2(t_stk *a, t_stk *b);

void	sort_3_arg(t_stk *a, int len);
void	sort_5_arg(t_stk *a, t_stk *b, int len);

void	print_stack(t_stk a, t_stk b); // for testing func
void	test_operator(t_stk a, t_stk b); // for testing func

#endif
