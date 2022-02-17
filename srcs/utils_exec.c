/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:26:10 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/17 14:54:31 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_execution(t_node **start, char **av, int ac)
{
	int		j;
	t_node	*tmp;

	j = 2;
	tmp = (*start);
	while (j < ac - 1)
	{
		tmp->args = ft_split(av[j], ' ');
		if (!tmp->args)
			return (ft_lstclear(start));
		if (tmp->next == NULL)
			tmp->args = NULL;
		tmp = tmp->next;
		++j;
	}
}
