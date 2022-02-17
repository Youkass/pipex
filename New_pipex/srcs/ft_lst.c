/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:05:34 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/17 18:21:56 by yobougre         ###   ########.fr       */
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
	sortie->args = NULL;
	sortie->cmd_path = NULL;
	sortie->next = NULL;
	return (sortie);
}

void	ft_lstadd_back(t_node **alst, t_node *new)
{
	t_node	*tmp;

	tmp = *alst;
	if (!(*alst))
	{
		*alst = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
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
		if (tmp_00->cmd_path)
			free(tmp_00->cmd_path);
		if (tmp_00->args)
			ft_free(tmp_00->args, ft_tab_size(tmp_00->args));
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
	tmp = (*start);
	while (i < nb_cmd)
	{
		tmp = ft_lstnew(i);
		tmp = tmp->next;
		++i;
	}
	tmp = NULL;
}
