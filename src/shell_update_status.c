/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_update_status.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 04:27:32 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/29 21:35:37 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "job.h"

void	shell_update_status(t_shell *sh)
{
	int		status;
	int		i;
	pid_t	pid;

	i = 0;
	while ((pid = waitpid(-1, &status, WNOHANG | WUNTRACED)))
	{
		if (pid == -1)
			return ;
		if (pid)
			update_jobs(sh->jobs, pid, status);
	}
}
