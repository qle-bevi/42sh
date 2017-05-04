/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:36:34 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/05/04 20:00:28 by bdesbos          ###   ########.fr       */
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

static int	str_is_uppercasenum(char *str)
{
	while (*str)
	{
		if (!((*str > 64 && *str < 91) || ft_isdigit(*str)))
			return (0);
		str++;
	}
	return (1);
}

int			bi_setenv(t_shell *sh, char **args)
{
	int	size;
	int	err;

	if (!args || !*args)
		return (bi_env(sh, args));
	size = ft_tablen(args);
	err = ((size < 3) ? 0 : 1);
	if (err)
		ft_putendl_fd("setenv: usage: [name value]", 2);
	else if ((err = ft_isdigit(args[0][0])))
		print_error("setenv: variable name must begin with a letter", NULL);
	else if ((err = !str_is_alnum(args[0])))
		print_error("setenv: only alphanum allowed in name.", NULL);
	else if ((err = !str_is_uppercasenum(args[0])))
		print_error("setenv: lowercase not allowed", NULL);
	else
	{
		h_set_or_create_elem(sh->env, args[0], args[1]);
		update_env(sh, args);
	}
	return (err);
}
