/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:26:10 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/10 22:51:32 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free_all(char ***execarg)
{
	int	i;
	int	j;

	i = 0;
	while (execarg[i])
	{
		j = 0;
		while (execarg[i][j])
			free(execarg[i][j++]);
		++i;
	}
	free(execarg);
}

void	ft_execution(char ***execarg, char **av, int ac)
{
	int		i;
	int		j;

	i = 0;
	j = 2;
	execarg = malloc(sizeof(char **) * ac + 1);
	if (!execarg)
		exit(EXIT_FAILURE);
	while (j < ac - 1)
	{
		execarg[i] = ft_split(av[j], ' ');
		if (!execarg[i])
			return (ft_free_all(execarg));
	}
	execarg[i] = NULL;
}
