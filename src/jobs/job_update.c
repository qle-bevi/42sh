/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 21:24:01 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/05 21:24:01 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job.h"
#include "shell.h"

static void job_stop(t_job *job)
{
	set_current_pgid(0);
	job->stopped = 1;
	job->current_cmd->background = 1;
	job_notify(job, "stopped", 1);
	return ;
}

void job_update(t_job *job, pid_t pid, int status)
{
	t_cmd	*current;

	if (!job->stopped && WIFSTOPPED(status))
		return (job_stop(job));
	current = cmd_get_by_pid(job->current_cmd, pid, 0);
	if (!current || current->done)
		return ;
	cmd_update(current, status);
	if (current->done)
	{
		if (current->ret == 130)
			return (job_terminate(job, 130));
		if (current->ret)
			cmd_terminate(job->current_cmd, current->ret);
		if (current->ret || !current->children)
			job_next_cmd(job);
	}
}