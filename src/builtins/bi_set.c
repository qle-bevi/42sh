/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:36:34 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/05/04 19:06:15 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	is_valid_name(char *arg)
{
	if (ft_isdigit(*arg))
	{
		print_error("set: variable name must begin with a letter", NULL);
		return (0);
	}
	while (*arg)
	{
		if (*arg >= 65 && *arg <= 90)
		{
			print_error("set: variable name must be lowercase", NULL);
			return (0);
		}
		++arg;
	}
	return (1);
}

static int	are_args_valid(char **args)
{
	int size;

	size = ft_tablen(args);
	if (size < 3)
	{
		if (ft_isdigit(args[0][0]))
		{
			print_error("set: variable name must begin with a letter", NULL);
			return (0);
		}
		return (is_valid_name(*args));
	}
	else
	{
		print_error("set: usage: [name value]", NULL);
		return (0);
	}
}

static int	print_vars(t_hash *hash)
{
	int		found;
	int		i;
	t_elem	**elems;

	i = 0;
	found = 0;
	elems = hash->hash_tab;
	while (found < hash->nb_elem)
	{
		if (elems[i])
		{
			ft_putstr(elems[i]->key);
			ft_putchar('=');
			ft_putendl(elems[i]->value);
			++found;
		}
		++i;
	}
	return (0);
}

int			bi_set(t_shell *sh, char **args)
{
	if (!args || !*args)
		return (print_vars(sh->vars));
	if (!are_args_valid(args))
		return (1);
	h_set_or_create_elem(sh->vars, args[0], args[1]);
	return (0);
}
