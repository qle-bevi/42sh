/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:38:51 by aschafer          #+#    #+#             */
/*   Updated: 2017/04/10 17:11:58 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "cmd.h"

int			do_exec(char **args, char **env)
{
	t_cmd	*cmd;
	int		ret;

	cmd = (t_cmd *)shalloc(sizeof(t_cmd));
	cmd->args = args;
	cmd_exec_single(cmd, 0, env);
	ret = cmd->ret;
	free(cmd);
	return (ret);
}
