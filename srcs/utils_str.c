/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:34:51 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/07 15:36:38 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_copy(char **av, char **execarg, int ac)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		execarg[j] = ft_strdup(av[i]);
		++j;
		++i;
	}
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while(s[i])
		++i;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*output;
	int		i;

	output = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!output)
		return (NULL);
	i = 0;
	while (s[i])
	{
		output[i] = s[i];
		++i;
	}
	output[i] = 0;
	return (output);
}

static char	*ft_strdup_pimp(char *s)
{
	char	*output;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	output = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!output)
		return (NULL);
	while (s[i])
	{
		output[i] = s[i];
		++i;
	}
	output[i] = 0;
	return (output);
}

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
	return (output);
}
