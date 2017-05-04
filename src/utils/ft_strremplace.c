/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremplace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atheveno <atheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 20:22:45 by atheveno          #+#    #+#             */
/*   Updated: 2017/05/04 20:22:46 by atheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*ft_strremplace(char *s1, size_t start, size_t length, char *s2)
{
	char	*tmp;
	size_t	len;

	tmp = NULL;
	len = 0;
	if (s1 != NULL && s2 != NULL && length > 0)
	{
		len = ft_strlen(s1);
		tmp = ft_strnew(len - length + ft_strlen(s2));
		if (tmp)
		{
			ft_memcpy(&tmp[0], &s1[0], start);
			ft_memcpy(&tmp[start], s2, ft_strlen(s2));
			ft_memcpy(&tmp[start + ft_strlen(s2)], &s1[length + start],
					len - start - length);
		}
	}
	else
		return (NULL);
	return (tmp);
}
