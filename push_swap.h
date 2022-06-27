/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:30:27 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/27 13:23:45 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

int		*make_stack_a(int len, char **argv);
int		*make_stack_b(int len);
int		dup_check(int *stack, int idx);
void	print_stack(int *stack_a, int *stack_b, int len_a, int len_b); // tmp func

void	swap_stack(int *stack, int len);
void	push_stack(int *stack_from, int *stack_to, int *len_from, int *len_to);
void	rotate_stack(int *stack);
void	reverse_rotate_stack(int *stack);

void	swap_a_b(int *a, int *b);

#endif