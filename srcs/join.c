/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:01:25 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/09 20:44:20 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_strjoin_pimp(char *s1, char *s2)
{
	char	*output;
	size_t	i;
	size_t	j;

	if (!s1)
		s1 = ft_strdup_pimp("\0");
	if (!s2)
		return (NULL);
	output = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!output)
		return (free(s1), free(s2), NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		output[i] = s1[i];
		++i;
	}
	while (s2[j])
	{
		output[i + j] = s2[j];
		++j;
	}
	output[i + j] = 0;
	return (free(s1), output);
}

int	ft_initialisation(t_node *params, char **av, int ac, int i)
{
	int	j;

	i = 1;
	while (j < ac - 1)
	{
		if (!av[j])
		{
			if (params->heredoc)
				free(params->limiter);
			ft_putstr_fd("Arguments error\n", 2);
			exit(EXIT_FAILURE);
		}
		++j;
	}
	if (ft_init_pid(params) < 0)
		return (-1);
	if (ft_fill_cmd_name(params, av, ac) < 0)
		return (-1);
	if (ft_init_pipe(params) < 0 || ft_open(params, av[1], av[ac - 1], i) < 0)
		return (-1);
	return (1);
}
