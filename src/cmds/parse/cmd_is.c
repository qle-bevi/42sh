/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_is.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:59:28 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/05/05 17:42:16 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "shell.h"

int	cmd_is_operator(char *str)
{
	return (!ft_strncmp(str, "&&", 2) || !ft_strncmp(str, "||", 2));
}

int	cmd_is_redir(char *str)
{
	if (*str == '>' || *str == '<')
		return (1);
	if (ft_isdigit(*str))
	{
		while (ft_isdigit(*str))
			++str;
		while (ft_isescaped(*str) || *str == ' ')
			++str;
		return (*str == '>' || *str == '<');
	}
	return (0);
}

int	cmd_is_arg(char *str)
{
	return (*str
	&& *str != ';'
	&& *str != '|'
	&& *str != '&'
	&& !ft_isescaped(*str)
	&& *str != ' '
	&& !cmd_is_operator(str)
	&& !cmd_is_redir(str));
}

int	cmd_is_skip_char(char c)
{
	return (ft_isescaped(c) || c == ' ');
}
