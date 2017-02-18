/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 12:42:06 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/01/27 22:16:54 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_free_str_array(char ***array)
{
	char	**arr;
	int		i;

	if (!array || !(arr = *array))
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	ft_memdel((void **)array);
}
