/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_histo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:31:27 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 19:35:29 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_command_line.h"

void	load_histo(t_histo **histo, char *path, int session)
{
	int		fd;
	int		ret;
	char	*line;

	if ((fd = open(path, O_CREAT | O_RDONLY, 0666)) == -1)
		return (ft_putendl_fd("Failed to open historic file descriptor.", 2));
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
		{
			ft_putendl_fd("Corrupted historic !.", 2);
			return ;
		}
		add_histo(histo, line, session);
		ft_memdel((void **)&line);
	}
	ft_memdel((void **)&line);
}
