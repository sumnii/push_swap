/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:05:52 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/25 23:41:24 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;

	i = -1;
	printf("argc : %d\n", argc);
	while (i++ < argc)
		printf("argv[%d] : %s\n", i, argv[i]);
	return (0);
}
