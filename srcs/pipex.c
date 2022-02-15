/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:36:20 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/15 14:01:37 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		printf("%s\n", tab[i++]);
}

char	**ft_fill_cmd(char **cmd, char ***av, char **envp, int ac)
{
	int	i;

	i = 0;
	while (i < ac - 3)
	{
		cmd[i] = check_path(get_path_lst(envp), av[i][0]);
		if (!cmd[i])
			return (ft_free_all(av, cmd), NULL);
		++i;
	}
	cmd[i] = NULL;
	return (cmd);
}

static int	ft_check_file(int filein, int fileout)
{
	if (filein == -1 || fileout == -1)
		return (0);
	else
		return (1);
}

int	main(int ac, char **av, char **envp)
{
	char	***execarg;
	char	**cmd;
	int		filein;
	int		fileout;
	int		i;

	execarg = NULL;
	cmd = NULL;
	if (ac < 5)
		return (0);
	execarg = ft_execution(execarg, av, ac, cmd);
	if (!execarg)
		return (ft_free_all(execarg, cmd), 0);
	cmd = malloc(sizeof(char *) * ac - 2);
	if (!cmd)
		return (ft_free_all(execarg, cmd), 0);
	cmd = ft_fill_cmd(cmd, execarg, envp, ac);
	if (!cmd)
		return (ft_free_all(execarg, cmd), 0);
	filein = ft_filein(av[1]);
	fileout = ft_fileout(av[ac - 1]);
	if (!ft_check_file(filein, fileout))
		return (ft_free_all(execarg, cmd), 0);
	dup2(filein, STDIN_FILENO);
	i = fork_pipe(ac - 3, cmd, execarg, envp);
	if (!i)
		return (ft_free_all(execarg, cmd), 0);
	dup2(fileout, STDOUT_FILENO);
	execve(cmd[i], execarg[i], envp);
	return (ft_free_all(execarg, cmd), 0);
}
