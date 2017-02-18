/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 02:05:05 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/01/30 08:07:41 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "get_command_line.h"

void		cmd_line_write(t_cmd_line *cl, char c)
{
	t_cl_char *new;

	cmd_line_clear(cl);
	new = shalloc(sizeof(t_cl_char));
	new->next = cl->cursor;
	new->c = c;
	if (cl->cursor->prev)
		cl->cursor->prev->next = new;
	else
		cl->chars = new;
	new->prev = cl->cursor->prev;
	cl->cursor->prev = new;
	++cl->len;
	++cl->index;
	cmd_line_render(cl);
}
