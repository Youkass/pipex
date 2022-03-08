/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 01:29:39 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/08 14:23:00 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_close_all(t_node *params)
{
	int	i;

	i = 0;
	while (i < (params->nb - 1) * 2)
		close(params->fd[i++]);
}

int	ft_fork(t_node *params, char **envp, char *av)
{
	params->pid[params->index] = fork();
	if (params->pid[params->index] == 0)
	{
		if (params->index == 0)
		{
			if (params->infile < 0)
				return (perror(params->infile_name), -1);
			ft_dup2(params->infile, params->fd[1]);
		}
		else if (params->index == params->nb - 1)
			ft_dup2(params->fd[2 * params->index - 2], params->outfile);
		else
			ft_dup2(params->fd[2 * params->index - 2],
			params->fd[2 * params->index + 1]);
		ft_close_all(params);
		if (ft_execute(ft_split(av, ' '), envp) < 0)
			return (ft_command_nt_found(params->cmd[params->index]), -1);
	}
	return (1);
}

void	ft_dup2(int in, int out)
{
	dup2(in, 0);
	dup2(out, 1);
}

int	ft_cmp_heredoc(char **av, char *heredoc, t_node *params)
{
	if (ft_strcmp(av[1], heredoc))
		return (0);
	else
	{
		params->limiter = ft_strdup(av[2]);
		return (1);
	}
}
