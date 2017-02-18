/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_get_value_by_key.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:24:48 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 17:24:50 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

char	*h_get_value_by_key(t_hash *hash, char *key)
{
	t_elem *elem;

	if ((elem = h_get_elem_by_key(hash, key)) == NULL)
		return (NULL);
	if (elem->value == NULL)
		return (NULL);
	return (ft_strdup(elem->value));
}
