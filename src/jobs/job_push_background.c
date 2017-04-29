/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_push_background.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 09:52:22 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/27 19:22:59 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "job.h"
#include <unistd.h>
#include <signal.h>

void	job_push_background(t_job *job, int cont)
{
	set_current_pgid(0);
	if (cont)
		kill(-job->current_cmd->pid, SIGCONT);
	job->notified = 0;
	job->current_cmd->background = 1;
}
