# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 23:33:09 by sumsong           #+#    #+#              #
#    Updated: 2022/06/25 23:40:17 by sumsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
# NAME_BONUS	=	so_long_bonus

CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra
AR				=	ar rcs
RM				=	rm -f

SRC_DIR			=	./
PRINTF_DIR		=	./ft_printf/

PRINTF_FLAGS	=	-L$(PRINTF_DIR) -lftprintf

SRC				=	main.c
# BONUS_SRC		=	main_bonus.c

SRCS			=	$(addprefix $(SRC_DIR), $(SRC))
OBJS			=	$(SRCS:.c=.o)

# BONUS_SRCS	=	$(addprefix $(SRC_DIR), $(BONUS_SRC))
# BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)


all: $(NAME)

clean:
	make -C $(PRINTF_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(PRINTF_DIR) fclean
	$(RM) $(NAME)

re: clean all

# bonus: $(NAME_BONUS)

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $?

$(NAME): $(OBJS)
	make -C $(PRINTF_DIR)
	$(CC) -o $@ $(PRINTF_FLAGS) $(OBJS)

# $(NAME_BONUS): $(BONUS_OBJS)
# 	make -C $(PRINTF_DIR)
# 	$(CC) -o $@ $(FTPRINTF_FLAGS) $(BONUS_OBJS)

PHONY: all clean fclean re