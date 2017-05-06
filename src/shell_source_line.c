/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_source_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:44:47 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/05/06 17:01:24 by qle-bevi         ###   ########.fr       */
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

void			shell_source_line(t_shell *sh, char **strp)
{
	char	*to_free;
	char	*new;
	t_cmd	*cmd;

	to_free = *strp;
	if (!(*strp = str_expand_vars(*strp)))
		exit_shell(ERR_MALLOC, 1);
	new = *strp;
	free(to_free);
	if (*new == ';')
		++new;
	while (*new)
	{
		if (!(cmd = cmd_build(&new, 1)))
			break ;
		if (validate_fds(cmd))
			shell_create_and_run_job(sh, cmd, *new == '&');
		if (*new == '&' || *new == ';')
			++new;
	}
}
