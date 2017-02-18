/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:35:48 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 19:35:49 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	bi_unsetenv(t_shell *sh, char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		h_delete_elem(sh->env, args[i]);
		if (!ft_strcmp(args[i], "PATH"))
			shell_update_bins(sh);
		i++;
	}
	sh->env_update = 1;
	return (0);
}
