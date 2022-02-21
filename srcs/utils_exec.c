/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:26:10 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/21 16:25:33 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_execute(int index, char **av, char **envp)
{
	char	**cmd;

	cmd = ft_split(av[index], ' ');
	printf("cmd : \n");
	ft_print_tab(cmd);
	if (!cmd)
		return (-1);
	if (execve(check_path(get_path_lst(envp), cmd[0]), cmd, envp) == -1)
		return (ft_free(cmd, ft_tab_size(cmd)),-1);
	return (1);
}
