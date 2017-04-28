/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_wait.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 06:45:04 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/28 20:30:21 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "job.h"

static void update_jobs(t_job *current_job, pid_t pid, int status)
{
	t_cmd *cmd;

	while (current_job)
	{
		cmd = current_job->current_cmd;
		while (cmd)
		{
			if (cmd->pid == pid)
			{
				if (cmd->done)
					return ;
				if (WIFSTOPPED(status))
					current_job->stopped = 1;
				cmd_update(cmd, status);
				if (cmd->done && cmd->ret == 130)
				{
					job_terminate(current_job, 130);
					return ;
				}
				if (cmd->done && (cmd->ret || !cmd->children))
				{
					cmd_terminate(current_job->current_cmd, cmd->ret);
					job_next_cmd(current_job);
				}
				break ;
			}
			else
				cmd = cmd->children;
		}
		current_job = current_job->next;
	}
}


void	job_wait(t_job *job)
{
	int		status;
	pid_t	pid;

	while (!job->stopped && !job->done)
	{
		pid = waitpid(job->current_cmd->pid, &status, WUNTRACED);
		if (pid <= 0) break ;
		update_jobs(job, pid, status);
	}
}
