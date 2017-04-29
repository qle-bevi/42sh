/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_set_fds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 04:03:30 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/29 13:41:29 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "shell.h"

int			cmd_got_fd_for(t_redir *current, int from, int links)
{
	while (current)
	{
		if (current->from == from)
		{
			if ((current->rtype == W_LINK || current->rtype == R_LINK) && links)
				return (current->to);
			else if ((current->rtype != W_LINK && current->rtype != R_LINK) &&
			!links)
				return (current->to);
		}
		current = current->next;
	}
	return (-1);
}

void		cmd_set_fds(t_redir *redirs, int links)
{
	int fd;
	int i;

	i = -1;
	while (++i < 3)
	{
		if ((fd = cmd_got_fd_for(redirs, i, links)) != -1)
		{
			close(i);
			if (fd != -3)
				dup(fd);
		}
	}
	if (!links)
		cmd_set_fds(redirs, 1);
}
