/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:34:10 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/10 20:17:41 by yobougre         ###   ########.fr       */
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
/*================================================*/
/* Function for chained list, ft_lst.c			  */
/*file : ft_lst.c	 							  */

/*================================================*/
/* Function for free, ft_free.c		 			  */
/*file : ft_free.c	 							  */

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

void	ft_copy(char **av, char **execarg, int ac);
int		ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*ft_strjoin_pimp(char *s1, char *s2);
char	**ft_split(char const *s, char c);
/*================================================*/
#endif
