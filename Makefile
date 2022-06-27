# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 23:33:09 by sumsong           #+#    #+#              #
#    Updated: 2022/06/27 14:53:31 by sumsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
# NAME_BONUS	=	so_long_bonus

CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra
AR				=	ar rcs
RM				=	rm -f

SRC_DIR			=	./
LIBFT_DIR		=	./libft/
PRINTF_DIR		=	./ft_printf/

LIBFT_FLAGS		=	-L$(LIBFT_DIR) -lft
PRINTF_FLAGS	=	-L$(PRINTF_DIR) -lftprintf

SRC				=	main.c stack_init.c operator.c operator_utils.c
# BONUS_SRC		=	main_bonus.c

SRCS			=	$(addprefix $(SRC_DIR), $(SRC))
OBJS			=	$(SRCS:.c=.o)

# BONUS_SRCS	=	$(addprefix $(SRC_DIR), $(BONUS_SRC))
# BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)


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

# bonus: $(NAME_BONUS)

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $?

$(NAME): $(OBJS)
	make -C $(PRINTF_DIR)
	make -C $(LIBFT_DIR)
	$(CC) -o $@ $(LIBFT_FLAGS) $(PRINTF_FLAGS) $(OBJS)

# $(NAME_BONUS): $(BONUS_OBJS)
# 	make -C $(PRINTF_DIR)
# 	$(CC) -o $@ $(FTPRINTF_FLAGS) $(BONUS_OBJS)

PHONY: all clean fclean re