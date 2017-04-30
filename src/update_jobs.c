/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_jobs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 09:50:23 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/30 18:41:19 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "cmd.h"
#include "job.h"

static void	handle_status(t_job *job, t_cmd *cmd, int status)
{
	if (WIFSTOPPED(status))
		job->stopped = 1;
	cmd_update(cmd, status);
	if (cmd->done && cmd->ret == 130)
		job_terminate(job, 130);
	else if (cmd->done)
	{
		if (cmd->ret || !cmd->children)
		{
			cmd_terminate(job->current_cmd, cmd->ret);
			job_next_cmd(job);
		}
	}
}

void		update_jobs(t_job *current_job, pid_t pid, int status)
{
	t_cmd *cmd;

	while (current_job)
	{
		cmd = current_job->current_cmd;
		while (cmd)
		{
			if (cmd->pid == pid && !cmd->done)
				handle_status(current_job, cmd, status);
			cmd = cmd->children;
		}
		current_job = current_job->next;
	}
}
