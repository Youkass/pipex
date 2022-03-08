/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:36:20 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/08 16:55:14 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_init_pid(t_node *params)
{
	params->pid = malloc(sizeof(pid_t) * params->nb);
	if (!params->pid)
		return (-1);
	return (1);
}

void	ft_free_struct(t_node *params)
{
	ft_close_all(params);
	close(params->infile);
	close(params->outfile);
	free(params->fd);
	free(params->pid);
	free(params->infile_name);
	free(params->outfile_name);
	ft_free(params->cmd);
	if (params->heredoc)
	{
		unlink(params->heredoc_name);
		free(params->heredoc_name);
		free(params->limiter);
	}
}

int	ft_fill_cmd_name(t_node *params, char **av, int ac)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 2;
	if (params->heredoc)
		j = 3;
	params->cmd = malloc(sizeof(char *) * ((ac - 3 - params->heredoc) + 1));
	if (!params->cmd)
		return (-1);
	while (i < ac - 3 - params->heredoc)
	{
		tmp = ft_split(av[j], ' ');
		if (!tmp)
			return (-1);
		params->cmd[i] = ft_strdup(tmp[0]);
		if (!params->cmd[i])
			return (ft_free(tmp), -1);
		ft_free(tmp);
		++i;
		++j;
	}
	params->cmd[i] = NULL;
	return (1);
}

int	ft_child_exec(t_node *params, char **av, char **envp)
{
	int	i;

	i = 2;
	params->index = 0;
	if (params->heredoc)
		i = 3;
	while (params->index < params->nb)
	{
		if (ft_fork(params, envp, av[i]) < 0)
		{
			ft_close();
			ft_free_struct(params);
			return (-1);
		}
		params->index++;
		i++;
	}
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	int		i;
	int		status;
	t_node	params;

	if (ac < 5 || get_path_pos(envp) < 0)
		return (ft_close(), 0);
	params.heredoc = ft_cmp_heredoc(av, "here_doc", &params);
	i = params.heredoc;
	params.nb = ac - 3 - params.heredoc;
	if (ft_init_pid(&params) < 0)
		exit(EXIT_FAILURE);
	if (ft_fill_cmd_name(&params, av, ac) < 0)
		exit(EXIT_FAILURE);
	if (ft_init_pipe(&params) < 0 || ft_open(&params, av[1], av[ac - 1], i) < 0)
		exit(EXIT_FAILURE);
	if (ft_child_exec(&params, av, envp) < 0)
		exit(EXIT_FAILURE);
	i = 0;
	ft_close_all(&params);
	while (i < params.nb)
		waitpid(params.pid[i++], &status, 0);
	ft_free_struct(&params);
	ft_close();
	return (0);
}
