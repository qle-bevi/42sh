/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:43:53 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/12/09 16:43:58 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	copy_fd(int in, int out)
{
	int		ret;
	char	*line;

	line = NULL;
	while ((ret = get_next_line(in, &line)))
	{
		if (ret == -1)
			exit_shell(ERR_READ, 1);
		ft_putendl_fd(line, out);
	}
}
