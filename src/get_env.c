/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:40:20 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 17:40:44 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	**get_env(void)
{
	static t_shell	*sh = NULL;
	static char		**env = NULL;

	if (!sh)
		sh = get_shell();
	if (env && !sh->env_update)
		return (env);
	if (env)
		ft_free_tab(&env);
	sh->env_update = 0;
	return ((env = hash_to_tab(sh->env)));
}
