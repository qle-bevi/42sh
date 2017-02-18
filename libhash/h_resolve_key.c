/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_resolve_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:26:39 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 17:26:40 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

int	h_get_key(int size, char *key)
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	while (key[i])
	{
		if (key[i + 1])
			ret += key[i] * (key[i + 1] * i);
		else
			ret += key[i] * i;
		i++;
	}
	return (ret % size);
}
