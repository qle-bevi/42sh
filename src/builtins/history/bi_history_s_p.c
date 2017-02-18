/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_history_s_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:06:23 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 20:07:57 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	bi_history_s(t_bi_histo *current, t_shell *sh)
{
	if (current->arg)
	{
		sh->histo->value = ft_strredup(sh->histo->value, current->arg);
		sh->histo->session = 1;
	}
	return (0);
}

int	bi_history_p(t_bi_histo *current, t_shell *sh)
{
	char	**args;
	int		i;

	if (!current->arg)
		return (0);
	i = 0;
	args = ft_strsplit(current->arg, ' ');
	while (args[i])
	{
		ft_putendl_fd(args[i], 1);
		i++;
	}
	ft_rfreetab((void ***)&args);
	if (sh->nb_histo == 1)
	{
		unload_histo(&sh->histo);
		return (0);
	}
	bi_histo_del_one_entry(sh->histo, sh);
	if (sh->histo)
	{
		sh->histo = sh->histo->prev;
		sh->histo->next = NULL;
	}
	return (0);
}
