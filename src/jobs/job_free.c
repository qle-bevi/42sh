/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:52:46 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/30 18:33:04 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job.h"
#include "libft.h"
#include <stdlib.h>

void	job_free(t_job *job)
{
	if (job->title)
		free(job->title);
	cmd_free(&job->cmds);
	ft_memdel((void **)&job);
}
