/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:36:34 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/01/30 00:15:55 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	update_env(t_shell *sh, char **args)
{
	if (!ft_strcmp(args[0], "PATH"))
		shell_update_bins(get_shell());
	else if (!ft_strcmp(args[0], "HOME"))
		sh->store[HOMEDIR] = ft_strredup(sh->store[HOMEDIR], args[1]);
	sh->env_update = 1;
}

int			bi_setenv(t_shell *sh, char **args)
{
	int	size;
	int	err;

	if (!args || !*args)
		return (bi_env(sh, args));
	size = ft_tablen(args);
	err = (ft_strchr(args[0], '=')) ? 1 : 0;
	if (size < 3 && !err)
	{
		if (str_is_digit(args[0]))
		{
			ft_putendl_fd("setenv: name can't be an integer", 2);
			return (1);
		}
		else
			h_set_or_create_elem(sh->env, args[0], args[1]);
	}
	else
	{
		ft_putendl_fd((err) ? "setenv: no '=' allowed in name."
		: "setenv: usage: [name value]", 2);
		return (1);
	}
	update_env(sh, args);
	return (0);
}
