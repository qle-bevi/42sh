/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_add_a_job.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 19:04:30 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/27 17:06:37 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	next_id(t_job *job)
{
	int max;

	max = 0;
	while (job)
	{
		if (job->id > max)
			max = job->id;
		job = job->next;
	}
	return (max + 1);
}

void		shell_add_a_job(t_shell *sh, t_job *job)
{
	t_job		*current_job;

	job->id = next_id(sh->jobs);
	if (!(job->title = ft_itoa(job->id)))
		exit_shell(ERR_MALLOC, 1);
	if (!(current_job = sh->jobs))
	{
		sh->jobs = job;
		return ;
	}
	while (current_job->next)
		current_job = current_job->next;
	current_job->next = job;
}
