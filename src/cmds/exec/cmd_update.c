/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 05:15:45 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/28 20:05:52 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "shell.h"

static void	cmd_return(t_cmd *cmd, int ret)
{
	cmd->done = 1;
	cmd->ret = ret;
}

static void	cmd_handle_signal(t_cmd *cmd, int sig)
{
	if (sig == SIGINT)
		return cmd_return(cmd, 130);
	if (sig == SIGTERM)
		return cmd_return(cmd, 1);
}

void	cmd_update(t_cmd *cmd, int status)
{
	if (WIFEXITED(status))
		return cmd_return(cmd, WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return cmd_handle_signal(cmd, WTERMSIG(status));
}
