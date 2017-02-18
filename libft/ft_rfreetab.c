/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rfreetab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 12:58:35 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/01/27 18:57:28 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_rfreetab(void ***arr)
{
	int i;

	if (!arr || !*arr)
		return ;
	i = 0;
	while ((*arr)[i])
		free((*arr)[i++]);
	ft_memdel((void **)arr);
}
