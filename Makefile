# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yobougre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 13:32:09 by yobougre          #+#    #+#              #
#    Updated: 2022/02/09 13:41:02 by yuro4ka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=	srcs/pipex.c\
		srcs/utils_str.c\
		srcs/utils_path.c\
		srcs/ft_free.c\
		srcs/ft_split.c

INCL=	includes/pipex.h

NAME=	pipex

CFLAGS= -Wall -Werror -Wextra

CC=	gcc-11

OBJS=	$(SRCS:.c=.o)

RM=	rm -f

all:	$(NAME)

$(NAME): $(OBJS) $(INCL)
		 $(CC) $(CFLAGS) $(OBJS) $(INCL) -o $(NAME)

clean:	
		$(RM) $(OBJS)
fclean: 
		$(RM) $(OBJS) $(NAME)
re:	fclean all

.PHONY: fclean clean re all 
