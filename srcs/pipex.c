/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:36:20 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/09 14:14:26 by yuro4ka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	ft_print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		printf("%s\n", tab[i++]);
}

int	main(int ac, char **av, char **envp)
{
	int		id;
	char	**execarg;

	if (ac < 1)
		return (0);
	execarg = malloc(sizeof(char *) * ac + 1);
	if (!execarg)
		exit(EXIT_FAILURE);
	ft_copy(av, execarg, ac);
	id = fork();
	if (id == 0)
	{
		printf("id Child : %d\n", id);
		if (access(ft_cmd(execarg[0]), F_OK) == 0)
			execve(ft_cmd(execarg[0]), execarg, envp);
		else
			printf("Commande inconnue\n");
	}
	else
	{
		waitpid(0, NULL, 0);
		printf("id Parent : %d\n", id);
	}
}
