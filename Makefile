# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yobougre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 13:32:09 by yobougre          #+#    #+#              #
#    Updated: 2022/02/05 14:46:09 by yobougre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=	srcs/pipex.c

INCL=	includes/pipex.h

NAME=	pipex

CFLAGS= -Wall -Werror -Wextra

CC=	gcc

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
