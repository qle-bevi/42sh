/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_set_term_mode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:43:45 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/15 20:48:25 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <termios.h>
#include <unistd.h>

static void	toggle_term(void)
{
	static int				status = -1;
	static struct termios	term;
	static struct termios	ncterm;

	if (status == -1)
	{
		tcgetattr(0, &term);
		ft_memcpy(&ncterm, &term, sizeof(struct termios));
		ncterm.c_lflag &= ~(ICANON | ECHO | ISIG);
		ncterm.c_cc[VMIN] = 1;
		ncterm.c_cc[VTIME] = 0;
		status = 0;
	}
	tcsetattr(0, 0, (status) ? &term : &ncterm);
	status = (status) ? 0 : 1;
}

void		set_term_mode(t_term_mode mode)
{
	static t_shell *sh = NULL;

	if (!sh)
		sh = get_shell();
	if (!sh->is_interactive || mode == sh->term_mode)
		return ;
	sh->term_mode = mode;
	toggle_term();
}
