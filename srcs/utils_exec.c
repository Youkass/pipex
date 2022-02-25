/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:26:10 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/25 18:48:55 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_execute(char **av, char **envp)
{
	char	*path;

	path = check_path(get_path_lst(envp), av[0]);
	if (!path)
		return (ft_free(av), -1);
	if (execve(path, av, envp) == -1)
		return (ft_free(av), free(path), -1);
	return (1);
}
