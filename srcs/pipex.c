/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:36:20 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/11 00:14:12 by yobougre         ###   ########.fr       */
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
			return (NULL);
		++i;
	}
	cmd[i] = NULL;
	return (cmd);
}

int	main(int ac, char **av, char **envp)
{
	char	***execarg;
	char	**cmd;

	execarg = NULL;
	if (ac < 5)
		return (0);
	if (access(av[1], F_OK) != 0)
		return (0);
	execarg = ft_execution(execarg, av, ac);
	if (!execarg)
		return (0);
	cmd = malloc(sizeof(char *) * ac - 2);
	if (!cmd)
		return (ft_free_all(execarg), 0);
	cmd = ft_fill_cmd(cmd, execarg, envp, ac);
	if (!cmd)
		return (ft_free_all(execarg), 0);
}
