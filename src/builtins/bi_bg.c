/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_bg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 02:46:57 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/27 19:07:51 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "job.h"

static int get_last_id(t_job *jobs)
{
	while (jobs)
	{
		if (jobs->next && !jobs->next->next) return (jobs->id);
		jobs = jobs->next;
	}
	return (0);
}

int 	bi_bg(t_shell *sh, char **args)
{
	t_job	*job;
	int		ret;
	int		id;

	ret = 0;
	if (!*args)
	{
		if (!(id = get_last_id(sh->jobs)))
		{
			print_error("fg: no such job", NULL);
			return (1);
		}
	} else id = ft_atoi(*args);
	while (*args)
	{
		job = sh->jobs;
		while (job)
		{
			if (job->id == ft_atoi(*args))
			{
				job_push_background(job, 1);
				break ;
			}
			job = job->next;
			if (!job)
			{
				ret = 1;
				print_error("bg: no such job: ", *args);
			}
		}
		++args;
	}
	return (ret);
}
