/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_expand_vars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <jbouloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 22:04:28 by jbouloux          #+#    #+#             */
/*   Updated: 2017/05/01 18:36:49 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

#define TSQ	0
#define TDQ	1
#define TBS	2

static int		extract_key(char *str, char **dest)
{
	int	i;

	i = 0;
	if (*str != '$')
		return (0);
	++str;
	if (*str == '?' || *str == '_')
	{
		i = 1;
	}
	else
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

	if (!ft_strcmp(key, "?"))
	{
		if (!(value = ft_itoa(get_shell()->cmd_ret)))
			exit_shell(ERR_MALLOC, 1);
	}
	else if (!(value = get_value(key)))
		return ;
	ft_strcat(buffer + *i, value);
	*i += (int)ft_strlen(value);
	free(value);
}

static void		extract_var(char **strp, char *buffer, int *i)
{
	int		len;
	char	*key;

	key = NULL;
	if (!(len = extract_key(*strp, &key)))
	{
		++(*strp);
		return ;
	}
	get_append_value(key, buffer, i);
	*strp += len + 1;
	free(key);
}

static void		handle_char(char **strp, char *triggers, char *buf, int *i)
{
	if (**strp == '\\' && !triggers[TBS] && !triggers[TSQ])
	{
		triggers[TBS] = 1;
		++*strp;
	}
	if ((**strp == '\'' || **strp == '\"') && !triggers[TBS])
	{
		if (**strp == '\'')
			triggers[TSQ] = !triggers[TSQ];
		else
			triggers[TDQ] = !triggers[TDQ];
		buf[*i] = **strp;
		++*strp;
		++*i;
	}
	else if (i && (!triggers[TSQ] || triggers[TBS])
			&& !triggers[TBS] && **strp == '$')
		extract_var(strp, buf, i);
	else
	{
		buf[*i] = **strp;
		++*strp;
		++*i;
	}
	triggers[TBS] = 0;
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
		handle_char(&str, (char *)triggers, buffer, &i);
	return (ft_strdup(buffer));
}
