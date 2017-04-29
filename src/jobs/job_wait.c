/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_wait.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 06:45:04 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/29 22:00:54 by qle-bevi         ###   ########.fr       */
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
		dprintf(get_shell()->tout, "waiting for pgid %ld\n", (long)job->current_cmd->pid);
		pid = waitpid(-1, &status, WUNTRACED);
		dprintf(get_shell()->tout, "got a pid: %ld\n", (long)pid);
		if (pid <= 0)
			perror("wait");
		update_jobs(job, pid, status);
	}
}
