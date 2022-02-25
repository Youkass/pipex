/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:36:20 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/25 18:48:55 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_print_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		printf("%s\n", tab[i++]);
}
/*
static int	ft_check_file(int filein, int fileout)
{
	if (filein == -1 || fileout == -1)
		return (0);
	else
		return (1);
}
*/
void	ft_error(int in, int out)
{
	close(in);
	close(out);
	__close();
}

static int	ft_check(char *av, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av, ' ');
	if (!cmd)
		return (-1);
	path = check_path(get_path_lst(envp), cmd[0]);
	if (!path)
		return (ft_free(cmd), free(path), -1);
	return (ft_free(cmd), free(path), 1);
}

static int	ft_check_cmd(char **av, char **envp, int i, int ac)
{
	while (i < ac - 1)
	{
		if (ft_check(av[i], envp) == -1)
			return (0);
		++i;
	}
	return (1);
}

void	__close(void)
{
	close(1);
	close(2);
	close(0);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av, char **envp)
{
//	int	filein;
	int	fileout;
	int	i;
	t_node	*start;
	t_node	*tmp;

	start = NULL;
	if (ac < 5)
		return (0);
	if (!ft_check_cmd(av, envp, 2, ac))
		__close();
	fileout = ft_fileout(av[ac - 1]);
	if (fileout == -1)
		exit(EXIT_FAILURE);
	ft_parse(av, envp, ac, &start);
	if (!start)
		__close();
	i = 2;
	tmp = start;
	dup2(fileout, STDOUT_FILENO);
	close(fileout);
	while (i < ac - 2)
	{
		tmp->pid = fork_pipe(tmp, envp, 1, av);
		if (tmp->pid == -1)
		{
			__close();
			exit(EXIT_FAILURE);
		}
		i++;
		tmp = tmp->next;
	}
	//waitpid(tmp->prev->pid, NULL, 0);
	ft_execute(tmp->cmd_args, envp);
}
