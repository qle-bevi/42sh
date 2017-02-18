/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_history_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:56:12 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/12/08 16:51:41 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static t_bi_histo	*new_flag(char flag, char *arg, int offset)
{
	t_bi_histo	*flags;

	if (!(flags = (t_bi_histo *)ft_memalloc(sizeof(t_bi_histo))))
		return (NULL);
	flags->flag = flag;
	flags->arg = arg;
	flags->offset = offset;
	flags->next = NULL;
	return (flags);
}

static char			*histo_merge_args(char **args)
{
	char	*arg;
	int		i;

	i = 0;
	arg = NULL;
	while (args[i])
	{
		if (!arg)
			arg = ft_strdup(args[i]);
		else
		{
			arg = ft_strrejoin(arg, arg, " ");
			arg = ft_strrejoin(arg, arg, args[i]);
		}
		i++;
	}
	return (arg);
}

static int			histo_set_arg(t_bi_histo **current, char **args, int *i)
{
	int temp;

	if (bi_history_anrw(current) && args[(*i) + 1] && args[(*i) + 1][0] != '-')
	{
		(*current)->arg = args[(*i) + 1];
		(*i)++;
	}
	else if ((*current)->flag == 'd')
	{
		if (args[(*i) + 1] && str_is_digit(args[(*i) + 1]) && \
			(temp = ft_atoi(args[(*i) + 1])) && temp <= get_shell()->nb_histo)
		{
			(*current)->offset = temp;
			(*i)++;
		}
		else
		{
			bi_history_display_invalid_num("-d");
			return (-1);
		}
	}
	else if ((*current)->flag == 'p' || (*current)->flag == 's')
		(*current)->arg = args[(*i) + 1] ?
		histo_merge_args(args + (*i) + 1) : NULL;
	return (0);
}

static int			histo_set_new_flag(t_bi_histo **tmp, t_bi_histo **first,
										char flag)
{
	if (*tmp)
	{
		if ((*tmp)->flag == flag)
			return (1);
		(*tmp)->next = new_flag(flag, NULL, 0);
		(*tmp) = (*tmp)->next;
	}
	else
	{
		(*first) = new_flag(flag, NULL, 0);
		(*tmp) = (*first);
	}
	return (0);
}

t_bi_histo			*bi_history_parse_arg(char **args)
{
	t_bi_histo	*first;
	t_bi_histo	*tmp;
	int			i;
	int			j;

	i = 0;
	first = NULL;
	tmp = NULL;
	while (args[i] && args[i][0] == '-')
	{
		j = 0;
		while (args[i][++j] && args[i][0] == '-')
		{
			if (!(bi_history_is_valid_flag(args[i][j])))
				return (bi_history_display_invalid_flag(args[i][j], first));
			if ((histo_set_new_flag(&tmp, &first, args[i][j])))
				continue ;
			if ((histo_set_arg(&tmp, args, &i)) == -1)
				return (bi_history_free_flags(first));
			else if (tmp->flag == 's' || tmp->flag == 'p')
				return (first);
		}
		i++;
	}
	return (first);
}
