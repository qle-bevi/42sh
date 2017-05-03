/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:38:51 by aschafer          #+#    #+#             */
/*   Updated: 2017/05/03 19:18:01 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "cmd.h"

static	char	**tabdup(char **arr)
{
	char	**new;
	size_t	size;
	int		i;

	if (!arr)
		return (NULL);
	new = NULL;
	size = sizeof(char *) * (ft_tablen(arr) + 1);
	new = shalloc(size);
	i = -1;
	while (arr[++i])
	{
		if (!(new[i] = ft_strdup(arr[i])))
			exit_shell(ERR_MALLOC, 1);
	}
	return (new);
}

int				do_exec(char **args, char **env)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)shalloc(sizeof(t_cmd));
	cmd->args = tabdup(args);
	cmd->env = env;
	shell_create_and_run_job(get_shell(), cmd, 0);
	return (0);
}
