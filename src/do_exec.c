/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:38:51 by aschafer          #+#    #+#             */
/*   Updated: 2017/01/31 14:19:22 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

int			do_exec(char **args, char **env)
{
	t_cmd	*cmd;
	int		ret;

	cmd = (t_cmd *)shalloc(sizeof(t_cmd));
	cmd->args = args;
	cmd_exec_single(cmd, env, 1);
	ret = cmd->ret;
	free(cmd);
	return (ret);
}
