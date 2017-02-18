/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:43:37 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/01/30 00:20:48 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*shell_prompt(t_shell *sh)
{
	char	*buf;
	char	*prompt;

	buf = ft_strnew(1024);
	if (sh->prompt)
		free(sh->prompt);
	buf = getcwd(buf, 1024);
	buf = ft_str_replace(buf, sh->store[HOMEDIR], "~", 1);
	prompt = ft_strdup("\e[35m");
	prompt = ft_strrejoin(prompt, prompt, sh->store[LOGNAME]);
	prompt = ft_strrejoin(prompt, prompt, "\e[00m => \e[32m");
	prompt = ft_strrejoin(prompt, prompt, buf);
	prompt = ft_strrejoin(prompt, prompt, "\e[32m\n\e[00m\e[36m$> \e[00m");
	free(buf);
	return (sh->prompt = prompt);
}
