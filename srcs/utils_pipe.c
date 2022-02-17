/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 01:29:39 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/17 12:13:39 by yobougre         ###   ########.fr       */
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

static char	**dup_args(char **execarg_i)
{
	char	**output;
	int		i;

	i = 0;
	output = malloc(sizeof(char *) * ft_tab_size(execarg_i) + 1);
	if (!output)
		return (NULL);
	while (execarg_i[i])
	{
		printf("%s\n", execarg_i[i]);
		output[i] = ft_strdup(execarg_i[i]);
		if (!output[i])
			return (ft_free(output, ft_tab_size(output)), NULL);
		++i;
	}
	output[i] = NULL;
	return (output);
}

int	fork_pipe(int nb, char **cmd, char ***execarg, char **envp)
{
	int		fd[2];
	int		pid;
	int		i;
	char	**args;

	i = 0;
	while (i < nb - 1)
	{
		if (pipe(fd) == -1)
			return (0);
		ft_print_tab(execarg[i]);
		args = dup_args(execarg[i]);
		if (!args)
			return (ft_free_all(execarg, cmd), 0);
		pid = fork();
		if (pid < 0)
			return (0);
		if (pid == 0)
		{
			close(fd[0]);
			dup2(fd[1], STDOUT_FILENO);
			if (execve(cmd[i], args, envp) == -1)
				return (ft_free_all(execarg, cmd), 0);
		}
		else
		{
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
			if (waitpid(pid, NULL, 0) == -1)
				return (ft_free_all(execarg, cmd), 0);
		}
		++i;
	}
	return (i);
}
