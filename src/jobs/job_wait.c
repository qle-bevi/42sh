/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_wait.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 06:45:04 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/30 18:36:26 by bdesbos          ###   ########.fr       */
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
		pid = waitpid(-1, &status, WUNTRACED);
		update_jobs(job, pid, status);
	}
}
