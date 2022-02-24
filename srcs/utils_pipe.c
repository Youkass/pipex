/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 01:29:39 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/23 17:39:38 by yobougre         ###   ########.fr       */
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

int	fork_pipe(t_node *data, char **envp)
{
	if (pipe(data->fd) == -1)
		return (-1);
	data->pid = fork();
	if (data->pid < 0)
		return (-1);
	if (data->pid == 0)
	{
		close(data->fd[0]);
		dup2(data->fd[1], STDOUT_FILENO);
		if (data->prev)
			close(data->prev->fd[1]);
		ft_execute(data->cmd_args, envp);
	}
	else
	{
		close(data->fd[1]);
		dup2(data->fd[0], STDIN_FILENO);
		close(data->fd[0]);
	}
	return (data->pid);
}
