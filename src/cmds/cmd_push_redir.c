/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 21:12:57 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/10 17:07:17 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "shell.h"

void	cmd_push_redir_end(t_redir **redirp, t_redir *new)
{
	t_redir *current;

	if (!(current = *redirp))
	{
		*redirp = new;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = new;
}

void	cmd_push_redir_front(t_redir **redirp, t_redir *new)
{
	new->next = *redirp;
	*redirp = new;
}
