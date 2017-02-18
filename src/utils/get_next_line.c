/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 13:15:55 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 17:57:45 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft.h"

static t_fdslot		*new_slot_for_fd(int const fd)
{
	t_fdslot	*slot;

	if (!(slot = (t_fdslot *)malloc(sizeof(t_fdslot))))
		return (NULL);
	if (!(slot->buffer = ft_strnew(BUFF_SIZE)))
	{
		free(slot);
		return (NULL);
	}
	slot->fd = fd;
	slot->head = slot->buffer;
	slot->next = NULL;
	return (slot);
}

static t_fdslot		*get_slot_for_fd(int const fd)
{
	static t_fdslot *first;
	t_fdslot		*current;

	if (!first)
		return ((first = new_slot_for_fd(fd)));
	current = first;
	while (current->next && fd != current->fd)
		current = current->next;
	if (fd == current->fd)
		return (current);
	return ((current->next = new_slot_for_fd(fd)));
}

static int			reset_slot(t_fdslot *slot)
{
	ft_strclr(slot->buffer);
	slot->head = slot->buffer;
	return (1);
}

static int			append_chunk(t_fdslot *slot, char **line)
{
	int		n;
	char	*occur;
	char	*temp;
	char	*tmp;

	if (!*(slot->head))
		return (reset_slot(slot));
	temp = *line;
	if (!(occur = ft_strchr(slot->head, '\n')))
	{
		if (!(*line = ft_strjoin(*line, slot->head)))
			return (-1);
		free(temp);
		return (reset_slot(slot));
	}
	if ((n = occur - slot->head))
	{
		tmp = ft_strsub(slot->head, 0, n);
		if (!tmp || !(*line = ft_strjoin(*line, tmp)))
			return (-1);
		free(tmp);
		free(temp);
	}
	slot->head = occur + 1;
	return (0);
}

int					get_next_line(int const fd, char **line)
{
	t_fdslot	*slot;
	int			append_res;
	int			read_res;

	if (fd < 0 || fd == 1 || fd == 2
		|| BUFF_SIZE < 1 || !line || !(slot = get_slot_for_fd(fd)))
		return (-1);
	if (!(*line = ft_strnew(0)))
		return (-1);
	while ((append_res = append_chunk(slot, line)))
	{
		if (append_res == -1)
			return (-1);
		if ((read_res = read(fd, slot->buffer, BUFF_SIZE)))
		{
			if (read_res == -1)
				return (-1);
		}
		else
			return ((**line) ? 1 : 0);
	}
	return (1);
}
