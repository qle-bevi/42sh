/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_history_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:50:30 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 19:54:28 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	bi_histo_exec_flag(t_bi_histo *current, t_shell *sh)
{
	int						i;
	static t_bi_histo_flags	flags[8] = {
	{'c', bi_history_c},
	{'d', bi_history_d},
	{'a', bi_history_a},
	{'w', bi_history_w},
	{'n', bi_history_n},
	{'r', bi_history_r},
	{'s', bi_history_s},
	{'p', bi_history_p}
	};

	i = 0;
	while (i < 8)
	{
		if (current->flag == flags[i].flag)
			return (flags[i].p(current, sh));
		i++;
	}
	return (1);
}

int			bi_history_exec(t_bi_histo *first, t_shell *sh)
{
	t_bi_histo	*tmp;
	int			ret;

	tmp = first;
	while (tmp)
	{
		ret = bi_histo_exec_flag(tmp, sh);
		tmp = tmp->next;
	}
	first = bi_history_free_flags(first);
	return (ret);
}
