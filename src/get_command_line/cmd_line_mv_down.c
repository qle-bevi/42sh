/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_mv_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 23:09:13 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 19:26:23 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_command_line.h"

void	cmd_line_mv_down(t_cmd_line *cl)
{
	int dest;

	dest = cl->cols;
	while (dest-- && cl->cursor->next)
		cmd_line_mv_right(cl);
}
