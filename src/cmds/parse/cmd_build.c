/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 12:46:59 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/05/04 16:54:01 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "shell.h"

static t_cmd	*cmd_build_parse_error(t_cmd **cmdp, char *str)
{
	print_error(ERR_PARSE, str);
	return (cmd_free(cmdp));
}

static int		cmd_build_add_operator(t_cmd *cmd, char **strp)
{
	cmd->ctype = !ft_strncmp(*strp, "&&", 2) ? AND : OR;
	*strp += 2;
	return ((cmd->then = cmd_build(strp, 1)) ? 1 : 0);
}

static int		cmd_build_add_children(t_cmd *cmd, char **strp)
{
	++*strp;
	return ((cmd->children = cmd_build(strp, 0)) ? 1 : 0);
}

t_cmd			*cmd_build(char **strp, int with_then)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)shalloc(sizeof(t_cmd));
	while (**strp && **strp != ';' && **strp != '&')
	{
		while (cmd_is_skip_char(**strp))
			++*strp;
		if (**strp < 0 || **strp > 127)
			return (cmd_build_parse_error(&cmd, *strp));
		if (!with_then && (cmd_is_operator(*strp) ||
					**strp == ';' || **strp == '&'))
		{
			break ;
		}
		if ((!cmd_is_arg(*strp) && !cmd->args)
		|| (cmd_is_operator(*strp) && !cmd_build_add_operator(cmd, strp))
		|| (**strp == '|' && ft_strncmp(*strp, "||", 2)
		&& !cmd_build_add_children(cmd, strp))
		|| (cmd_is_redir(*strp) && !cmd_add_redir(cmd, strp))
		|| (cmd_is_arg(*strp) && !cmd_add_arg(cmd, strp, 1)))
			return (cmd_build_parse_error(&cmd, *strp));
	}
	return ((!cmd->args || !*cmd->args) ? cmd_build_parse_error(&cmd, *strp)
	: cmd);
}
