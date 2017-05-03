/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_create_and_run_job.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:16:21 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/05/03 19:46:48 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_create_and_run_job(t_shell *sh, t_cmd *cmd, int background)
{
	t_job *job;

	job = shalloc(sizeof(t_job));
	job->cmds = cmd;
	shell_add_a_job(sh, job);
	job_next_cmd(job);
	if (sh->is_interactive)
	{
		if (background)
			job_push_background(job, 0);
		else
			job_push_foreground(job);
	}
	else
		job_wait(job);
	if (job->done)
		shell_remove_a_job(sh, job);
}
