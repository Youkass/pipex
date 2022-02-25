/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 01:29:39 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/25 18:48:53 by yobougre         ###   ########.fr       */
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

int	__open_infile(char *file)
{
	int	fd;

	fd = ft_filein(file);
	if (fd == -1)
		return (-1);
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (1);
}

int	fork_pipe(t_node *data, char **envp, int i, char **av)
{
	if (pipe(data->fd) == -1)
		return (-1);
	data->pid = fork();
	if (data->pid < 0)
		return (-1);
	if (data->pid == 0)
	{
		if (data->index == 0)
		{
			if (__open_infile(av[i]) == -1)
				exit(EXIT_FAILURE);
			close(data->fd[1]);
			dup2(data->fd[0], STDIN_FILENO);
		}
		else if (data->index != 0)
		{
			close(data->fd[0]);
			dup2(data->fd[1], STDOUT_FILENO);
		}
		ft_execute(data->cmd_args, envp);
	}
	return (data->pid);
}
