/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_mv_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 02:46:30 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 19:26:53 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_command_line.h"

void	cmd_line_mv_left(t_cmd_line *cl)
{
	if (!cl->cursor->prev)
		return ;
	ft_putstr(tgetstr("le", NULL));
	--cl->col;
	--cl->index;
	if (!cl->col)
		cl->col = cl->cols;
	cl->cursor = cl->cursor->prev;
}
