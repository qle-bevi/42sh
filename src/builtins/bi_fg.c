/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_fg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 11:09:17 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/13 11:09:17 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "job.h"

int		bi_fg(t_shell *sh, char **args)
{
	int		id;
	t_job	*job;

	if (!args[0])
	{
		print_error("fg: no such job", NULL);
		return (1);
	}
	id = ft_atoi(args[0]);
	job = sh->jobs;
	while (job)
	{
		if (job->id == id)
		{
			job_push_foreground(job);
			if (job->done)
				shell_remove_a_job(sh, job);
			return (0);
		}
		job = job->next;
	}
	print_error("fg: no such job: ", args[0]);
	return (1);
}