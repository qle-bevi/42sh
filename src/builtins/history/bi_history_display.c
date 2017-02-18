/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_history_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:47:15 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 19:47:35 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	display_padding(int nb)
{
	int spaces;

	spaces = 4;
	while ((nb /= 10) > 0)
		spaces--;
	while (spaces--)
		ft_putchar(' ');
}

int			bi_history_print_histo(t_shell *sh, t_histo *last, int n)
{
	t_histo	*tmp;
	int		offset;

	if (!last)
		return (0);
	if (n > sh->nb_histo || n < -1)
		bi_history_display_invalid_num(ft_itoa(n));
	if (n == 0)
		return (0);
	tmp = bi_history_get_pos(last, n >= 0 ? n : -1);
	offset = n >= 0 ? (sh->nb_histo - n + 1) : 1;
	while (tmp && offset <= sh->nb_histo)
	{
		display_padding(offset);
		ft_putnbr(offset);
		ft_putstr("  ");
		ft_putendl(tmp->value);
		tmp = tmp->next;
		offset++;
	}
	return (0);
}
