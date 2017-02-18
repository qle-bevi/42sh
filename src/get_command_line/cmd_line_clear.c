/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 02:43:52 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 19:25:28 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_command_line.h"

void	cmd_line_clear(t_cmd_line *cl)
{
	t_cl_char		*current;
	int				i;

	i = 0;
	current = cl->cursor;
	while (current)
	{
		ft_putstr(tgetstr("le", NULL));
		current = current->prev;
	}
	while (i++ < cl->plines)
		ft_putstr(tgetstr("up", NULL));
	ft_putstr(tgetstr("cr", NULL));
	ft_putstr(tgetstr("cd", NULL));
}
