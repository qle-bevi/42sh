/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:40:00 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/11/14 17:40:04 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	exit_shell(char *msg, int code)
{
	t_shell *sh;

	sh = get_shell();
	if (sh->prompt)
		free(sh->prompt);
	if (sh->env)
		h_free(&sh->env, true);
	if (sh->vars)
		h_free(&sh->vars, true);
	if (sh->bins)
		h_free(&sh->bins, true);
	set_term_mode(TM_NORMAL);
	histo_list_to_file_wo(sh->histo_path, sh->histo);
	free(sh->histo_path);
	if (sh->histo)
		unload_histo(&sh->histo);
	if (msg)
		print_error(msg, NULL);
	exit(code);
}
