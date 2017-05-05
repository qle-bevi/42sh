/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:34:54 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/05/05 15:24:10 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_builtin	*get_builtins(void)
{
	static const t_builtin builtins[NB_BUILTINS] = {
		{"exit", bi_exit},
		{"alias", bi_alias},
		{"print", bi_print_hash},
		{"env", bi_env},
		{"setenv", bi_setenv},
		{"unsetenv", bi_unsetenv},
		{"exit", bi_exit},
		{"setenv", bi_setenv},
		{"set", bi_set},
		{"cd", bi_cd},
		{"echo", bi_echo},
		{"history", bi_history},
		{"export", bi_export},
		{"unset", bi_unset},
		{"jobs", bi_jobs},
		{"fg", bi_fg},
		{"bg", bi_bg}
	};

	return ((t_builtin *)builtins);
}
