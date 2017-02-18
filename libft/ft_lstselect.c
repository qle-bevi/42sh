/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstselect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 15:49:17 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/20 15:49:43 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstselect(t_list *list, BOOL (*f)(t_list *elem))
{
	t_list *new;
	t_list *temp;
	t_list *last;

	if (!list || !f)
		return (NULL);
	new = NULL;
	last = NULL;
	while (list)
	{
		if (f(list) && (temp = ft_memalloc(sizeof(t_list))))
		{
			temp->next = NULL;
			temp->content_size = list->content_size;
			temp->content = list->content;
			last = ft_lstpush2(!last ? &new : &last, temp);
		}
		list = list->next;
	}
	return (new);
}
