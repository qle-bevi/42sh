/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histo_list_to_file_wo.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:10:32 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 20:11:00 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	histo_list_to_file_wo(char *path, t_histo *last)
{
	t_histo	*tmp;
	int		file;
	int		fd;

	if (!(fd = open(path, O_CREAT | O_WRONLY | O_TRUNC)))
		ft_putendl_fd("Failed to open historic file descriptor.", 2);
	if (!fd)
		return (1);
	if (!last)
	{
		ft_putstr_fd("", fd);
		close(fd);
		return (0);
	}
	tmp = bi_history_get_pos(last, -1);
	file = (ft_strcmp(path, get_shell()->histo_path)) ? 0 : 1;
	while (tmp)
	{
		ft_putendl_fd(tmp->value, fd);
		if (file)
			tmp->session = 0;
		tmp = tmp->next;
	}
	close(fd);
	return (0);
}
