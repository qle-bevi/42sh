/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_source.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:36:19 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/02/18 19:23:06 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	check_validity(char *path)
{
	struct stat stati;

	if (check_access(path, R_OK))
		return (0);
	if (lstat(path, &stati) == -1)
	{
		print_error("source: stat error: ", path);
		return (0);
	}
	if (!S_ISREG(stati.st_mode))
	{
		print_error("source: not a valid file: ", path);
		return (0);
	}
	return (1);
}

int			bi_source(t_shell *sh, char **args)
{
	int			is_interactive;
	int			fd;

	if (!*args)
	{
		print_error("source: not enough arguments.", NULL);
		return (-1);
	}
	if (!check_validity(args[0]))
		return (-1);
	if ((fd = open(args[0], O_RDONLY)) == -1)
	{
		print_error("source: open error: ", args[0]);
		return (-1);
	}
	is_interactive = sh->is_interactive;
	sh->is_interactive = 0;
	shell_source_fd(sh, fd);
	sh->is_interactive = is_interactive;
	close(fd);
	return (0);
}
