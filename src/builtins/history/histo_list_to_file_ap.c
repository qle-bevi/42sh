/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histo_list_to_file_ap.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:09:56 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 20:10:04 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_command_line.h"
#include "shell.h"

int	histo_list_to_file_ap(char *path, t_histo *last)
{
	t_histo	*tmp;
	int		fd;

	if (!last)
		return (0);
	if (!(fd = open(path, O_CREAT | O_WRONLY | O_APPEND)))
	{
		ft_putendl_fd("Failed to open historic file descriptor.", 2);
		return (1);
	}
	tmp = bi_history_get_pos(last, 1);
	while (tmp)
	{
		if (tmp->session)
			ft_putendl_fd(tmp->value, fd);
		tmp->session = 0;
		tmp = tmp->next;
	}
	close(fd);
	return (0);
}
