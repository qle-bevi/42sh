/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 05:15:45 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/01/27 21:31:22 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

void	cmd_handle_status(t_cmd *cmd, int status)
{
	cmd->done = 1;
	if (WIFEXITED(status))
		cmd->ret = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		cmd->ret = (WTERMSIG(status) == SIGINT) ? 130 : 1;
	else
		cmd->ret = 1;
}
