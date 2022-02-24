/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:34:10 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/23 17:39:37 by yobougre         ###   ########.fr       */
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
	struct s_node	*prev;
	int				index;
	int				fd[2];
	pid_t			pid;
	char		 	*path;
	char			**cmd_args;
} t_node;

void	ft_print_tab(char **tab);
void	ft_error(int in, int out);
void	__close(void);
void	ft_parse(char **av, char **envp, int ac, t_node **start);
/*================================================*/
/* Functions using pipe()			   			  */
/*file : utils_pipe.c		 					  */
int		fork_pipe(t_node *data, char **envp);
int		ft_filein(char *file);
int		ft_fileout(char *file);

/*================================================*/
/* Fill the execarg tab				   			  */
/*file : utils_exec.c		 					  */
int		ft_execute(char **av, char **envp);

/*================================================*/
/* Just read the proto name			   			  */
/*file : ft_split_path.c	 					  */
char	**ft_split_path(char const *s, char c);

/*================================================*/
/* Function for free, ft_free.c		 			  */
/*file : ft_free.c				 				  */
void	ft_free(char **tab);
int		ft_tab_size(char **tab);

/*================================================*/
/* Get the different possibles path				  */
/*file : utils_path.c							  */

char	*ft_cmd(char *path, char *cmd);
int		ft_cmp_path(char *s1, char *s2);
int		get_path_pos(char **envp);
char	**get_path_lst(char **envp);
char	*check_path(char **path_lst, char *cmd);

/*================================================*/
/*file : ft_lst.c							  	  */
void	ft_create_new_lst(t_node **start, int nb_cmd);
void	ft_lstclear(t_node **lst);
t_node	*ft_lstnew(int value);

/*================================================*/
/* Gestion des arguments et chaines de caracteres */
/*file : utils_str.c							  */

void	ft_copy(char **av, char **execarg);
int		ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*ft_strjoin_pimp(char *s1, char *s2);
char	**ft_split(char const *s, char c);
/*================================================*/
#endif
