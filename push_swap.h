/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:30:27 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/01 14:51:40 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_stack {
	int		*stack;
	int		len;
	char	name;
}				t_stack;

typedef struct s_int {
	int	n;
	int	flag;
}				t_int;

void	ft_exit(int *stack_a, int *stack_b, int flag);
void	print_stack(t_stack a, t_stack b); // tmp func
void	test_operator(t_stack a, t_stack b); // func

int		*make_stack_a(int len, char **argv);
int		*make_stack_b(int len);
int		dup_check(int *stack, int idx);
int		*error_return(int *stack);

void	swap_stack(int *stack, int len);
void	push_stack(int *stack_from, int *stack_to, int *len_from, int *len_to);
void	rotate_stack(int *stack, int len);
void	reverse_rotate_stack(int *stack, int len);

void	swap_a_b(int *a, int *b);

void	pivoting(t_stack *stack, int p, t_stack *target);

#endif