/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:36:20 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/10 22:52:15 by yobougre         ###   ########.fr       */
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
	char	***execarg;

	execarg = NULL;
	(void)envp;
	if (ac < 1)
		return (0);
	if (access(av[1], F_OK) != 0)
		return (0);
	ft_execution(execarg, av, ac);
}
