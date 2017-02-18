/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_doublesplit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:03:58 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 18:04:02 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	countwords(char *str)
{
	int res;

	if (!str)
		return (1);
	res = 1;
	while (*str)
	{
		if (*str == '$' || *str == ' ')
			res++;
		str++;
	}
	return (res + 1);
}

char		**str_doublesplit(char *str)
{
	char	**array;
	char	*word;
	int		i;
	int		len;

	i = 0;
	if (!(array = (char **)ft_memalloc(sizeof(char *) * countwords(str))))
		exit_shell(ERR_MALLOC);
	while (*str)
	{
		if ((*str == '$' && *(str + 1) && *(str + 1) != ' ') || *str == ' ')
		{
			while (*str && *str != ' ' && *str != '$')
			{
				len++;
				str++;
			}
			if (!(array[i++] = ft_strsub((str - len), 0, len)))
				exit_shell(ERR_MALLOC);
			len = 0;
		}
		str++;
	}
	array[i] = NULL;
	return (array);
}
