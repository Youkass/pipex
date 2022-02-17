/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:25:58 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/17 16:27:04 by yobougre         ###   ########.fr       */
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
