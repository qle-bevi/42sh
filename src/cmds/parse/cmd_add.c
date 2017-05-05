/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 18:10:51 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/05/05 17:38:46 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "shell.h"

static int	check_alias(t_cmd *cmd, char *extracted)
{
	static t_shell	*sh = NULL;
	char			*temp;
	char			*alias;
	char			*head;

	if (!sh)
		sh = get_shell();
	if (!(alias = h_get_value_by_key(sh->aliases, extracted)))
		return (0);
	temp = alias;
	if (!(alias = str_expand_vars(alias)))
		exit_shell(ERR_MALLOC, 1);
	head = alias;
	while (*head)
	{
		while (cmd_is_skip_char(*head))
			++head;
		if (*head)
			cmd_add_arg(cmd, &head, 0);
	}
	free(alias);
	free(temp);
	return (1);
}

int			cmd_add_arg(t_cmd *cmd, char **strp, int alias_check)
{
	char	**args;
	char	*extracted;
	int		ac;

	if (!(extracted = cmd_extract_str(strp)))
		exit_shell(ERR_MALLOC, 1);
	if (!cmd->args && alias_check && check_alias(cmd, extracted))
	{
		free(extracted);
		return (1);
	}
	ac = ft_tablen(cmd->args);
	args = ft_memalloc(sizeof(char *) * (ac + 2));
	ft_memcpy(args, cmd->args, sizeof(char *) * ac);
	args[ac] = extracted;
	args[ac + 1] = NULL;
	if (cmd->args)
		free(cmd->args);
	cmd->args = args;
	return (1);
}

int			cmd_add_redir(t_cmd *cmd, char **strp)
{
	t_redir *redir;

	redir = (t_redir *)shalloc(sizeof(t_redir));
	redir->from = -1;
	redir->to = -2;
	if (!cmd_parse_redir(redir, strp))
	{
		ft_memdel((void **)&redir);
		return (0);
	}
	cmd_push_redir_front(&cmd->redirs, redir);
	return (1);
}
