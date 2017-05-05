/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_source_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:44:41 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/05/05 15:00:34 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	shell_source_fd(t_shell *sh, int fd)
{
	int		ret;
	char	*line;

	line = NULL;
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			return (exit_shell(ERR_READ, 1));
		if (*line != '#')
			shell_source_line(sh, &line);
		ft_memdel((void **)&line);
	}
	if (line)
		free(line);
}
