/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:36:20 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/01 17:49:32 by yobougre         ###   ########.fr       */
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

void	ft_close(void)
{
	close(1);
	close(2);
	close(0);
	exit(EXIT_FAILURE);
}

void	ft_free_struct(t_node *params)
{
	ft_close_all(params);
	free(params->fd);
}

int	main(int ac, char **av, char **envp)
{
	int		i;
	int		status;
	t_node	params;

	if (ac < 5)
		return (0);
	params.nb = ac - 3;
	i = 2;
	/*ADD HERE_DOC CONDITION*/
	if (ft_init_pipe(&params) < 0 || ft_open(&params, av[1], av[ac - 1]) < 0)
		exit(EXIT_FAILURE);
	params.index = 0;
	while (params.index < params.nb)
	{
		if (ft_fork(&params, envp, av[i]) < 0)
		{
			ft_free_struct(&params);
			exit(EXIT_FAILURE);
		}
		params.index++;
		i++;
	}
	waitpid(-1, &status, 0);
	ft_free_struct(&params);
	return (0);
}
