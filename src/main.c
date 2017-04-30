/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:42:24 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/30 18:37:27 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

rnt			main(int ac, char **av, char **env)
{
	t_shell *sh;

	shell_init((sh = get_shell()), env);
	shell_start(sh, ac, av);
	return (0);
}
