/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:38:31 by aschafer          #+#    #+#             */
/*   Updated: 2017/05/03 18:50:30 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		invalid_opt(char opt)
{
	static char str[2] = {0};

	str[0] = opt;
	print_error("env: invalid option: ", str);
	return (0);
}

static int		parse_env_opts(char ***args, t_hash *env)
{
	char *current;

	while (**args && (**args)[0] == '-')
	{
		current = **args + 1;
		while (*current)
		{
			if (*current == 'i')
				h_free(&env, 0);
			else if (*current == 'u')
			{
				if (*(*args + 1) && *(*args + 1)[0] != '-')
				{
					h_delete_elem(env, *(*args + 1));
					++*args;
				}
			}
			else
				return (invalid_opt(*current));
			++current;
		}
		++*args;
	}
	return (1);
}

static void		parse_vars(char ***args, t_hash *env)
{
	char **split;

	while (**args)
	{
		if (!(split = ft_strsplit(**args, '=')))
			exit_shell(ERR_MALLOC, 1);
		if (ft_tablen(split) != 2)
		{
			ft_free_tab(&split);
			break ;
		}
		h_add_elem(env, split[0], split[1]);
		ft_free_tab(&split);
		++*args;
	}
}

static void		print_env(char **env)
{
	while (env && *env)
		ft_putendl(*(env++));
}

int				bi_env(t_shell *sh, char **args)
{
	char	**envp;
	char	**new_env;
	t_hash	*env;
	int		ret;

	ret = 0;
	if (!(envp = get_env()))
		exit_shell(ERR_MALLOC, 1);
	env_init(&env, envp);
	if (!parse_env_opts(&args, env))
		return (1);
	parse_vars(&args, env);
	if (!(new_env = hash_to_tab(env)))
		exit_shell(ERR_MALLOC, 1);
	if (*args)
		ret = do_exec(args, new_env);
	else
		print_env(new_env);
	ft_free_tab(&new_env);
	h_free(&env, 1);
	return (ret);
	(void)sh;
}
