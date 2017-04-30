/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_expand_vars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <jbouloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 22:04:28 by jbouloux          #+#    #+#             */
/*   Updated: 2017/04/30 19:01:18 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
# define TSQ	0
# define TDQ		1
# define TBS	2


static int		extract_key(char *str, char **dest)
{
	int	i;

	i = 0;
	if (*str != '$')
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

static void 	extract_var(char **strp, char *buffer, int *i)
{
	int len;
	char *key;

	key = NULL;
	if (!(len = extract_key(*strp, &key)))
	{
		++(*strp);
		return ;
	}
	get_append_value(key, buffer, i);
	*strp += len;
	free(key);
}

static int		is_escaped(char c)
{
	return (c == 'n' || c == 'r' || c == 't');
}

char			*str_expand_vars(char *str)
{
	static char	buffer[10000] = { 0 };
	static int	triggers[3] = { 0 };
	int			i;

	ft_bzero(buffer, 10000);
	ft_bzero(triggers, sizeof(char) * 3);
	i = 0;
	while (*str)
	{
		if (*str == '\\' && !triggers[TBS] && !triggers[TSQ] && !is_escaped(*(str + 1)))
		{
			triggers[TBS] = 1;
			++str;
		}
		if ((*str == '\'' || *str == '\"') && !triggers[TBS])
		{
			if (*str == '\'')
				triggers[TSQ] = !triggers[TSQ];
			else
				triggers[TDQ] = !triggers[TDQ];
			buffer[i++] = *str;
		}
		else if (i && (!triggers[TSQ] || triggers[TBS])
		&& !triggers[TBS] && *str == '$' )
			extract_var(&str, buffer, &i);
		else
			buffer[i++] = *str;
		++str;
		triggers[TBS] = 0;
	}
	return (ft_strdup(buffer));
}
