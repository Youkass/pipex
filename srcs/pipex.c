/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:36:20 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/17 15:00:07 by yobougre         ###   ########.fr       */
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

void	ft_fill_cmd(t_node **start, char **envp)
{
	t_node	*tmp;

	tmp = (*start);
	while (tmp != NULL)
	{
		tmp->cmd_path = check_path(get_path_lst(envp), tmp->args[0]);
		if (!tmp->cmd_path)
			return (ft_lstclear(start));
		if (tmp->next == NULL)
			tmp->cmd_path = NULL;
		tmp = tmp->next;
	}
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
void	ft_lst(t_node **start, char **av, int ac, char **envp)
{
	ft_create_new_lst(start, ac - 3);
	if (!start)
		exit(EXIT_FAILURE);
	ft_execution(start, av, ac);
	if (!start)
		exit(EXIT_FAILURE);
	ft_fill_cmd(start, envp);
	if (!start)
		exit(EXIT_FAILURE);
}

int	main(int ac, char **av, char **envp)
{
	t_node	*lst;
	//int		filein;
	//int		fileout;
	//int		i;

	lst = NULL;
	if (ac < 5)
		return (0);
	ft_lst(&lst, av, ac, envp);
	printf("first cmd_path : %s\n", lst->cmd_path);
	ft_print_tab(lst->args);
	/*filein = ft_filein(av[1]);
	fileout = ft_fileout(av[ac - 1]);
	if (!ft_check_file(filein, fileout))
		return (ft_lstclear(start), 0);
	dup2(filein, STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	i = fork_pipe(ac - 3, cmd, execarg, envp);
	if (!i)
		return (ft_free_all(execarg, cmd), 0);
	if (execve(cmd[i], execarg[i], envp) == -1)
		return (ft_free_all(execarg, cmd), 0);
		*/
}
