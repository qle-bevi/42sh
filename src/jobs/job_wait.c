/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_wait.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 06:45:04 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/27 06:45:04 by qle-bevi         ###   ########.fr       */
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