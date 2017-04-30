/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_jobs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 08:21:08 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/28 20:33:50 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char	*get_flags(char ***args)
{
	static char valids[] = "lnprs";
	static char flags[6] = { 0 };
	char		c[2];
	int			i;
	char		**current_arg;

	ft_bzero(flags, sizeof(char) * 6);
	i = 0;
	c[1] = 0;
	while (**args && ***args == '-')
	{
		current_arg = *args + 1;
		while (*current_arg)
		{
			c[1] = **current_arg;
			if (!ft_strchr(valids, c[1]))
			{
				print_error("jobs: invalid option: ", c);
				ft_putendl("jobs [-lnprs] [jobspec]");
				return (NULL);
			}
			if (!ft_strchr(flags, c[1]) && ft_strchr(valids, c[1]))
				flags[i++] = c[1];
			++*current_arg;
		}
		++*args;
	}
	return ((char *)&flags);
}

static t_job	*add_job(t_job **jlist, t_job *job)
{
	t_job	*dup;
	t_job	*current;

	dup = shalloc(sizeof(t_job));
	ft_memcpy(dup, job, sizeof(t_job));
	dup->next = NULL;
	if (!(current = *jlist))
		return (*jlist = dup);
	while (current->next)
		current = current->next;
	return ((current->next = dup));
}

static t_job	*get_jobs(t_job *jobs, char flags[6])
{
	t_job	*jobs_list;

	jobs_list = NULL;
	while (jobs)
	{
		if (!jobs->next)
			break ;
		if (!ft_strchr(flags, 'n') || (!jobs->notified && (jobs->done || jobs->stopped)))
		{
			if ((ft_strchr(flags, 's') && jobs->stopped)
			|| (ft_strchr(flags, 'r') && !jobs->stopped && !jobs->done)
			|| (!ft_strchr(flags, 's') && !ft_strchr(flags, 'r')))
				add_job(&jobs_list, jobs);
		}
		jobs = jobs->next;
	}
	return (jobs_list);
}

int			bi_jobs(t_shell *sh, char **args)
{
	t_job	*current_job;
	t_job	*to_free;
	char	*flags;
	char	*id;

	shell_update_status(sh);
	if (!(flags = get_flags(&args)))
		return (1);
	if (!(current_job = get_jobs(sh->jobs, flags)))
		return (0);
	while (current_job)
	{
		if(!(id = ft_itoa(current_job->id)))
			exit_shell(ERR_MALLOC, 1);
		print_hooks(id);
		print_hooks(current_job->current_cmd->args[0]);
		if (current_job->done)
			print_hooks("terminated");
		else
			print_hooks((current_job->stopped) ? "stopped" : "running...");
		ft_putchar('\n');
		to_free = current_job;
		current_job = current_job->next;
		free(to_free);
		free(id);
	}
	return (0);
}
