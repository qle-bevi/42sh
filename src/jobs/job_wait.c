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

void	job_wait(t_job *job)
{
	int		status;
	pid_t	pid;

	while (!job->stopped && !job->done)
	{
		pid = waitpid(-job->current_cmd->pid, &status, WUNTRACED);
		if (pid <= 0) break ;
		update_jobs(job, pid, status);
	}
}
