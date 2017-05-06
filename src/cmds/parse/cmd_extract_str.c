/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_extract_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 21:02:34 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/05/06 17:06:55 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "shell.h"

#define MAX_SIZE 500
#define TSQ 0
#define TDQ 1
#define TBS 2

static int	should_stop(char c, char *triggers)
{
	if (c == '\n')
		return (0);
	return ((cmd_is_skip_char(c) || c == ';' || c == '|') &&
			!triggers[TBS] && !triggers[TDQ] && !triggers[TSQ]);
}

static int	handle_char(char **strp, char *triggers, char *buffer, int *i)
{
	if (**strp == '\\' && !triggers[TSQ])
	{
		triggers[TBS] = !triggers[TBS];
		++*strp;
	}
	if (**strp == '\'' && !triggers[TDQ] && !triggers[TBS])
		triggers[TSQ] = !triggers[TSQ];
	else if (**strp == '\"' && !triggers[TSQ] && !triggers[TBS])
		triggers[TDQ] = !triggers[TDQ];
	else if (should_stop(**strp, triggers))
		return (1);
	else
	{
		buffer[*i] = **strp;
		++*i;
	}
	++*strp;
	triggers[TBS] = 0;
	return (0);
}

char		*cmd_extract_str(char **strp)
{
	static char	buffer[MAX_SIZE + 1];
	char		triggers[3];
	int			i;

	ft_bzero(buffer, sizeof(char) * (MAX_SIZE + 1));
	ft_bzero(triggers, sizeof(char) * 3);
	i = 0;
	while (strp && *strp && **strp)
	{
		if (i == MAX_SIZE)
			exit_shell("Argument is too big !", 1);
		if (handle_char(strp, (char *)triggers, buffer, &i))
			break ;
	}
	return (ft_strdup(buffer));
}
