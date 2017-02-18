/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_fds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:42:56 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 17:43:03 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	restore_fds(void)
{
	static t_shell *sh = NULL;

	if (!sh)
		sh = get_shell();
	dup2(sh->save_in, 0);
	dup2(sh->save_out, 1);
	dup2(sh->save_err, 2);
}
