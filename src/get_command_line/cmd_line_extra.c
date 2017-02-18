/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:45:20 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/01/27 21:57:46 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_command_line.h"

void	cmd_line_free(t_cmd_line *cl)
{
	cl->chars = del_chars(cl->chars);
	ft_memdel((void **)&cl->chars);
	if (cl->search)
		ft_memdel((void **)&cl->search);
}

int		cmd_line_ctrl_c(t_cmd_line *cl, char **str)
{
	ft_putstr("\n");
	cmd_line_free(cl);
	return ((*str = NULL) ? -2 : -2);
}

int		cmd_line_validate(t_cmd_line *cl, char **str)
{
	*str = cmd_line_to_str(cl, cl->len);
	cmd_line_free(cl);
	return ((*str) ? 1 : -1);
}
