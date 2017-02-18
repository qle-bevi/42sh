/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:15:06 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/02 16:12:24 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <wchar.h>
#include <unistd.h>

static int	ft_wcutf8(wchar_t wchar, char *conv_temp)
{
	int		len;

	len = 0;
	if (wchar < 0x80)
		conv_temp[len++] = ((wchar >> 0) & 0x7F) | 0x00;
	else if (wchar < 0x0800)
	{
		conv_temp[len++] = ((wchar >> 6) & 0x1F) | 0xC0;
		conv_temp[len++] = ((wchar >> 0) & 0x3F) | 0x80;
	}
	else if (wchar < 0x010000)
	{
		conv_temp[len++] = ((wchar >> 12) & 0x0F) | 0xE0;
		conv_temp[len++] = ((wchar >> 6) & 0x3F) | 0x80;
		conv_temp[len++] = ((wchar >> 0) & 0x3F) | 0x80;
	}
	else if (wchar < 0x110000)
	{
		conv_temp[len++] = ((wchar >> 18) & 0x07) | 0xF0;
		conv_temp[len++] = ((wchar >> 12) & 0x3F) | 0x80;
		conv_temp[len++] = ((wchar >> 6) & 0x3F) | 0x80;
		conv_temp[len++] = ((wchar >> 0) & 0x3F) | 0x80;
	}
	return (len);
}

int			ft_putwchar(wchar_t c)
{
	int		len;
	char	conv_temp[4];

	len = ft_wcutf8(c, conv_temp);
	write(1, conv_temp, len);
	return (len);
}
