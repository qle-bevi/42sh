/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:38:22 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/05/03 18:48:52 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	has_stopped_jobs(t_job *jobs)
{
	while (jobs)
	{
		if (jobs->stopped)
			return (1);
		jobs = jobs->next;
	}
	return (0);
}

int			bi_exit(t_shell *sh, char **args)
{
	if (args[0] && !str_is_digit(args[0]))
	{
		ft_putendl_fd("exit code should be a digit!", 2);
		return (1);
	}
	if (has_stopped_jobs(sh->jobs))
	{
		ft_putendl_fd("They are stopped jobs.", 2);
		return (1);
	}
	exit_shell(NULL, (args[0]) ? ft_atoi(args[0]) : 0);
	return (0);
}
