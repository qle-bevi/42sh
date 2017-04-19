/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_wait.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 23:09:05 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/11 23:09:05 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job.h"
#include "shell.h"

void	job_wait(t_job *job)
{
	pid_t	pid;
	int 	status;

	while (!job->done && !job->stopped)
	{
		pid = waitpid(-job->current_cmd->pid, &status, WUNTRACED);
		job_update(job, pid, status);
	}	
}