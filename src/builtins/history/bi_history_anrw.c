/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_history_anrw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:42:58 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 19:43:50 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	bi_history_anrw(t_bi_histo **current)
{
	return ((*current)->flag == 'a' || (*current)->flag == 'n'
	|| (*current)->flag == 'r' || (*current)->flag == 'w');
}

int	bi_history_a(t_bi_histo *current, t_shell *sh)
{
	if (current->arg)
		return (0);
	return (histo_list_to_file_ap(sh->histo_path, sh->histo));
}

int	bi_history_w(t_bi_histo *current, t_shell *sh)
{
	return (histo_list_to_file_wo(current->arg ? current->arg : \
		sh->histo_path, sh->histo));
}

int	bi_history_n(t_bi_histo *current, t_shell *sh)
{
	if (current->arg)
		return (0);
	unload_histo(&sh->histo);
	load_histo(&sh->histo, sh->histo_path, 0);
	return (0);
}

int	bi_history_r(t_bi_histo *current, t_shell *sh)
{
	load_histo(&sh->histo, current->arg ? current->arg : sh->histo_path, 1);
	return (0);
}
