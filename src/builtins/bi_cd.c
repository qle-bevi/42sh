/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:42:09 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/01/30 20:09:54 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <unistd.h>
#define Q 0
#define S 1
#define L 2
#define P 3
#define NB_FLAGS 4
#define P_FLAG 5
#define CMDPATH args[flags[NB_FLAGS]]
#define TMP (tmp[0] == '~')

static void	update_env(t_shell *sh, char *oldpwd, char *input, int flagp)
{
	char	*pwd;

	pwd = NULL;
	if (flagp || !input)
	{
		pwd = (char *)malloc(sizeof(char) * 1024);
		getcwd(pwd, 1024);
	}
	else if (input)
		pwd = ft_strdup(input);
	pwd = ft_str_replace(pwd, sh->store[HOMEDIR], "~", 1);
	free(sh->store[OLDPWD]);
	sh->store[OLDPWD] = clean_path(oldpwd);
	free(sh->store[PWD]);
	sh->store[PWD] = pwd;
	h_set_or_create_elem(sh->env, "PWD", pwd);
	h_set_or_create_elem(sh->env, "OLDPWD", oldpwd);
	sh->env_update = 1;
}

static void	get_path(char **path, char *pwd, char *input)
{
	char *tmp;

	if (input && input[0] == '/')
	{
		*path = clean_path(input);
		return ;
	}
	tmp = ft_strjoin(pwd, "/");
	tmp = ft_strrejoin(tmp, tmp, input);
	*path = ft_strdup(tmp);
	free(tmp);
}

static void	exec_cd(char **path, char *oldpwd, int *flags, char *input)
{
	if (!(bi_cd_change_dir(*path, flags[P_FLAG], input)))
		update_env(get_shell(), oldpwd, *path, flags[P]);
	free(input);
	ft_memdel((void **)path);
	free(oldpwd);
}

static int	cd_minus(char **path, t_shell *sh)
{
	*path = ft_strdup(sh->store[OLDPWD]);
	return (1);
}

int			bi_cd(t_shell *sh, char **args)
{
	char	*oldpwd;
	char	*path;
	int		*flags;
	char	*tmp;

	path = NULL;
	flags = bi_cd_get_flags(args);
	tmp = CMDPATH ? ft_strdup(CMDPATH) : NULL;
	oldpwd = ft_strnew(1024);
	oldpwd = getcwd(oldpwd, 1024);
	if (!tmp)
		path = ft_strdup(sh->store[HOMEDIR]);
	else if (tmp[0] == '-' && !(args[flags[NB_FLAGS] + 1]) && !tmp[1])
		flags[P_FLAG] = cd_minus(&path, sh);
	else
	{
		tmp = TMP ? ft_str_replace(tmp, "~", sh->store[HOMEDIR], 1) : tmp;
		get_path(&path, oldpwd, tmp);
	}
	if (flags[S] || flags[P])
		bi_cd_symlink(flags, tmp[0] == '/' ? &path : &tmp, &path);
	if (path)
		exec_cd(&path, oldpwd, flags, tmp);
	free(flags);
	return (0);
}
