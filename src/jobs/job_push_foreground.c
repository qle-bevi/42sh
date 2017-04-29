/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_push_foreground.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 09:28:44 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/28 20:06:54 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job.h"
#include "shell.h"

void	job_push_foreground(t_job *job)
{
	set_current_pgid(job->current_cmd->pid);
	kill(-job->current_cmd->pid, SIGCONT);
	job->stopped = 0;
	job->notified = 0;
	job->current_cmd->background = 0;
	job_wait(job);
	sleep(0);
	set_current_pgid(0);
}
