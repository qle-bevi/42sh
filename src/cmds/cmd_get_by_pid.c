/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_get_by_pid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 18:12:59 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/30 18:24:00 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "shell.h"

static t_cmd	*cmd_find(t_cmd *cmds, pid_t pid)
{
	while (cmds && cmds->pid != pid)
		cmds = cmds->children;
	return (cmds);
}

static t_cmd	*cmd_find_deep(t_cmd *cmds, pid_t pid)
{
	t_cmd *cmd;

	while (cmds)
	{
		if ((cmd = cmd_find(cmds, pid)))
			return (cmd);
		cmds = cmds->then;
	}
	return (NULL);
}

t_cmd			*cmd_get_by_pid(t_cmd *cmds, pid_t pid, int deep)
{
	return (deep) ? cmd_find_deep(cmds, pid) : cmd_find(cmds, pid);
}
