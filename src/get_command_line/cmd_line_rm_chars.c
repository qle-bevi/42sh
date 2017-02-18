/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_rm_chars.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 23:58:08 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 19:29:36 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_command_line.h"

t_cl_char		*del_chars(t_cl_char *list)
{
	t_cl_char *next;

	if (!list->c)
	{
		list->prev = NULL;
		return (list);
	}
	next = list->next;
	free(list);
	return (del_chars(next));
}

void			cmd_line_rm_chars(t_cmd_line *cl)
{
	cmd_line_clear(cl);
	cl->chars = del_chars(cl->chars);
	cl->cursor = cl->chars;
	cl->len = 0;
	cl->index = 0;
	cmd_line_render(cl);
}
