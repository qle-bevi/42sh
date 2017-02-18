/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_histo_down.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:25:46 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 19:26:04 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_command_line.h"

void	cmd_line_histo_down(t_cmd_line *cl)
{
	if (!cl->histo || !cl->search)
		return ;
	cl->histo = cl->histo->next;
	if (!*cl->search && cl->histo)
		return (cmd_line_set_text(cl, cl->histo->value));
	while (cl->histo)
	{
		if (!ft_strncmp(cl->histo->value, cl->search, ft_strlen(cl->search)))
			return (cmd_line_set_text(cl, cl->histo->value));
		cl->histo = cl->histo->next;
	}
	ft_memdel((void **)&cl->search);
	cmd_line_set_text(cl, "");
}
