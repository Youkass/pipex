/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:01:03 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/17 18:21:57 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct	s_node
{
	struct s_node	*next;
	int				index;
	char			*cmd_path;
	char			**args;
} t_node;
void	ft_print_tab(char **tab);

/* ************************************************************************** */
/*file : ft_lst.c															  */
t_node	*ft_lstnew(int value);
void	ft_lstadd_back(t_node **alst, t_node *new);
void	ft_lstclear(t_node **lst);
void	ft_create_new_lst(t_node **start, int nb_cmd);
/* ************************************************************************** */


/* ************************************************************************** */
/*file : utils_str.c														  */
int		ft_strlen(char *s);
char	*ft_strjoin_pimp(char *s1, char *s2);
char	*ft_strdup(char *s);
/* ************************************************************************** */


/* ************************************************************************** */
/*file : ft_split.c && ft_split_path.c										  */
char	**ft_split_path(char const *s, char c);
char	**ft_split(char const *s, char c);
/* ************************************************************************** */


/* ************************************************************************** */
/*file : ft_free.c														  	  */
int		ft_tab_size(char **tab);
void	*ft_free(char **output, int p);
/* ************************************************************************** */


/* ************************************************************************** */
/*file : utils_path.c														  */
char	*check_path(char **path_lst, char *cmd);
char	**get_path_lst(char **envp);
int		get_path_pos(char **envp);
int		ft_cmp_path(char *s1, char *s2);
char	*ft_cmd(char *path, char *cmd);
/* ************************************************************************** */


/* ************************************************************************** */
/*file : utils_parse.c														  */
void	ft_fill_path(t_node **start, char **envp);
void	ft_get_args(t_node **start, char **av);
void	ft_print_tab(char **tab);
/* ************************************************************************** */
#endif
