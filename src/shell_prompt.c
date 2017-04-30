/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:43:37 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/30 20:56:33 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "colors.h"

char	*shell_prompt(t_shell *sh)
{
	char	*buf;
	char	*prompt;
	char	*ret;

	buf = ft_strnew(1024);
	ret = ft_itoa(sh->cmd_ret);
	if (sh->prompt)
		free(sh->prompt);
	if (!getcwd(buf, 1024))
	{
		chdir(sh->store[HOMEDIR]);
		buf = ft_strredup(buf, sh->store[HOMEDIR]);
		sh->store[OLDPWD] = ft_strredup(sh->store[OLDPWD], "~");
		sh->store[PWD] = ft_strredup(sh->store[PWD], "~");
		h_set_or_create_elem(sh->env, "PWD", "~");
		h_set_or_create_elem(sh->env, "OLDPWD", "~");
		sh->env_update = 1;
	}
	buf = ft_str_replace(buf, sh->store[HOMEDIR], "~", 1);
	prompt = ft_strdup("\e[35m");
	prompt = ft_strrejoin(prompt, prompt, sh->store[LOGNAME]);
	prompt = ft_strrejoin(prompt, prompt, "\e[00m => \e[32m");
	prompt = ft_strrejoin(prompt, prompt, buf);
	prompt = ft_strrejoin(prompt, prompt, (sh->cmd_ret) ? RED : GREEN);
	prompt = ft_strrejoin(prompt, prompt, " [");
	prompt = ft_strrejoin(prompt, prompt, ret);
	prompt = ft_strrejoin(prompt, prompt, "]");
	prompt = ft_strrejoin(prompt, prompt, "\e[32m\n\e[00m\e[36m$> \e[00m");
	free(buf);
	free(ret);
	return (sh->prompt = prompt);
}
