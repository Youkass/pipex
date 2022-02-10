/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:18:05 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/10 20:45:53 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_node	*ft_lstnew(int value)
{
	t_node	*sortie;

	sortie = malloc(sizeof(t_node) * 1);
	if (!sortie)
		return (NULL);
	sortie->id = value;
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
