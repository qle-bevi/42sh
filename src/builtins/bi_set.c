/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:36:34 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/05/04 16:57:53 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			bi_set(t_shell *sh, char **args)
{
	int	size;
	int	err;

	if (!args || !*args)
		return (bi_env(sh, args));
	size = ft_tablen(args);
	err = (str_is_alnum(args[0])) ? 0 : 1;
	if (size < 3 && !err)
	{
		if (ft_isdigit(args[0][0]))
		{
			ft_putendl_fd("set: variable name must begin with a letter", 2);
			return (1);
		}
		if (h_get_elem_by_key(sh->env, args[0]))
			return (bi_setenv(sh, args));
		h_set_or_create_elem(sh->vars, args[0], args[1]);
	}
	else
	{
		ft_putendl_fd((err) ? "set: only alphanum allowed in name."
		: "set: usage: [name value]", 2);
		return (1);
	}
	return (0);
}
