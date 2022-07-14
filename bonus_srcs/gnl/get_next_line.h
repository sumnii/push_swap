/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:58:25 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/13 19:04:58 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../../libft/libft.h"

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
# endif
# define FD_MAX 10240

char	*get_next_line(int fd);
char	*ft_read_buf(int fd, char **save);
char	*ft_cut_line(char **line, char **save);
char	*ft_cut_save(char **save);
void	*ft_close(char **line, char **save);

size_t	gnl_strlen(char *str);
int		ft_find_lf(char *str);
char	*gnl_strjoin(char **line, char **buf);
char	*ft_idx_dup(char *str, size_t i, size_t j);

#endif