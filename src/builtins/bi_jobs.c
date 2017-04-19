/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_jobs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 08:21:08 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/13 08:21:08 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		bi_jobs(t_shell *sh, char **args)
{
	t_job *current_job;

	shell_update_jobs(sh);
	current_job = sh->jobs;
	while (current_job)
	{
		if (!current_job->next)
			return (0);
		job_print(current_job);	
		current_job = current_job->next;
	}
	return (0);
	(void)args;
}