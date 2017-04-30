/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:36:41 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/30 21:24:25 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_access(char *path, int mode)
{
	int ret;

	ret = access(path, F_OK);
	if (ret)
	{
		print_error(ERR_ACC_EXISTS, path);
		return (-1);
	}
	if (!(ret = access(path, mode)))
		return (0);
	if (mode & R_OK)
		print_error(ERR_ACC_READ, path);
	else if (mode & W_OK)
		print_error(ERR_ACC_WRITE, path);
	else
		print_error(ERR_ACC_EXEC, path);
	return (-1);
}
