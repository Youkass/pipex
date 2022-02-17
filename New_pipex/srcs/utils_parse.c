/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:07:40 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/17 18:21:28 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		printf("%s\n", tab[i++]);
}

void	ft_get_args(t_node **start, char **av)
{
	t_node	*tmp;
	int		j;

	tmp = (*start);
	j = 2;
	while (tmp != NULL)
	{
		tmp->args = ft_split(av[j], ' ');
		if (!tmp->args)
		{
			ft_lstclear(start);
			exit(EXIT_FAILURE);
		}
		tmp = tmp->next;
		++j;
	}
}

void	ft_fill_path(t_node **start, char **envp)
{
	t_node	*tmp;

	tmp = (*start);
	while (tmp != NULL)
	{
		tmp->cmd_path = check_path(get_path_lst(envp), tmp->args[0]); 
		if (!tmp->cmd_path)
		{
			ft_lstclear(start);
			exit(EXIT_FAILURE);
		}
		tmp = tmp->next;
	}
}
