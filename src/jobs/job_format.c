/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 12:33:49 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/13 12:33:49 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job.h"
#include "libft.h"

void job_format(char *str)
{
	static char buffer[100] = { 0 };
	int len;

	ft_bzero(buffer, sizeof(char) * 100);
	len = ft_strlen(str);
	buffer[0] = '[';
	ft_strcat(buffer + 1, str);
	buffer[len + 1] = ']';
	ft_putstr(buffer);
}