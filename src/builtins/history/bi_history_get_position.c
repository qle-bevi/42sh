/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_history_get_position.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:55:33 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 19:55:37 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_histo	*bi_history_get_pos(t_histo *last, int n)
{
	t_histo *tmp;

	tmp = last;
	if (!last)
		return (NULL);
	while (tmp->prev)
		tmp = tmp->prev;
	if (n == -1 || n == 1)
		return (tmp);
	else
	{
		n--;
		while (n && tmp->next)
		{
			tmp = tmp->next;
			n--;
		}
	}
	return (tmp);
}
