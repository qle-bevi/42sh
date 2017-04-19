/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_push_background.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 09:52:22 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/13 09:52:22 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job.h"
#include <unistd.h>

void	job_push_background(t_job *job)
{
	//kill(-job->current_cmd->pid, SIGSTOP);
	usleep(400000);
	(void)job;
}