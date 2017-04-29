/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_terminate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 09:04:50 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/29 21:55:53 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "job.h"
#include "shell.h"

void		job_terminate(t_job *job, int ret)
{
	set_current_pgid(0);
	cmd_terminate(job->current_cmd, ret);
	job->ret = ret;
	job->done = 1;
}
