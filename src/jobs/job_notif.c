/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_notif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 06:37:08 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/30 18:34:05 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	job_notif(t_job *job, char *status)
{
	char *str;

	if (!(str = ft_itoa(job->id)))
		exit_shell(ERR_MALLOC, 1);
	print_hooks(str);
	print_hooks(status);
	ft_putchar('\n');
	free(str);
}
