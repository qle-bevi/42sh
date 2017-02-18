/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 03:32:14 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/01/28 14:35:17 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

static int		cmd_exec_builtin(t_cmd *cmd)
{
	int bi_index;

	if ((bi_index = builtin_index(cmd->args[0])) != -1)
	{
		cmd_set_fds(cmd->redirs, 0);
		cmd->ret = get_builtins()[bi_index].run(get_shell(), cmd->args + 1);
		cmd->done = 1;
		restore_fds();
		return (1);
	}
	return (0);
}

static int		cmd_check_get_path(t_cmd *cmd)
{
	char *path;

	if (!(path = h_get_value_by_key(get_shell()->bins, cmd->args[0])))
	{
		if (cmd->args[0][0] != '.' && cmd->args[0][0] != '/')
		{
			print_error("Command not found: ", cmd->args[0]);
			cmd->done = 1;
			cmd->ret = 127;
			return (0);
		}
	}
	else
	{
		free(cmd->args[0]);
		cmd->args[0] = path;
	}
	if (check_access(cmd->args[0], X_OK) == -1)
	{
		cmd->done = 1;
		cmd->ret = 126;
		return (0);
	}
	return (1);
}

void			cmd_exec_single(t_cmd *cmd, char **env, int must_wait)
{
	int	status;

	if (cmd_exec_builtin(cmd) || !cmd_check_get_path(cmd))
		return ;
	if ((cmd->pid = fork()) == -1)
		exit_shell(ERR_FORK, 1);
	if (!cmd->pid)
	{
		signal(SIGSTOP, SIG_IGN);
		restore_fds();
		cmd_set_fds(cmd->redirs, 0);
		execve(cmd->args[0], cmd->args, env);
		exit(1);
	}
	if (must_wait && waitpid(cmd->pid, &status, 0))
		cmd_handle_status(cmd, status);
}

static void		cmd_exec_group(t_cmd *cmd, char **env)
{
	int		to_close;
	t_cmd	*current;
	int		p[2];

	current = cmd;
	to_close = 0;
	ft_bzero(p, sizeof(int) * 2);
	while (current)
	{
		cmd_link_pipe(current, p);
		cmd_exec_single(current, env, 0);
		if (p[1])
			close(p[1]);
		if (to_close)
			close(to_close);
		to_close = p[0];
		current = current->children;
	}
	cmd_wait_group(cmd);
}

int				cmd_exec(t_cmd *cmd)
{
	char	**env;
	t_cmd	*next;

	env = get_env();
	(cmd->children) ? cmd_exec_group(cmd, env) : cmd_exec_single(cmd, env, 1);
	if (cmd->ret == 130)
		return (130);
	if (cmd->then && ((!cmd->ret && cmd->ctype == AND) || (cmd->ret &&
		cmd->ctype == OR)))
		cmd->ret = cmd_exec(cmd->then);
	else if (cmd->then)
	{
		next = cmd->then;
		while (next && cmd->ctype == next->ctype)
			next = next->then;
		if (next && next->then && next->ctype != cmd->ctype)
			return (cmd_exec(next->then));
	}
	return (cmd->ret);
}
