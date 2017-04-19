/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:42:24 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/12 02:10:08 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*static void	shell_source_init(t_shell *sh)
{
	static char	*args[2] = {"./.init", NULL};

	if (!access(args[0], F_OK))
		bi_source(sh, args);
}*/

int			main(int ac, char **av, char **env)
{
	t_shell *sh;

	shell_init((sh = get_shell()), env);
	//shell_source_init(sh);
	shell_start(sh, ac, av);
	return (0);
}
