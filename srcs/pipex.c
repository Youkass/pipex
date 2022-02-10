/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:36:20 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/10 20:11:59 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
/*
static void	ft_print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		printf("%s\n", tab[i++]);
}*/

int	main(int ac, char **av, char **envp)
{
	int		id;
	char	**execarg;
	char	*cmd;

	if (ac < 1)
		return (0);
	execarg = malloc(sizeof(char *) * ac + 1);
	if (!execarg)
		exit(EXIT_FAILURE);
	ft_copy(av, execarg, ac);
	id = fork();
	if (id == 0)
	{
		cmd = check_path(get_path_lst(envp), av[1]);
		if (cmd)
			execve(cmd, execarg, envp);
		else
			printf("Commande inconnue\n");
	}
	else
	{
		waitpid(0, NULL, 0);
		printf("id Parent : %d\n", id);
	}
}
