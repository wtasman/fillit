
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wasman <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/21 09:26:58 by wasman            #+#    #+#              #
#    Updated: 2016/09/21 13:37:49 by wasman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = fillit

SOURCES =	libft.a\
			read.c\
			test.c\
			ft_btoi.c\
			is_valid.c\
			classify.c

OBJ =	$(SOURCES:.c=.o)

.PHONY: all norm clean fclean re

$(NAME):
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

all: $(NAME)

norm: fclean
	norminette $(SOURCES)

clean:
	/bin/rm -f $(NAME)

fclean: clean
	/bin/rm -f rm $(NAME)

re: fclean all
