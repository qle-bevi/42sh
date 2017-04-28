/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_update_status.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 04:27:32 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/28 19:57:48 by qle-bevi         ###   ########.fr       */
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
					break ;
				if (WIFSTOPPED(status))
					current_job->stopped = 1;
				cmd_update(cmd, status);
				if (cmd->done && cmd->ret == 130)
				{
					job_terminate(current_job, 130);
					return ;
				}
				if (cmd->done)
				{
					if (cmd->ret)
						cmd_terminate(current_job->current_cmd, cmd->ret);
					if (cmd->ret || !cmd->children)
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

void	shell_update_status(t_shell *sh)
{
	int		status;
	pid_t	pid;

	while ((pid = waitpid(-1, &status, WNOHANG | WUNTRACED)))
	{
		if (pid == -1) break ;
		update_jobs(sh->jobs, pid, status);
	}
}
