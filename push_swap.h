/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:30:27 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/26 01:04:21 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

int		*make_stack_a(int argc, char **argv);
int		dup_check(int *stack, int idx);

void	swap_stack(int **stack);
void	push_stack(int *stack_f, int *stack_t);
void	rotate_stack(int *stack);
void	reverse_rotate_stack(int *stack);
void	swap_a_b(int *a, int *b);

#endif