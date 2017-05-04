/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atheveno <atheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 20:22:52 by atheveno          #+#    #+#             */
/*   Updated: 2017/05/04 20:23:06 by atheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		extract_key(char *str, char **dest)
{
	int	i;

	i = 0;
	if (*str != '$')
		return (0);
	++str;
	if (*str == '?' || *str == '_')
		i = 1;
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

void	get_append_value(char *key, char *buffer, int *i)
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

void	extract_var(char **strp, char *buffer, int *i)
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
