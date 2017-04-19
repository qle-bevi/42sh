/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_get_job_by_pid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 21:03:20 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/05 21:03:20 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
     
void	shell_update_jobs(t_shell *sh)
{
	pid_t	pid;
	t_job 	*job;
	int 	status;

	if (!sh->jobs)
		return ;
	while ((pid = waitpid(-1, &status, WNOHANG | WUNTRACED )))
	{
		if (pid == -1)
			break ;
		if ((job = job_get_by_pid(sh->jobs, pid)))
		{
			job_update(job, pid, status);
			if (job->done)
			{
				sh->cmd_ret = job->ret;
				shell_remove_a_job(sh, job);
			}	
		}
	}
}