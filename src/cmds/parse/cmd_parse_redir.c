/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 20:14:43 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/10 17:07:05 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "shell.h"

#define NUM_RDEF 6

static t_rdef		*get_rdefs(void)
{
	static const t_rdef	defs[NUM_RDEF] = {
		{ ">>", APPEND },
		{ "<<", HD },
		{ ">&", W_LINK },
		{ "<&", R_LINK },
		{ ">", WRITE },
		{ "<", READ }
	};

	return ((t_rdef *)defs);
}

static int			parse_from(char **strp)
{
	int	from;

	if (**strp == '>')
		return (1);
	if (**strp == '<')
		return (0);
	if (ft_isdigit(**strp))
	{
		from = ft_atoi(*strp);
		while (ft_isdigit(**strp))
			++*strp;
		return (from);
	}
	return (-1);
}

static t_rtype		parse_rtype(char **strp)
{
	int		i;
	int		len;
	t_rdef	*defs;

	defs = get_rdefs();
	while (cmd_is_skip_char(**strp))
		++*strp;
	i = -1;
	while (++i < NUM_RDEF)
	{
		len = (int)ft_strlen(defs[i].def);
		if (!ft_strncmp(*strp, defs[i].def, len))
		{
			*strp += len;
			return (defs[i].rtype);
		}
	}
	return (NONE);
}

static int			parse_to(char **strp)
{
	int	to;

	while (cmd_is_skip_char(**strp))
		++*strp;
	if (**strp == '-')
	{
		++*strp;
		return (-3);
	}
	if (!ft_isdigit(**strp))
		return (-1);
	to = ft_atoi(*strp);
	while (ft_isdigit(**strp))
		++*strp;
	return (to);
}

int					cmd_parse_redir(t_redir *redir, char **strp)
{
	if ((redir->from = parse_from(strp)) == -1)
		return (0);
	if ((redir->rtype = parse_rtype(strp)) == NONE)
		return (0);
	if (redir->rtype == R_LINK || redir->rtype == W_LINK)
	{
		if ((redir->to = parse_to(strp)) == -1)
			return (0);
	}
	else
	{
		while (cmd_is_skip_char(**strp))
			++*strp;
		if (!(redir->path = cmd_extract_str(strp)))
			exit_shell(ERR_MALLOC, 1);
		if (!*redir->path)
		{
			--*strp;
			return (0);
		}
	}
	return (1);
}
