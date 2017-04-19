/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_next_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 09:14:10 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/13 09:14:10 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job.h"

static void		job_exec_cmd(t_job *job, t_cmd *cmd)
{
	job->started = 1;
	cmd_exec((job->current_cmd = cmd));
	if (job->current_cmd->done)
		job_next_cmd(job);
}

void		job_next_cmd(t_job *job)
{
	t_cmd *candidate;

	candidate = job->current_cmd;
	if (!job->started)
		return (job_exec_cmd(job, job->cmds)); 
	while (candidate->then)
	{
		if ((candidate->ctype == OR && job->current_cmd->ret)
		|| (candidate->ctype == AND && !job->current_cmd->ret))
			return (job_exec_cmd(job, candidate->then));
		candidate = candidate->then;
	}
	job_terminate(job, job->current_cmd->ret);
}