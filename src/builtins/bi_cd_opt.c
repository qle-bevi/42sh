/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:42:15 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/01/30 20:10:31 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#define S 1
#define P 3

static char	*bi_cd_s_help(char *temp, char **array, char *path, int i)
{
	if (temp)
	{
		temp = ft_strrejoin(temp, temp, "/");
		temp = ft_strrejoin(temp, temp, array[i]);
	}
	else
	{
		temp = ft_strdup(path[0] == '/' ? "/" : "./");
		temp = ft_strrejoin(temp, temp, array[0]);
	}
	return (temp);
}

static int	bi_cd_s(char *path)
{
	char		**array;
	struct stat	buf;
	char		*temp;
	int			i;

	i = 0;
	temp = NULL;
	array = ft_strsplit(path, '/');
	while (array[i])
	{
		temp = bi_cd_s_help(temp, array, path, i);
		lstat(temp, &buf);
		if (S_ISLNK(buf.st_mode))
		{
			ft_memdel((void **)&temp);
			return (1);
		}
		i++;
	}
	return (0);
}

void		bi_cd_symlink(int *flags, char **path, char **to_clear)
{
	if (flags[S] && bi_cd_s(*path))
	{
		ft_putstr(*path);
		ft_putendl(" is not a directory");
		ft_memdel((void **)to_clear);
		return ;
	}
}
