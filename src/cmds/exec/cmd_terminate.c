/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_terminate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 09:02:51 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/30 18:25:38 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "shell.h"
#include <stdio.h>
#include <signal.h>

void		cmd_terminate(t_cmd *cmd, int ret)
{
	cmd->ret = ret;
	while (cmd)
	{
		if (!cmd->done)
		{
			cmd->done = 1;
			if (cmd->pid)
				kill(cmd->pid, SIGKILL);
		}
		cmd = cmd->children;
	}
}
