/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_source_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:44:47 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/05/02 17:13:46 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "job.h"
#include "cmd.h"

static int		validate_fds(t_cmd *cmd)
{
	t_cmd	*curr_cmd;
	t_redir	*curr_redir;

	curr_cmd = cmd;
	while (curr_cmd)
	{
		curr_redir = curr_cmd->redirs;
		while (curr_redir)
		{
			if (curr_redir->from != 1 || !curr_cmd->children)
				if (cmd_get_redir_fd(curr_redir) == -1)
					return (0);
			curr_redir = curr_redir->next;
		}
		curr_cmd = curr_cmd->children;
	}
	return ((cmd->then) ? validate_fds(cmd->then) : 1);
}

static void		create_and_run_job(t_shell *sh, t_cmd *cmd, int background)
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

void			shell_source_line(t_shell *sh, char *str)
{
	char	*cmd_str;
	t_cmd	*cmd;

	if (!(str = str_expand_vars(str)))
		exit_shell(ERR_MALLOC, 1);
	cmd_str = str;
	if (*cmd_str == ';')
		++cmd_str;
	while (*cmd_str)
	{
		if (!(cmd = cmd_build(&cmd_str, 1)))
			break ;
		if (validate_fds(cmd))
			create_and_run_job(sh, cmd, *cmd_str == '&');
		if (*cmd_str == '&')
			++cmd_str;
	}
	free(str);
}
