/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_fg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 11:09:17 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/30 23:11:55 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "job.h"

static int	get_last_id(t_job *jobs)
{
	while (jobs)
	{
		if (jobs->next && !jobs->next->next)
			return (jobs->id);
		jobs = jobs->next;
	}
	return (0);
}

static int	fg_job(t_job *job, int id)
{
	char	*id_str;

	while (job)
	{
		if (job->id == id)
		{
			job_push_foreground(job);
			return (0);
		}
		job = job->next;
	}
	if (!(id_str = ft_itoa(id)))
		exit_shell(ERR_MALLOC, 1);
	print_error("fg: no such job: ", id_str);
	free(id_str);
	return (1);
}

int			bi_fg(t_shell *sh, char **args)
{
	int		id;
	t_job	*job;

	if (!args[0])
	{
		if (!(id = get_last_id(sh->jobs)))
		{
			print_error("fg: no such job", NULL);
			return (1);
		}
	}
	else
		id = ft_atoi(args[0]);
	job = sh->jobs;
	return (fg_job(sh->jobs, id));
}
