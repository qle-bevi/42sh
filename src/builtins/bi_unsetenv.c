/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:35:48 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/05/03 22:16:42 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	u_msg(char *key, int n)
{
	if (n == 0)
	{
		ft_putstr_fd(key, 1);
		ft_putendl_fd(" key has been deleted", 1);
	}
	else if (n == 1)
		print_error(" key not found : ", key);
}

int			bi_unsetenv(t_shell *sh, char **args)
{
	int	i;

	i = 0;
	if (!args[0])
		ft_putendl_fd("unsetenv: usage: [name ...]", 1);
	while (args[i])
	{
		h_delete_elem(sh->env, args[i]) ? u_msg(args[i], 0) : u_msg(args[i], 1);
		if (!ft_strcmp(args[i], "PATH"))
			shell_update_bins(sh);
		i++;
	}
	sh->env_update = 1;
	return (0);
}
