/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_get_redir_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 02:09:51 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/30 18:25:08 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "shell.h"

static int		heredoc(char *path)
{
	int		heredocp[2];
	int		ret;
	char	*line;

	pipe(heredocp);
	line = NULL;
	while ((ret = get_line("heredoc > ", &line)))
	{
		if (ret == -1)
			exit_shell(ERR_READ, 1);
		if (!line)
			break ;
		if (!ft_strcmp(path, line))
		{
			ft_memdel((void **)&line);
			break ;
		}
		ft_putendl_fd(line, heredocp[1]);
		free(line);
	}
	close(heredocp[1]);
	return (heredocp[0]);
}

static int		get_flags(int type)
{
	int flags;

	flags = 0;
	if (type == READ)
		flags |= O_RDONLY;
	else
		flags |= O_CREAT | O_WRONLY;
	if (type == APPEND)
		flags |= O_APPEND;
	else if (type == WRITE)
		flags |= O_TRUNC;
	return (flags);
}

int				cmd_get_redir_fd(t_redir *redir)
{
	int	flags;

	if (redir->to != -2)
		return (redir->to);
	if (redir->rtype == HD)
		return (redir->to = heredoc(redir->path));
	flags = get_flags(redir->rtype);
	if (redir->rtype == READ && (check_access(redir->path, R_OK) == -1))
		return (redir->to = -1);
	return (redir->to = open(redir->path, flags, 0666));
}
