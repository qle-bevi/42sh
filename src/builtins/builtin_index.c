/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:35:40 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 19:35:41 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	builtin_index(char *key)
{
	static t_builtin	*builtins = NULL;
	int					i;

	if (!builtins)
		builtins = get_builtins();
	i = 0;
	while (i < NB_BUILTINS)
	{
		if (!ft_strcmp(builtins[i].key, key))
			return (i);
		++i;
	}
	return (-1);
}
