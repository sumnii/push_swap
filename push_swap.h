/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:30:27 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/01 15:47:15 by sumsong          ###   ########.fr       */
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

void	ft_exit(t_nb *stack_a, t_nb *stack_b, int flag);
void	print_stack(t_stk a, t_stk b); // tmp func
void	test_operator(t_stk a, t_stk b); // func

int		make_stack_a(t_stk *stack_a, char **argv);
int		make_stack_b(t_stk *stack_b, int len);
int		dup_check(t_nb *stack, int idx);
int		error_return(t_nb *stack);

void	swap_stack(t_stk stack, int len);
void	push_stack(t_stk stack_f, t_stk stack_t, int *len_f, int *len_t);
void	rotate_stack(t_stk stack, int len);
void	reverse_rotate_stack(t_stk stack, int len);

void	swap_a_b(int *a, int *b);

void	pivoting(t_stk *stack, int p, t_stk *target);

#endif