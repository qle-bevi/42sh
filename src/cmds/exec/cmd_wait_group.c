/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_wait_group.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 05:00:33 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/01/30 20:11:49 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

static int		cmd_are_all_complete(t_cmd *first)
{
	t_cmd	*current;

	current = first;
	while (current)
	{
		if (!current->done)
			return (0);
		current = current->children;
	}
	return (1);
}

static void		cmd_kill_them_all(t_cmd *current)
{
	while (current)
	{
		if (!current->done && current->pid)
			kill(current->pid, SIGTERM);
		current = current->children;
	}
}

static t_cmd	*cmd_get_by_pid(t_cmd *current, pid_t pid)
{
	while (current)
	{
		if (current->pid == pid)
			return (current);
		current = current->children;
	}
	return (NULL);
}

void			cmd_wait_group(t_cmd *first)
{
	pid_t	pid;
	int		status;
	t_cmd	*current;
	int		ret;

	ret = -1;
	while (!cmd_are_all_complete(first))
	{
		if (!(pid = waitpid(-1, &status, WNOHANG)))
			continue ;
		if ((current = cmd_get_by_pid(first, pid)) && !current->done)
		{
			cmd_handle_status(current, status);
			if (!current->children)
			{
				cmd_kill_them_all(first);
				ret = current->ret;
			}
		}
	}
	first->ret = ret;
}
