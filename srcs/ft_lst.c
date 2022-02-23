/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:18:05 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/23 16:30:34 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_node	*ft_lstnew(int value)
{
	t_node	*sortie;

	sortie = malloc(sizeof(t_node) * 1);
	if (!sortie)
		return (NULL);
	sortie->index = value;
	sortie->path = NULL;
	sortie->prev = NULL;
	sortie->cmd_args = NULL;
	sortie->next = NULL;
	return (sortie);
}

void	ft_lstclear(t_node **lst)
{
	t_node	*tmp_00;
	t_node	*tmp_01;

	if (!lst)
		return ;
	tmp_00 = *lst;
	while (tmp_00)
	{
		tmp_01 = tmp_00->next;
		free(tmp_00);
		tmp_00 = tmp_01;
	}
	*lst = NULL;
}

void	ft_create_new_lst(t_node **start, int nb_cmd)
{
	int		i;
	t_node	*tmp;

	i = 0;
	*start = ft_lstnew(i);
	if (!(*start))
		exit(EXIT_FAILURE);
	i++;
	tmp = (*start);
	while (i < nb_cmd)
	{
		tmp->next = ft_lstnew(i++);
		if (!tmp->next)
			return (ft_lstclear(start));
		tmp->next->prev = tmp;
		tmp = tmp->next;
	}
}
