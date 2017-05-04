/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atheveno <atheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 20:23:09 by atheveno          #+#    #+#             */
/*   Updated: 2017/05/04 20:23:38 by atheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		len_histo(t_histo *last)
{
	t_histo	*cur;
	int		i;

	i = 0;
	cur = last;
	while (cur)
	{
		cur = cur->prev;
		i++;
		if (cur == last)
			break ;
	}
	return (i);
}

char	*histo_nvalue(t_histo *last, int n)
{
	t_histo *cur;

	cur = last;
	while (cur)
	{
		if (n == 0)
			return (cur->value);
		n--;
		cur = cur->prev;
	}
	return (NULL);
}

int		ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*get_cmd_histo(t_histo *last, int n, int len)
{
	char *ret;

	if (ft_abs(n) > len)
		return (NULL);
	if (n < 0)
		n = len + n;
	n = len - n;
	ret = histo_nvalue(last, n);
	return (ret);
}

int		char_len(int n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
