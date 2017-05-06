/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 01:32:00 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/05/06 17:37:38 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_command_line.h"

static void			cmd_line_end(t_cmd_line *cl)
{
	cmd_line_mv_end(cl);
	ft_putchar('\n');
}

static void			clear_term(t_cmd_line *cl)
{
	ft_putstr(tgetstr("cl", NULL));
	cmd_line_render(cl);
}

static t_cl_action	*get_actions(void)
{
	static t_cl_action actions[GCL_NB_ACTIONS] = {
		{LEFT_KEY, cmd_line_mv_left}, {RIGHT_KEY, cmd_line_mv_right},
		{UP_KEY, cmd_line_histo_up}, {DOWN_KEY, cmd_line_histo_down},
		{CTRL_UP_KEY, cmd_line_mv_up}, {CTRL_DOWN_KEY, cmd_line_mv_down},
		{HOME_KEY, cmd_line_mv_home}, {END_KEY, cmd_line_mv_end},
		{CTRL_LEFT_KEY, cmd_line_pword}, {CTRL_RIGHT_KEY, cmd_line_nword},
		{BACKSPACE_KEY, cmd_line_erase}, {ENTER_KEY, cmd_line_end},
		{CTRL_U, cmd_line_rm_chars}, {CTRL_D, cmd_line_interrupt},
		{CTRL_L, clear_term}
	};

	return ((t_cl_action *)actions);
}

void				cmd_line_action(t_cmd_line *cl, int key)
{
	t_cl_action			*actions;
	int					i;

	i = 0;
	actions = get_actions();
	while (i < GCL_NB_ACTIONS)
	{
		if (key == actions[i].key)
		{
			actions[i].act(cl);
			break ;
		}
		++i;
	}
	if (cl->search && key != UP_KEY && key != DOWN_KEY)
		ft_memdel((void **)&cl->search);
	if (ft_isprint(key) && key != ENTER_KEY)
		cmd_line_write(cl, (char)key);
}
