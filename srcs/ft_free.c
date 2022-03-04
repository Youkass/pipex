/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:26:48 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/04 18:33:42 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_tab_size(char **tab)
{
	int	i;
	
	i = 0;
	while (tab[i])
		++i;
	return (i);
}

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	if (!tab )
		return ;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	tab = NULL;
}
