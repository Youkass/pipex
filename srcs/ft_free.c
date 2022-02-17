/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:26:48 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/17 14:51:46 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free_all(char ***execarg, char **cmd)
{
	int	i;

	i = 0;
	if (execarg)
	{
		while (execarg[i])
			++i;
		while (i)
		{
			if (execarg[i])
				ft_free(execarg[i], ft_tab_size(execarg[i]));
			--i;
		}
		free(execarg);
	}
	if (cmd)
		ft_free(cmd, ft_tab_size(cmd));
	execarg = NULL;
	cmd = NULL;
}


int	ft_tab_size(char **tab)
{
	int	i;
	
	i = 0;
	while (tab[i])
		++i;
	return (i);
}

void	*ft_free(char **output, int p)
{
	if (output)
	{
		while (p)
		{
			if (output[p])
				free(output[p]);
			p--;
		}
		if (output)
			free(output);
	}
	return (NULL);
}
