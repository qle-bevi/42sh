/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_get_by_pid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:32:01 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/11 17:32:01 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job.h"

t_job	*job_get_by_pid(t_job *jobs, pid_t pid)
{
	t_cmd *cmd;

	while (jobs && !(cmd = cmd_get_by_pid(jobs->current_cmd, pid, 0)))
		jobs = jobs->next;
	return (jobs);
}