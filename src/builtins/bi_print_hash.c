/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_print_hash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:36:45 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/30 17:57:22 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	bi_print_hash(t_shell *sh, char **args)
{
	if (!args[0])
	{
		ft_putendl("print need an option [bins, env]");
		return (1);
	}
	if (!ft_strcmp(args[0], "env"))
		h_print(sh->env, VAL_OK | NUM_OK | LEN_OK);
	else if (!ft_strcmp(args[0], "bins"))
		h_print(sh->bins, VAL_OK | NUM_OK | LEN_OK);
	else
	{
		ft_putendl("print Illegal option [bins, env]");
		return (1);
	}
	return (0);
}
