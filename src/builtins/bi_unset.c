/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:35:53 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 19:36:15 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	bi_unset(t_shell *sh, char **args)
{
	int i;

	i = 0;
	if (!args[0])
	{
		ft_putendl_fd("unset: not enough arguments", 2);
		return (1);
	}
	while (args[i])
	{
		h_delete_elem(sh->vars, args[i]);
		if (!ft_strcmp(args[i], "PATH"))
			shell_update_bins(sh);
		i++;
	}
	return (0);
}
