/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:43:23 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/05/01 18:51:58 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pwd.h>
#include <unistd.h>
#include <unistd.h>
#include <sys/types.h>
#include "shell.h"

static void	store_init(char *store[STORE_SIZE])
{
	char			buffer[4096];
	struct passwd	*pw;

	if (!(pw = getpwuid(getuid())))
		exit_shell("gepwuid error.", 1);
	if (!(store[HOMEDIR] = ft_strdup(pw->pw_dir)))
		exit_shell(ERR_MALLOC, 1);
	if (!(store[LOGNAME] = ft_strdup(pw->pw_name)))
		exit_shell(ERR_MALLOC, 1);
	ft_bzero(buffer, 4096);
	if (!getcwd(buffer, 4096))
		exit_shell("getcwd error.", 1);
	if (!(store[PWD] = ft_str_replace(buffer, store[HOMEDIR], "~", 0)))
		exit_shell(ERR_MALLOC, 1);
	if (!(store[OLDPWD] = ft_strdup(buffer)))
		exit_shell(ERR_MALLOC, 1);
}

static void	init_histo(t_shell *sh)
{
	char	*tmp;

	tmp = shalloc(sizeof(char) * 1024);
	tmp = getcwd(tmp, 1024);
	sh->histo_path = ft_strjoin(tmp, "/.histo");
	load_histo(&sh->histo, sh->histo_path, 0);
	free(tmp);
}

static void	shell_lvl(t_hash *env, char *str_lvl)
{
	char *lvl;

	if (!str_lvl)
		return (void)h_set_or_create_elem(env, "SHLVL", "1");
	if (!(lvl = ft_itoa(ft_atoi(str_lvl) + 1)))
		exit_shell(ERR_MALLOC, 1);
	h_set_or_create_elem(env, "SHLVL", lvl);
	free(str_lvl);
	free(lvl);
}

int			shell_init(t_shell *sh, char **env)
{
	char	*tmp;

	ft_bzero(sh, sizeof(sh));
	env_init(&sh->env, env);
	store_init(sh->store);
	env_check(sh->env, sh->store);
	init_histo(sh);
	if (!(sh->vars = create_hash("local variables", 300)))
		exit_shell("vars hash creation error.", 1);
	if (!(sh->bins = create_hash("binaries", 9000)))
		exit_shell("bins hash creation error.", 1);
	if (!(sh->aliases = create_hash("aliases", 300)))
		exit_shell("aliases hash creation error.", 1);
	shell_update_bins(sh);
	shell_lvl(sh->env, get_value("SHLVL"));
	sh->pid = getpid();
	sh->save_in = dup(0);
	sh->save_out = dup(1);
	sh->save_err = dup(2);
	tmp = ttyname(0);
	sh->tout = open(tmp, O_WRONLY);
	free(tmp);
	sh->line = NULL;
	restore_fds();
	return (0);
}
