/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:40:36 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/01 17:06:46 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "includes.h"

typedef struct	s_node
{
	int				infile;
	int				outfile;
	pid_t			child;
	pid_t			parent;
	int				nb;
	int				*fd;
	char		 	*path;
	char			**cmd_args;
	int				index;
} t_node;

#endif
