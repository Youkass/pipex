/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:01:00 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/17 18:21:55 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
/*, char **envp*/
int	main(int ac, char **av)
{
	t_node	*lst;
	t_node	*tmp;

	lst = ft_lstnew(0);
	if (ac < 5)
		return (0);
	ft_create_new_lst(&lst, ac - 3);
	if (!lst)
		exit(EXIT_FAILURE);
	ft_get_args(&lst, av);
	tmp = lst;
	while (tmp != NULL)
	{
		printf("node numero : %d\n", tmp->index);
		ft_print_tab(tmp->args);
		tmp = tmp->next;
	}
}
