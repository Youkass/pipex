/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:33:39 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/23 17:39:38 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_parse(char **av, char **envp, int ac, t_node **start)
{
	t_node	*tmp;
	int		i;

	ft_create_new_lst(start, ac - 3);
	if (!start)
		return ;
	tmp = (*start);
	i = 2;
	while (tmp != NULL)
	{
		tmp->cmd_args = ft_split(av[i], ' ');
		if (!tmp->cmd_args)
			return (ft_lstclear(start));
		tmp->path = check_path(get_path_lst(envp), tmp->cmd_args[0]);
		if (!tmp->path)
			return (ft_lstclear(start));
		tmp = tmp->next;
		++i;
	}
}
