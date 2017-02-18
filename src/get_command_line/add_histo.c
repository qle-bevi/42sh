/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_histo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:24:58 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 19:25:04 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_command_line.h"
#include "shell.h"

t_histo	*add_histo(t_histo **histo, char *str, int session)
{
	t_histo *new;
	t_shell *sh;

	sh = get_shell();
	if (!str || !*str)
		return (NULL);
	if (!(new = (t_histo *)ft_memalloc(sizeof(t_histo))))
		return (NULL);
	if (!(new->value = ft_strtrim(str)))
	{
		free(new);
		return (NULL);
	}
	new->prev = *histo;
	new->session = session;
	if (*histo)
		(*histo)->next = new;
	sh->nb_histo++;
	return (*histo = new);
}
