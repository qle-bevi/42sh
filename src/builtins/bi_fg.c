/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_fg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 11:09:17 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/05/03 19:01:30 by bdesbos          ###   ########.fr       */
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

	while (job && job->next)
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
	return (fg_job(sh->jobs, id));
}
