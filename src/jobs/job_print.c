/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 12:35:38 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/13 12:35:38 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job.h"
#include "libft.h"

void	job_print(t_job *job)
{
	job_notify(job, (job->stopped) ? "stopped" : "running...", 0);
	job_format(*job->current_cmd->args);
	ft_putchar('\n');
}