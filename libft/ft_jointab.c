/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jointab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:42:31 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/30 21:12:24 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_jointab_sep(char **array, char *sep)
{
	char	*str;
	int		i;
	int		len;
	int		sep_len;

	i = 0;
	len = 1;
	sep_len = ft_strlen(sep);
	while (array[i])
		len += ft_strlen(array[i++]);
	len += (ft_tablen(array) - 1) * sep_len;
	if (!(str = ft_memalloc(sizeof(char *) * (len + 1))))
		return (NULL);
	i = 0;
	while (array[i])
	{
		ft_strcat(str, array[i]);
		if (array[i + 1])
			ft_strcat(str, sep);
		++i;
	}
	return (str);
}

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
