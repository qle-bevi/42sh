/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_expand_vars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <jbouloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 22:04:28 by jbouloux          #+#    #+#             */
/*   Updated: 2017/02/17 15:56:18 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		extract_key(char *str, char **dest, int nfirst)
{
	int	i;

	i = 0;
	if (*str != '$')
		return (0);
	if (nfirst && *(str - 1) == '\\')
		return (0);
	++str;
	while (str[i] && ft_isalnum(str[i]))
		++i;
	if (!i)
		return (0);
	if (!(*dest = ft_strnew(i)))
		exit_shell(ERR_MALLOC, 1);
	ft_strncat(*dest, str, i);
	return (i);
}

static void		get_append_value(char *key, char *buffer, int *i)
{
	char *value;

	if (!(value = get_value(key)))
		return ;
	ft_strcat(buffer + *i, value);
	*i += (int)ft_strlen(value);
	free(value);
}

char			*str_expand_vars(char *str)
{
	static char	buffer[10000] = { 0 };
	int			i;
	int			key_len;
	char		*key;

	ft_bzero(buffer, 10000);
	i = 0;
	key = NULL;
	while (*str)
	{
		if ((key_len = extract_key(str, &key, i)))
		{
			get_append_value(key, buffer, &i);
			ft_memdel((void **)&key);
			str += key_len;
		}
		else if (*str != '\\' || *(str + 1) != '$')
			buffer[i++] = *str;
		++str;
	}
	return (ft_strdup(buffer));
}
