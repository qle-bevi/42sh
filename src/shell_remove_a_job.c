/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_remove_a_job.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 09:37:32 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/30 18:38:47 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	push_job(t_job **jobs, t_job *job)
{
	t_job *current;

	job->next = NULL;
	if (!(current = *jobs))
	{
		*jobs = job;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = job;
}

void		shell_remove_a_job(t_shell *sh, t_job *job)
{
	t_job *current;
	t_job *next;

	current = sh->jobs;
	sh->jobs = NULL;
	while (current)
	{
		next = current->next;
		if (current != job)
			push_job(&sh->jobs, current);
		else
			job_free(job);
		current = next;
	}
}
