# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 23:33:09 by sumsong           #+#    #+#              #
#    Updated: 2022/08/02 18:28:34 by sumsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
BONUS			=	checker

CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra
AR				=	ar rcs
RM				=	rm -f

SRC_DIR			=	./srcs/
LIBFT_DIR		=	./libft/
PRINTF_DIR		=	./ft_printf/
BONUS_DIR		=	./bonus_srcs/

LIBFT_FLAGS		=	-L$(LIBFT_DIR) -lft
PRINTF_FLAGS	=	-L$(PRINTF_DIR) -lftprintf

SRC				=	main.c arg_check.c stack_init.c \
					3_5_arg_sort.c operator.c sorting.c sorting_utils.c \
					hard_sort_in_a.c hard_sort_in_b.c \
					a3_hard_sort.c b3_hard_sort.c \
					testing.c
# testing.c should be deleted.

BONUS_SRC		=	main.c arg_check.c stack_init.c \
					operate_stack.c operator.c \
					gnl/get_next_line.c gnl/get_next_line_utils.c \
					testing.c
# testing.c should be deleted.

SRCS			=	$(addprefix $(SRC_DIR), $(SRC))
OBJS			=	$(SRCS:.c=.o)
BONUS_SRCS		=	$(addprefix $(BONUS_DIR), $(BONUS_SRC))
BONUS_OBJS		=	$(BONUS_SRCS:.c=.o)

all: $(NAME)

clean:
	make -C $(PRINTF_DIR) clean
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	make -C $(PRINTF_DIR) fclean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) $(BONUS)

re: fclean all

bonus: $(BONUS)

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $?

$(NAME): $(OBJS)
	make -C $(PRINTF_DIR)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $@ $(LIBFT_FLAGS) $(PRINTF_FLAGS) $(OBJS)

$(BONUS): $(BONUS_OBJS)
	make -C $(PRINTF_DIR)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $@ $(LIBFT_FLAGS) $(PRINTF_FLAGS) $(BONUS_OBJS)

PHONY: all clean fclean re bonus
