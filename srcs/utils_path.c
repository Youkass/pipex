/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:13:00 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/03 03:07:06 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_cmd(char *path, char *cmd)
{
	char	*output;

	output = ft_strjoin_pimp(path, cmd);
	return (output);
}

int	ft_cmp_path(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < 3)
		++i;
	return (s1[i] - s2[i]);
}

int	get_path_pos(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_cmp_path("PATH", envp[i]) == 0)
			return (i);
		++i;
	}
	return (-1);
}

char	**get_path_lst(char **envp)
{
	char	**output;

	output = ft_split_path(envp[get_path_pos(envp)] + 5, ':');
	if (!output)
		return (NULL);
	else
		return (output);
}

char	*check_path(char **path_lst, char *cmd)
{
	int		i;
	char	*output;

	i = 0;
	if (!path_lst)
		return (free(cmd), NULL);
	while (path_lst[i])
	{
		output = ft_strjoin_pimp(path_lst[i], cmd);
		if (access(output, R_OK) == 0)
			return (ft_free(path_lst), output);
		free(output);
		++i;
	}
	ft_free(path_lst);
	return (NULL);
}
