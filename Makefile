# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yobougre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 13:32:09 by yobougre          #+#    #+#              #
#    Updated: 2022/03/10 16:14:53 by yobougre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=	srcs/pipex.c\
		srcs/utils_str.c\
		srcs/utils_path.c\
		srcs/ft_free.c\
		srcs/ft_split_path.c\
		srcs/ft_split.c\
		srcs/utils_pipe.c\
		srcs/utils_exec.c\
		srcs/error.c\
		srcs/gnl.c\
		srcs/utils_both.c\
		srcs/join.c

SRCS_BONUS=	srcs/pipex_bonus.c\
			srcs/utils_str.c\
			srcs/utils_both.c\
			srcs/utils_path.c\
			srcs/ft_free.c\
			srcs/ft_split_path.c\
			srcs/ft_split.c\
			srcs/utils_pipe.c\
			srcs/utils_exec.c\
			srcs/error.c\
			srcs/gnl.c\
			srcs/join.c

INCL=	includes/pipex.h\
		includes/includes.h\
		includes/struct.h

NAME=	pipex

BONUS_NAME=	pipex_bonus

CFLAGS= -Wall -Werror -Wextra -g3

CC=	gcc

OBJS=	$(SRCS:.c=.o)

OBJS_BONUS=		$(SRCS_BONUS:.c=.o)

RM=	rm -f

all:	$(NAME)


$(NAME): $(OBJS) $(INCL)
		 $(CC) $(CFLAGS) $(OBJS) $(INCL) -o $(NAME)

bonus:	$(BONUS_NAME)

$(BONUS_NAME): $(OBJS_BONUS) $(INCL)
				$(CC) $(CFLAGS) $(OBJS_BONUS) $(INCL) -o $(BONUS_NAME)

clean:	
		$(RM) $(OBJS) $(OBJS_BONUS)
fclean: 
		$(RM) $(OBJS) $(OBJS_BONUS) $(NAME) $(BONUS_NAME)

re:	fclean all

.PHONY: fclean clean re all bonus
