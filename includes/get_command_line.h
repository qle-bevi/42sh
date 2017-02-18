/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 01:11:59 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/12/16 19:17:24 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_COMMAND_LINE_H
# define GET_COMMAND_LINE_H
# include <stdlib.h>
# include <ncurses.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/ioctl.h>
# include <keys.h>
# include <signal.h>
# include <wchar.h>
# define GCL_NB_ACTIONS 15
# include "libft.h"
# include "keys.h"

typedef struct s_cmd_line	t_cmd_line;
typedef struct s_cl_action	t_cl_action;
typedef struct s_cl_char	t_cl_char;

typedef struct				s_histo
{
	char						*value;
	int							session;
	struct s_histo				*prev;
	struct s_histo				*next;
}							t_histo;

struct						s_cmd_line
{
	char			*prompt;
	int				plines;
	int				cols;
	int				pcol;
	int				col;
	int				len;
	int				index;
	int				eof;
	char			*search;
	t_histo			*histo_list;
	t_histo			*histo;
	t_cl_char		*chars;
	t_cl_char		*cursor;
};

struct						s_cl_action
{
	int		key;
	void	(*act)(t_cmd_line *);
};

struct						s_cl_char
{
	char		c;
	t_cl_char	*prev;
	t_cl_char	*next;
};

int							get_command_line(char *prompt, char **dest,
												t_histo *histo);
void						cmd_line_action(t_cmd_line *cl, int key);
void						cmd_line_interrupt(t_cmd_line *cl);
void						cmd_line_mv_left(t_cmd_line *cl);
void						cmd_line_mv_right(t_cmd_line *cl);
void						cmd_line_histo_up(t_cmd_line *cl);
void						cmd_line_histo_down(t_cmd_line *cl);
void						cmd_line_mv_up(t_cmd_line *cl);
void						cmd_line_set_text(t_cmd_line *cl, char *str);
void						cmd_line_mv_down(t_cmd_line *cl);
void						cmd_line_mv_home(t_cmd_line *cl);
void						cmd_line_mv_end(t_cmd_line *cl);
void						cmd_line_nword(t_cmd_line *cl);
void						cmd_line_pword(t_cmd_line *cl);
void						cmd_line_clear(t_cmd_line *cl);
t_cl_char					*del_chars(t_cl_char *list);
void						cmd_line_rm_chars(t_cmd_line *cl);
void						cmd_line_write(t_cmd_line *cl, char c);
void						cmd_line_erase(t_cmd_line *cl);
void						cmd_line_render(t_cmd_line *cl);
void						cmd_line_free(t_cmd_line *cl);
char						*cmd_line_to_str(t_cmd_line *cl, int len);
int							cmd_line_ctrl_c(t_cmd_line *cl, char **str);
int							cmd_line_validate(t_cmd_line *cl, char **str);
int							read_key(void);
struct winsize				*get_winsize(void);
int							get_next_line(int fd, char **line);
t_histo						*add_histo(t_histo **histo, char *str, int session);
void						load_histo(t_histo **histo, char *path,
										int session);
void						unload_histo(t_histo **histo);
char						*quotes_cmd_opened(char **str);
int							**quotes_check_opened(char *str, int **array1);
void						cmd_line_free_scope_tab(int **array1);
#endif
