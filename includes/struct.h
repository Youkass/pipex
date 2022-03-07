/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobougre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:40:36 by yobougre          #+#    #+#             */
/*   Updated: 2022/03/07 16:48:53 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "includes.h"

typedef struct	s_node
{
	int				infile;
	char			*infile_name;
	char			*outfile_name;
	int				outfile;
	pid_t			*pid;
	int				nb;
	int				*fd;
	char		 	**cmd;
	char			**cmd_args;
	int				index;
	int				heredoc;
} t_node;

#endif
