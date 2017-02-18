/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_lst_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:25:27 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 17:25:28 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

t_elem	*lst_new_elem(char *key, char *value)
{
	t_elem *new_elem;

	if (!(new_elem = (t_elem *)malloc(sizeof(t_elem))))
		return (NULL);
	new_elem->key = key;
	new_elem->value = value;
	new_elem->next = NULL;
	return (new_elem);
}
