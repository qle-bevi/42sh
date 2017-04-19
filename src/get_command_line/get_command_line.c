/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 01:13:59 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/12 06:00:16 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_command_line.h"
#include "shell.h"

static t_cmd_line	*get_cmd_line(void)
{
	static t_cmd_line	cl;

	return (&cl);
}

static void			update_prompt(t_cmd_line *cl)
{
	int i;

	i = 0;
	cl->pcol = 1;
	cl->plines = 0;
	while (cl->prompt[i])
	{
		if (cl->prompt[i] == '\n' || (cl->pcol > cl->cols))
		{
			++cl->plines;
			cl->pcol = 1;
		}
		else if (cl->prompt[i] == '\033')
			while (cl->prompt[i] != 'm')
				++i;
		else
			++cl->pcol;
		++i;
	}
}

static void			update(int sig)
{
	t_cmd_line *cl;

	cl = get_cmd_line();
	cl->cols = get_winsize()->ws_col;
	update_prompt(cl);
	cmd_line_clear(cl);
	cmd_line_render(cl);
	(void)sig;
}

static int			cmd_line_init(t_cmd_line *cl, char *prompt, t_histo *histo)
{
	ft_bzero(cl, sizeof(t_cmd_line));
	if (!(cl->chars = ft_memalloc(sizeof(t_cl_char))))
		return (0);
	cl->chars->c = '\0';
	cl->histo_list = histo;
	cl->cursor = cl->chars;
	cl->prompt = prompt;
	cl->cols = get_winsize()->ws_col;
	update_prompt(cl);
	signal(SIGWINCH, update);
	return (1);
}

int					get_command_line(char *prompt, char **str, t_histo *histo)
{
	t_cmd_line	*cl;
	int			key;

	cl = get_cmd_line();
	if (!(cmd_line_init(cl, prompt, histo)))
		return (-1);
	cmd_line_render(cl);
	while ((key = read_key()))
	{
		if (key == CTRL_C)
			return (cmd_line_ctrl_c(cl, str));
		if (key == -1)
			return (-1);
		cmd_line_action(cl, key);
		if (cl->eof)
		{
			ft_putstr("%\n");
			cmd_line_free(cl);
			break ;
		}
		if (key == ENTER_KEY)
			return (cmd_line_validate(cl, str));
	}
	return (0);
}
