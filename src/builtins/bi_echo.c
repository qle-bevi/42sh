/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:40:44 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/29 19:48:59 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#define N 0
#define EE 1
#define E 2
#define NB_FLAGS 3

static int	is_invalid_flags(char *arg)
{
	int	i;

	i = 1;
	while (arg && arg[i])
	{
		if (arg[i] != 'n' && arg[i] != 'e' && arg[i] != 'E')
			return (1);
		else
			i++;
	}
	return (0);
}

static int	*get_flags(char **args)
{
	int *flags;
	int	i;
	int j;

	i = 0;
	flags = (int *)ft_memalloc(sizeof(int) * 4);
	while (args[i] && args[i][0] == '-')
	{
		if (!is_invalid_flags(args[i]))
		{
			j = 1;
			flags[NB_FLAGS]++;
			while (args[i][j])
			{
				flags[N] = args[i][j] == 'n' ? 1 : flags[N];
				flags[EE] = args[i][j] == 'e' ? 1 : flags[EE];
				flags[E] = args[i][j] == 'E' ? 1 : flags[E];
				j++;
			}
		}
		else
			break ;
		i++;
	}
	return (flags);
}

int			bi_echo(t_shell *sh, char **args)
{
	char	*str;
	int		*flags;

	flags = get_flags(args);
	str = stringtab_to_string(args, flags[NB_FLAGS]);
	ft_putstr(str);
	free(str);
	if (!flags[N])
		ft_putchar('\n');
	free(flags);
	return (0);
	(void)sh;
}
