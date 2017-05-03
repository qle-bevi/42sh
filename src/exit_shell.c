/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:40:00 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/05/03 18:48:46 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	stop_jobs(t_shell *sh)
{
	t_job	*job;
	t_job	*next;

	job = sh->jobs;
	while (job)
	{
		next = job->next;
		job_terminate(job, 130);
		shell_remove_a_job(sh, job);
		job = next;
	}
}

static void	free_store(char *store[STORE_SIZE])
{
	free(store[HOMEDIR]);
	free(store[PWD]);
	free(store[OLDPWD]);
	free(store[LOGNAME]);
}

void		exit_shell(char *msg, int code)
{
	t_shell *sh;

	sh = get_shell();
	if (sh->jobs)
		stop_jobs(sh);
	if (sh->prompt)
		free(sh->prompt);
	if (sh->env)
		h_free(&sh->env, true);
	if (sh->vars)
		h_free(&sh->vars, true);
	if (sh->bins)
		h_free(&sh->bins, true);
	if (sh->aliases)
		h_free(&sh->aliases, true);
	free_store(sh->store);
	set_term_mode(TM_NORMAL);
	histo_list_to_file_wo(sh->histo_path, sh->histo);
	free(sh->histo_path);
	if (sh->histo)
		unload_histo(&sh->histo);
	if (msg)
		print_error(msg, NULL);
	exit(code);
}
