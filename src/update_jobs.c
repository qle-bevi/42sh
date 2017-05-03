/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_jobs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 09:50:23 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/05/03 16:14:21 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "cmd.h"
#include "job.h"

static void	handle_done(t_shell *sh, t_job *job, t_cmd *cmd)
{
	char	*tmp;

	sh->cmd_ret = cmd->ret;
	if (!cmd->ret)
	{
		if (!(tmp = ft_jointab_sep(cmd->args, " ")))
			exit_shell(ERR_MALLOC, 1);
		h_set_or_create_elem(sh->env, "_", tmp);
		free(tmp);
		sh->env_update = 1;
	}
	if (cmd->ret == 130)
		job_terminate(job, 130);
	else if (!cmd->children)
	{
		cmd_return(cmd, cmd->ret);
		cmd_terminate(job->current_cmd, cmd->ret);
		job_next_cmd(job);
	}
}

static void	handle_status(t_job *job, t_cmd *cmd, int status)
{
	if (WIFSTOPPED(status))
		job->stopped = 1;
	cmd_update(cmd, status);
}

void		update_jobs(t_job *current_job, pid_t pid, int status)
{
	t_cmd *cmd;

	while (current_job)
	{
		cmd = current_job->current_cmd;
		while (cmd)
		{
			if (cmd->pid == pid && !cmd->done)
				handle_status(current_job, cmd, status);
			if (cmd->done)
				handle_done(get_shell(), current_job, cmd);
			cmd = cmd->children;
		}
		current_job = current_job->next;
	}
}
