/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:50:34 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/05/03 18:47:48 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "shell.h"

static void	free_redirs(t_redir *redir)
{
	if (!redir)
		return ;
	free_redirs(redir->next);
	if (redir->path)
		free(redir->path);
	if (redir->to > 2)
		close(redir->to);
	free(redir);
}

t_cmd		*cmd_free(t_cmd **cmd)
{
	if ((*cmd)->args)
		ft_rfreetab((void ***)&(*cmd)->args);
	free_redirs((*cmd)->redirs);
	if ((*cmd)->children)
		cmd_free(&(*cmd)->children);
	if ((*cmd)->then)
		cmd_free(&(*cmd)->then);
	if ((*cmd)->pidstr)
		free((*cmd)->pidstr);
	return ((t_cmd *)ft_memdel((void **)cmd));
}
