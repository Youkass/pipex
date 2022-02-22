/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:34:10 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/22 14:10:44 by yobougre         ###   ########.fr       */
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

void	ft_print_tab(char **tab);
/*================================================*/
/* Functions using pipe()			   			  */
/*file : utils_pipe.c		 					  */
int		fork_pipe(char *av, char **envp);
int		ft_filein(char *file);
int		ft_fileout(char *file);

/*================================================*/
/* Fill the execarg tab				   			  */
/*file : utils_exec.c		 					  */
int		ft_execute(char *av, char **envp);

/*================================================*/
/* Just read the proto name			   			  */
/*file : ft_split_path.c	 					  */
char	**ft_split_path(char const *s, char c);

/*================================================*/
/* Function for free, ft_free.c		 			  */
/*file : ft_free.c				 				  */
void	ft_free_all(char ***execarg, char **cmd);
void	*ft_free(char **output, int p);
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
