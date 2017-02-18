/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_history_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:47:39 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 19:50:09 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_bi_histo	*bi_history_display_invalid_flag(char arg, t_bi_histo *first)
{
	ft_putstr_fd("42sh : history: ", 2);
	ft_putchar_fd(arg, 2);
	ft_putendl_fd(": invalid option", 2);
	ft_putendl_fd("history: usage: history [-c] [-d offset] [n]", 2);
	return (bi_history_free_flags(first));
}

int			bi_history_display_invalid_num(char *arg)
{
	ft_putstr_fd("42sh : history: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putendl_fd(": numeric argument required or argument out of range", 2);
	return (1);
}

int			bi_history_display_too_many_arg(void)
{
	ft_putstr_fd("42sh : history: too many arguments", 2);
	return (1);
}
