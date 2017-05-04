/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atheveno <atheveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 20:23:44 by atheveno          #+#    #+#             */
/*   Updated: 2017/05/04 20:23:57 by atheveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	add_char(char **str, char *triggers, char *buf, int *i)
{
	if (!triggers[TBS] && char_special(**str))
		handle_c(str, triggers, buf, i);
	if (buf[*i] == ' ')
		while (**str == ' ')
			++*str;
	buf[*i] = **str;
	++*i;
	if (**str)
		++*str;
	if (char_special(**str))
		handle_c(str, triggers, buf, i);
	else
		triggers[TBS] = 0;
}

void	handle_bs(char *triggers)
{
	triggers[TBS] = !triggers[TBS];
}

void	handle_sq(char **str, char *triggers, char *buf, int *i)
{
	if (!triggers[TBS] && !triggers[TSQ])
	{
		triggers[TSQ] = 1;
		while (**str)
		{
			buf[*i] = **str;
			++*i;
			++*str;
			if (**str == '\'')
			{
				triggers[TSQ] = !triggers[TSQ];
				break ;
			}
		}
	}
}

void	handle_dq(char **str, char *trigger, char *buf, int *i)
{
	if (!trigger[TBS] && !trigger[TDQ])
	{
		trigger[TDQ] = 1;
		while (**str)
		{
			if (**str == '\\')
				handle_bs(trigger);
			if (!trigger[TBS] && trigger[TDQ] && **str == '\"' \
					&& !(trigger[TDQ] = 0))
				break ;
			if (!trigger[TBS] && **str == '$')
				get_dols(str, trigger, buf, i);
			if (trigger[TBS] || !char_special(**str))
			{
				if (trigger[TBS] && !(trigger[TBS] = 0))
					++*str;
				buf[*i] = **str;
				++*str;
				++*i;
			}
		}
	}
	if (!trigger[TBS] && trigger[TDQ])
		trigger[TDQ] = 0;
	*str += (*str) ? 1 : 0;
}

void	handle_c(char **str, char *triggers, char *buf, int *i)
{
	if (**str == '\\')
		handle_bs(triggers);
	else if (**str == '\'')
		handle_sq(str, triggers, buf, i);
	else if (**str == '\"')
		handle_dq(str, triggers, buf, i);
	else if (**str == '$' && !triggers[TBS])
		extract_var(str, buf, i);
	add_char(str, triggers, buf, i);
}
