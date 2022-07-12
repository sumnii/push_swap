# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 23:33:09 by sumsong           #+#    #+#              #
#    Updated: 2022/07/12 23:53:11 by sumsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra
AR				=	ar rcs
RM				=	rm -f

SRC_DIR			=	./
LIBFT_DIR		=	./libft/
PRINTF_DIR		=	./ft_printf/

LIBFT_FLAGS		=	-L$(LIBFT_DIR) -lft
PRINTF_FLAGS	=	-L$(PRINTF_DIR) -lftprintf

SRC				=	main.c arg_check.c stack_init.c \
					operator.c operator_utils.c \
					sorting.c hard_sort_in_a.c hard_sort_in_b.c \
					a3_hard_sort.c b3_hard_sort.c \
					3_arg_sort.c \
					testing.c

SRCS			=	$(addprefix $(SRC_DIR), $(SRC))
OBJS			=	$(SRCS:.c=.o)

all: $(NAME)

clean:
	make -C $(PRINTF_DIR) clean
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(PRINTF_DIR) fclean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: clean all

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $?

$(NAME): $(OBJS)
	make -C $(PRINTF_DIR)
	make -C $(LIBFT_DIR)
	$(CC) -o $@ $(LIBFT_FLAGS) $(PRINTF_FLAGS) $(OBJS)

PHONY: all clean fclean re