/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jointab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:42:31 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 20:43:00 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_jointab(char **array)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = 1;
	while (array[i])
		len += ft_strlen(array[i++]);
	if (!(str = ft_memalloc(sizeof(char *) * len)))
		return (NULL);
	i = 0;
	while (array[i])
		ft_strcat(str, array[i++]);
	return (str);
}
