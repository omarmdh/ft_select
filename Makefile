# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 18:04:20 by ommadhi           #+#    #+#              #
#    Updated: 2019/12/13 17:17:14 by ommadhi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	src/ft_select.c\
		src/ft_stock_args.c\
		src/ft_free_list.c\
		src/ft_print_args.c\
		src/ft_rev_col.c\
		src/ft_signal.c\
		src/ft_cursor_pisix.c\
		src/ft_max_len_word.c\
		src/ft_search.c\
		src/ft_save_pos.c\

OBJS    = $(SRCS:.c=.o)


NAME        = ft_select
CC			= gcc
CFLAGS      = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C libft
	gcc -ltermcap $(CFLAG) $(OBJS) libft/libft.a -o $(NAME)

clean :
	rm -rf $(OBJS)
	@make -C libft clean

fclean : clean
	rm -rf $(NAME)
	@make -C libft fclean

re : fclean all
