/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <yobougre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:52:24 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/01 17:49:34 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "struct.h"
# include "includes.h"

/* -------------------------------------------------------------------------- */
/*                        FILE = srcs/ft_split_path.c                         */
/* -------------------------------------------------------------------------- */
char	**ft_split_path(char const *s, char c);

/* -------------------------------------------------------------------------- */
/*                           FILE = srcs/ft_split.c                           */
/* -------------------------------------------------------------------------- */
char	**ft_split(char const *s, char c);

/* -------------------------------------------------------------------------- */
/*                          FILE = srcs/utils_exec.c                          */
/* -------------------------------------------------------------------------- */
int		ft_execute(char **av, char **envp);
void	ft_dup2(int in, int out);
int		ft_init_pipe(t_node *params);
int		ft_open(t_node *params, char *infile, char *outfile);

/* -------------------------------------------------------------------------- */
/*                          FILE = srcs/utils_str.c                           */
/* -------------------------------------------------------------------------- */
int		ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*ft_strjoin_pimp(char *s1, char *s2);

/* -------------------------------------------------------------------------- */
/*                          FILE = srcs/utils_path.c                          */
/* -------------------------------------------------------------------------- */
char	*ft_cmd(char *path, char *cmd);
int		ft_cmp_path(char *s1, char *s2);
int		get_path_pos(char **envp);
char	**get_path_lst(char **envp);
char	*check_path(char **path_lst, char *cmd);

/* -------------------------------------------------------------------------- */
/*                            FILE = srcs/pipex.c                             */
/* -------------------------------------------------------------------------- */
void	ft_print_tab(char **tab);
void	ft_error(int in, int out);
void	ft_close(void);
void	ft_free_struct(t_node *params);

/* -------------------------------------------------------------------------- */
/*                          FILE = srcs/utils_pipe.c                          */
/* -------------------------------------------------------------------------- */
void	ft_close_all(t_node *params);
int		ft_fork(t_node *params, char **envp, char *av);

/* -------------------------------------------------------------------------- */
/*                           FILE = srcs/ft_free.c                            */
/* -------------------------------------------------------------------------- */
int		ft_tab_size(char **tab);
void	ft_free(char **tab);


#endif
