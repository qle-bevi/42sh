/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_quotes_tools.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:27:50 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/05/05 15:35:51 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_command_line.h"
#define IGNORE array1[4][0]

void			cmd_line_free_scope_tab(int **array1)
{
	int	i;

	i = 0;
	while (i <= 4)
	{
		free(array1[i]);
		i++;
	}
	free(array1);
}

static int		**check_each_char(char *c, int i, int **array1)
{
	int	j;

	j = -1;
	while (j++ < 3)
	{
		if (*c == (char)array1[j][0])
		{
			if ((i && *(c - 1) == '\\') && !((i > 1) && *(c - 2) == '\\'))
				return (array1);
			if (j == 0 || j == 1)
			{
				if (!array1[2][1])
				{
					if ((j == 0 && !array1[1][1]) || (j == 1 && !array1[0][1]))
						array1[j][1] = array1[j][1] ? 0 : 1;
				}
			}
			else if (j == 2)
			{
				array1[2][1] = array1[2][1] ? 0 : 1;
				IGNORE = IGNORE ? 0 : 1;
			}
		}
	}
	return (array1);
}

static int		**check_pipe(char *str, int **array1)
{
	char *tmp;

	if (!IGNORE)
	{
		if (!(tmp = ft_strchr(str, '|')))
			return (array1);
		tmp++;
		while (*tmp)
		{
			if (*tmp == ' ')
				tmp++;
			else
				return (array1);
		}
		array1[3][1] = 1;
	}
	return (array1);
}

int				**quotes_check_opened(char *str, int **array1)
{
	int i;

	i = 0;
	while (str[i])
	{
		array1 = check_each_char(str + i, i, array1);
		i++;
	}
	check_pipe(str, array1);
	return (array1);
}
