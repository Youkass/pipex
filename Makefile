# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yobougre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 13:32:09 by yobougre          #+#    #+#              #
#    Updated: 2022/02/22 14:32:28 by yobougre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=	srcs/pipex.c\
		srcs/utils_str.c\
		srcs/utils_path.c\
		srcs/utils_path_2.c\
		srcs/ft_free.c\
		srcs/ft_split_path.c\
		srcs/ft_split.c\
		srcs/utils_pipe.c\
		srcs/utils_exec.c

INCL=	includes/pipex.h

NAME=	pipex

CFLAGS= -Wall -Werror -Wextra -g3

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

#--track -fds=is
#--trace -children=is
#-q
