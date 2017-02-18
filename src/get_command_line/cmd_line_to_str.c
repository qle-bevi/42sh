/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_to_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 23:40:55 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/01/30 15:27:58 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "get_command_line.h"

char	*cmd_line_to_str(t_cmd_line *cl, int len)
{
	t_cl_char		*current;
	char			*ret;
	char			*temp;
	int				i;

	if (!(ret = ft_strnew(len > 0 ? len : 1)))
		exit_shell(ERR_MALLOC, 1);
	current = cl->chars;
	i = 0;
	while (current && i < len)
	{
		ret[i++] = current->c;
		current = current->next;
	}
	if (*ret)
	{
		temp = ret;
		ret = ft_strtrim(ret);
		free(temp);
	}
	return (ret);
}
