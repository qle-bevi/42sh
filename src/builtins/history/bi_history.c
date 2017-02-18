/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:08:49 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 20:08:57 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	bi_history(t_shell *sh, char **args)
{
	t_bi_histo	*flags;

	flags = NULL;
	if (!args[0])
		return (bi_history_print_histo(sh, sh->histo, -1));
	else if (str_is_digit(args[0]))
		return (bi_history_print_histo(sh, sh->histo, ft_atoi(args[0])));
	else if (args[0][0] != '-' || !args[0][1])
		return (bi_history_display_invalid_num(args[0]));
	else if (!(flags = bi_history_parse_arg(args)))
		return (1);
	return (bi_history_exec(flags, sh));
}
