/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_notify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 05:20:41 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/13 05:20:41 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "job.h"

void	job_notify(t_job *job, char *status, int endl)
{
	if (!job->current_cmd->background)
		return ;
	if (!job->current_cmd->pidstr)
		if (!(job->current_cmd->pidstr = ft_itoa((int)job->current_cmd->pid)))
			exit_shell(ERR_MALLOC, 1);
	job_format(job->title);
	job_format(status);
	if (endl) ft_putchar('\n');
}