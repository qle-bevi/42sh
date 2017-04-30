/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_bg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdesbos <bdesbos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 17:49:08 by bdesbos           #+#    #+#             */
/*   Updated: 2017/04/30 22:16:48 by qle-bevi         ###   ########.fr       */
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

static int	bg_jobs(t_job *job, int id)
{
	char	*id_str;

	while (job)
	{
		if (job->id == id)
		{
			job_push_background(job, 1);
			return (0);
		}
		job = job->next;
	}
	if (!(id_str = ft_itoa(id)))
		exit_shell(ERR_MALLOC, 1);
	print_error("bg: no such job: ", id_str);
	free(id_str);
	return (1);
}

int			bi_bg(t_shell *sh, char **args)
{
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
	}
	else
		id = ft_atoi(*args);
	return (bg_jobs(sh->jobs, id));
}
