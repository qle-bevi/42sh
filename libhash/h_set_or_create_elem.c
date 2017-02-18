/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_set_or_create_elem.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:27:05 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 17:27:06 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

t_elem	*h_set_or_create_elem(t_hash *hash, char *key, char *value)
{
	t_elem *elem;

	if ((elem = h_get_elem_by_key(hash, key)))
	{
		ft_memdel((void **)&(elem->value));
		elem->value = ft_strdup(value);
	}
	else
		elem = h_add_elem(hash, key, value);
	return (elem);
}
