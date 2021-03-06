/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:52:25 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/10 16:22:11 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		i;
	int		status;
	t_node	params;

	if (ac != 5 || ft_args(ac, av) < 0)
		ft_wrong_args();
	i = 0;
	params.nb = ac - 3;
	params.heredoc = 0;
	params.limiter = NULL;
	if (ft_initialisation(&params, av, ac, i) < 0)
	{
		ft_free_struct(&params);
		exit(EXIT_FAILURE);
	}
	if (ft_child_exec(&params, av, envp) < 0)
		exit(EXIT_FAILURE);
	ft_close_all(&params);
	while (i < params.nb)
		waitpid(params.pid[i++], &status, 0);
	ft_free_struct(&params);
	ft_close();
	return (0);
}
