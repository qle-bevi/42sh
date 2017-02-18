/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 15:54:30 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/20 15:54:44 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	ft_lstgot(t_list *list, t_list *elem)
{
	while (list)
	{
		if (list == elem)
			return (TRUE);
		list = list->next;
	}
	return (FALSE);
}
