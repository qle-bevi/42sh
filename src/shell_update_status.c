/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_update_status.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 04:27:32 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/28 19:57:48 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "job.h"

void	shell_update_status(t_shell *sh)
{
	int		status;
	pid_t	pid;

	while ((pid = waitpid(-1, &status, WNOHANG | WUNTRACED)))
	{
		if (pid == -1) break ;
		update_jobs(sh->jobs, pid, status);
	}
}
