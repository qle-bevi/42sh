/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_link_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 02:58:03 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/10 17:07:38 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "shell.h"

static t_redir	*make_redir(int from, int to)
{
	t_redir *redir;

	redir = (t_redir *)shalloc(sizeof(t_redir));
	redir->from = from;
	redir->to = to;
	return (redir);
}

void			cmd_link_pipe(t_cmd *current, int p[2])
{
	if (current->children)
	{
		pipe(p);
		cmd_push_redir_front(&current->redirs, make_redir(1, p[1]));
		cmd_push_redir_front(&current->children->redirs, make_redir(0, p[0]));
	}
}
