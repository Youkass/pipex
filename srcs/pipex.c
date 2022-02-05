/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:36:20 by yobougre          #+#    #+#             */
/*   Updated: 2022/02/05 14:46:10 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main()
{
	int	id;
	int	id_2;
	int	i;

	id = fork();
	if (id != 0)
	{
		i = 0;
		printf("id : %d\n", id);
		while (i < 5)
			printf("%d ", i++);
		printf("\n");
	}
	else
	{
		wait(NULL);
		id_2 = fork();
		printf("id : %d\n", id);
		if (id_2 != 0)
		{
			i = 5;
			while (i < 10)
				printf("%d ", i++);
			printf("\n");
		}
		else
		{
			wait(NULL);
			printf("id : %d\n", id_2);
			i = 10;
			while (i < 15)
				printf("%d ", i++);
			printf("\n");
		}
	}
}
