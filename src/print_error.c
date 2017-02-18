/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:42:41 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/01/22 18:09:38 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "colors.h"

void	print_error(char *str, char *item)
{
	ft_putstr_fd(H_RED, 2);
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	if (item)
		ft_putstr_fd(item, 2);
	ft_putendl_fd(INIT, 2);
}
