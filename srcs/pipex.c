/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:36:20 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/21 16:25:35 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_print_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
	{
		printf("y'a R c'est null connard\n");
		return ;
	}
	while (tab[i])
		printf("%s\n", tab[i++]);
}

static int	ft_check_file(int filein, int fileout)
{
	if (filein == -1 || fileout == -1)
		return (0);
	else
		return (1);
}

int	main(int ac, char **av, char **envp)
{
	int		filein;
	int		fileout;

	if (ac < 5)
		return (0);
	filein = ft_filein(av[1]);
	fileout = ft_fileout(av[ac - 1]);
	if (!ft_check_file(filein, fileout))
		exit(EXIT_FAILURE);
	dup2(filein, STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	if (!fork_pipe(ac, av, envp))
		exit(EXIT_FAILURE);
	close(filein);
	close(fileout);
	if (ft_execute(ac - 2, av, envp) == -1)
		exit(EXIT_FAILURE);
}
