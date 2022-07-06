/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:30:27 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/06 16:31:32 by sumsong          ###   ########.fr       */
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

t_stk	*struct_init(void);
void	ft_exit(t_stk *stack_a, t_stk *stack_b, int flag);

int		count_args(int argc, char **argv);
int		int_range_check(char *str);
int		atoi_error_check(char *str, t_nb nb);
int		dup_check(t_nb *stack, int s_len, int idx);

int		make_stack_a(t_stk *stack_a, int argc, char **argv);
int		make_stack_b(t_stk *stack_b, int len);
void	free_split(char **split);
int		error_return(t_stk *a, char **split);

void	swap_stack(t_stk *stack, int len);
void	push_stack(t_stk *stack_f, t_stk *stack_t);
void	rotate_stack(t_stk stack, int len);
void	reverse_rotate_stack(t_stk stack, int len);

void	swap_a_b(int *a, int *b);

void	pivoting_a(t_stk *a, t_stk *b, int cnt);
void	pivoting_b(t_stk *a, t_stk *b, int cnt);
void	hard_sort_in_a(t_stk *a, int len, int cnt);
void	hard_sort_in_b(t_stk *a, t_stk *b, int len, int cnt);

int		sort_three_in_a(t_stk *a, int len);
int		sort_two_in_a(t_stk *a, int len);
int		sort_three_in_b(t_stk *b, int len);
int		sort_two_in_b(t_stk *b, int len);

void	a_sort_1_3_2(t_stk *a);
void	a_sort_2_1_3(t_stk *a);
void	a_sort_2_3_1(t_stk *a);
void	a_sort_3_1_2(t_stk *a);
void	a_sort_3_2_1(t_stk *a);

void	b_sort_1_2_3(t_stk *b);
void	b_sort_1_3_2(t_stk *b);
void	b_sort_2_1_3(t_stk *b);
void	b_sort_2_3_1(t_stk *b);
void	b_sort_3_1_2(t_stk *b);

void	print_stack(t_stk a, t_stk b); // for testing func
void	test_operator(t_stk a, t_stk b); // for testing func

#endif