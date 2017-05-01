/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_terminate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 09:02:51 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/05/01 18:47:04 by qle-bevi         ###   ########.fr       */
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
			if (cmd->pid)
				kill(cmd->pid, SIGKILL);
		}
		cmd = cmd->children;
	}
}
