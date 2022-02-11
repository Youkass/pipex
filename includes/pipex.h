/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:34:10 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/11 05:01:46 by yobougre         ###   ########.fr       */
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
	int				tab[2];
	int				id;
	struct s_node	*next;
} t_node;
void	ft_print_tab(char **tab);
/*================================================*/
/* Functions using pipe()			   			  */
/*file : utils_pipe.c		 					  */
int		fork_pipe(int nb, char **cmd, char ***execarg, char **envp);
int		ft_filein(char *file);
int		ft_fileout(char *file);

/*================================================*/
/* Fill the execarg tab				   			  */
/*file : utils_exec.c		 					  */
char	***ft_execution(char ***execarg, char **av, int ac);

/*================================================*/
/* Just read the proto name			   			  */
/*file : ft_split_path.c	 					  */
char	**ft_split_path(char const *s, char c);

/*================================================*/
/* Function for chained list, ft_lst.c			  */
/*file : ft_lst.c	 							  */
t_node	*ft_lstnew(int value);
void	ft_lstadd_back(t_node **alst, t_node *new);

/*================================================*/
/* Function for free, ft_free.c		 			  */
/*file : ft_free.c	utils_exec.c 				  */
void	ft_free_all(char ***execarg);
void	*ft_free(char **output, int p);
void	ft_lstclear(t_node **lst);
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
/* Gestion des arguments et chaines de caracteres */
/*file : utils_str.c							  */

void	ft_copy(char **av, char **execarg);
int		ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*ft_strjoin_pimp(char *s1, char *s2);
char	**ft_split(char const *s, char c);
/*================================================*/
#endif
