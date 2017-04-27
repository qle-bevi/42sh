/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_update_status.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 04:27:32 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/27 04:27:32 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "job.h"

static void update_jobs(t_job *current_job, pid_t pid, int status)
{
	while (current_job)
	{
		if (current_job->current_cmd->pid == pid)
		{
			if (WIFSTOPPED(status))
				current_job->stopped = 1;
			cmd_update(current_job->current_cmd, status);
			if (current_job->current_cmd->done)
			{
				job_next_cmd(current_job);
				break ;
			}
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