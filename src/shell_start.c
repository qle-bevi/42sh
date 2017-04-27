/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:45:18 by aschafer          #+#    #+#             */
/*   Updated: 2017/04/27 09:17:04 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "shell.h"

static void check_jobs(t_shell *sh)
{
	shell_update_status(sh);
	shell_notificate(sh);
}

static void user_loop(t_shell *sh)
{
	int		ret;
	char	*line;

	line = NULL;
	while ((ret = get_line(shell_prompt(sh), &sh->line)) != -1)
	{
		line = sh->line;
		if (!ret)
		{
			ft_putchar('\n');
			exit_shell(NULL, 0);
		}
		if (line && *line)
		{
			if (!ft_strchr(line, '\n')
			&& ((sh->histo && ft_strcmp(sh->histo->value, line)) || !sh->histo))
				add_histo(&sh->histo, line, 1);
			sh->line = ft_str_replace(sh->line, "~", sh->store[HOMEDIR], 1);
			line = sh->line;
			shell_source_line(sh, line);
		}
		ft_putchar('\n');
		check_jobs(sh);
		ft_memdel((void **)&sh->line);
	}
}

static void	interactive(t_shell *sh)
{
	while (tcgetpgrp(sh->save_in) != sh->pid)
		kill (-sh->pid, SIGTTIN);
	setpgid(sh->pid, sh->pid);
	tcsetpgrp(sh->save_in, sh->pid);
	sh->is_interactive = 1;
	user_loop(sh);
}

void	shell_start(t_shell *sh, int ac, char **av)
{
	shell_signals();
	if (ac != 1)
		bi_source(sh, av + 1);
	else if (!isatty(0))
		shell_source_fd(sh, 0);
	else
		interactive(sh);
	exit_shell(NULL, 0);
}
