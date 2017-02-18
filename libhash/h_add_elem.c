/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_add_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:23:52 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 17:23:53 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

t_elem	*h_add_elem(t_hash *hash, char *key, char *value)
{
	t_elem	*elem;
	int		index;

	hash->nb_elem++;
	index = h_get_key(hash->size, key);
	elem = lst_push_elem(&(hash->hash_tab[index]), \
			ft_strdup(key), ft_strdup(value));
	return (elem);
}
