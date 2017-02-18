/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_history_is_valid_flag.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:55:44 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 19:56:05 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	bi_history_is_valid_flag(char flag)
{
	if (flag == 'c' || flag == 'd' || flag == 'a' || flag == 'n' || flag == 'r'\
	|| flag == 'w' || flag == 'p' || flag == 's')
		return (1);
	else
		return (0);
}
