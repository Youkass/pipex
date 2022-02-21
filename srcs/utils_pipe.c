/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 01:29:39 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/21 16:25:32 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_fileout(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		return (-1);
	else
		return (fd);
}

int	ft_filein(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY, 0777);
	if (fd == -1)
		return (-1);
	else
		return (fd);
}

int	fork_pipe(int ac, char **av, char **envp)
{
	int		fd[2];
	int		pid;
	int		i;

	i = 2;
	while (i < ac - 1)
	{
		if (pipe(fd) == -1)
			return (-1);
		pid = fork();
		if (pid < 0)
			return (-1);
		if (pid == 0)
		{
			close(fd[0]);
			dup2(fd[1], STDOUT_FILENO);
			if (ft_execute(i, av, envp) == -1)
				return (-1);
		}
		else
		{
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
			if (waitpid(pid, NULL, 0) == -1)
				return (-1);
		}
		++i;
	}
	return (i);
}
