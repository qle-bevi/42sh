/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 01:16:06 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/12/13 19:39:06 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <termios.h>
#include <unistd.h>
#include "libft.h"

static int	get_keyval(char *buff)
{
	int val;

	val = 0;
	while (*buff)
		val += *(buff++);
	return (val);
}

int			read_key(void)
{
	static char	buff[10];
	int			ret;

	ft_bzero(buff, sizeof(char) * 10);
	ret = read(0, buff, 1);
	if (ret != -1 && buff[0] == '\e')
		ret = read(0, buff + 1, 8);
	return ((ret == -1) ? -1 : get_keyval(buff));
}
