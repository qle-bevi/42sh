/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_expand_vars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <jbouloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 22:04:28 by jbouloux          #+#    #+#             */
/*   Updated: 2017/05/06 15:47:24 by bdesbos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	get_dols(char **str, char *trigger, char *buf, int *i)
{
	if (!trigger[TBS])
		extract_var(str, buf, i);
}

char	*get_histo(char *tmp, size_t *i)
{
	t_histo *h;
	char	*tmp2;
	char	*h_cmd;
	int		n_cmd;

	tmp2 = NULL;
	h = get_shell()->histo;
	if (tmp[*i + 1] && tmp[*i + 1] == '!' && (n_cmd = 1))
		h_cmd = get_cmd_histo(h, len_histo(h) - 1, len_histo(h));
	else
	{
		n_cmd = ft_atoi(&tmp[*i + 1]);
		h_cmd = get_cmd_histo(h, n_cmd, len_histo(h));
	}
	tmp2 = ft_strremplace(tmp, *i, char_len(n_cmd) + 1, h_cmd);
	ft_memdel((void **)&tmp);
	*i += ft_strlen(h_cmd) - char_len(n_cmd);
	return (tmp2);
}

void	str_history(char **tmp, char *trig)
{
	size_t	i;
	size_t	len;

	i = -1;
	len = ft_strlen(*tmp);
	while (++i < len)
	{
		if ((*tmp)[i] == '\'' && !trig[TBS])
			trig[TSQ] = !trig[TSQ];
		if ((*tmp)[i] == '\\' && !trig[TBS])
			trig[TBS] = !trig[TBS];
		if (!trig[TSQ] && !trig[TBS] && (*tmp)[i] == '!')
			*tmp = get_histo(*tmp, &i);
		if (!*tmp)
			return ;
		len = ft_strlen(*tmp);
	}
	ft_bzero(trig, 3);
}

char	*str_expand_vars(char *str)
{
	static char	buffer[10000] = { 0 };
	static char	triggers[3] = { 0 };
	int			i;
	char		*tmp;
	char		*tmp2;

	ft_bzero(buffer, 10000);
	ft_bzero(triggers, 3);
	i = 0;
	tmp = ft_strdup(str);
	str_history(&tmp, triggers);
	if (!tmp)
		print_error("event not found", NULL);
	tmp2 = tmp;
	while (tmp && *tmp)
		handle_c(&tmp, (char *)triggers, buffer, &i);
	if (tmp2)
		ft_memdel((void **)&tmp2);
	return (ft_strdup(buffer));
}
