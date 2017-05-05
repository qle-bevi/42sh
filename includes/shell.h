/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:35:22 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/05/05 15:26:18 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H
# define STORE_SIZE 4
# define NB_BUILTINS 17
# define DEFAULT_PATH "/bin:/usr/bin"
# define HELP_FILES "./help/"
# define TSQ	0
# define TDQ	1
# define TBS	2

/*
** ERRORS MESSAGES
*/

# define ERR_ACC_EXISTS "File does not exists: "
# define ERR_ACC_READ	"Not allowed to read: "
# define ERR_ACC_WRITE	"Not allowed to write: "
# define ERR_ACC_EXEC	"Not allowed to execute: "
# define ERR_PARSE		"Parse error near -> "
# define ERR_MALLOC		"FATAL malloc error."
# define ERR_READ		"FATAL read error."
# define ERR_FORK		"FATAL fork error."

# include <sys/stat.h>
# ifdef __linux__
#  include <sys/types.h>
#  include <sys/wait.h>
# endif

# include "get_command_line.h"
# include "libft.h"
# include "libhash.h"
# include "job.h"

typedef struct s_shell			t_shell;
typedef struct s_bi_histo		t_bi_histo;
typedef struct s_builtin		t_builtin;
typedef struct s_bi_histo_flags	t_bi_histo_flags;

typedef enum			e_storage_key
{
	HOMEDIR,
	LOGNAME,
	OLDPWD,
	PWD,
}						t_storage_key;

typedef enum			e_term_mode
{
	TM_NORMAL,
	TM_RAW
}						t_term_mode;

struct					s_bi_histo
{
	char				flag;
	char				*arg;
	int					offset;
	t_bi_histo			*next;
};

struct					s_shell
{
	pid_t		pid;
	char		*store[STORE_SIZE];
	char		*line;
	char		*histo_path;
	t_hash		*env;
	t_hash		*vars;
	t_hash		*bins;
	t_hash		*aliases;
	t_histo		*histo;
	t_job		*jobs;
	t_term_mode	term_mode;
	char		*prompt;
	int			aeof;
	int			cmd_ret;
	int			save_in;
	int			save_out;
	int			save_err;
	int			tout;
	int			env_update;
	int			is_interactive;
	int			nb_histo;
	int			sigint;
};

struct					s_bi_histo_flags
{
	char	flag;
	int		(*p)(t_bi_histo *current, t_shell *sh);
};

struct					s_builtin
{
	char	*key;
	int		(*run)(t_shell *sh, char **args);
};

/*
** CORE
*/

t_shell					*get_shell(void);
char					**get_env();
t_hash					*get_bins();
int						do_exec(char **args, char **env);
int						get_line(char *prompt, char **line);
char					*get_value(char *key);
void					sigsig(int sig);
void					exit_shell(char *msg, int code);
void					set_term_mode(t_term_mode mode);
void					restore_fds();
int						check_access(char *path, int mode);
void					print_error(char *str, char *item);
int						shell_init(t_shell *sh, char **env);
void					env_init(t_hash **hash_env, char **envp);
void					shell_update_bins(t_shell *sh);
void					env_check(t_hash *hash_env, char **store);
void					shell_start(t_shell *sh, int ac, char **av);
void					shell_source_fd(t_shell *sh, int fd);
void					shell_source_line(t_shell *sh, char **line);
void					shell_add_a_job(t_shell *sh, t_job *job);
void					shell_create_and_run_job(t_shell *sh,
	t_cmd *cmd, int background);
void					shell_remove_a_job(t_shell *sh, t_job *job);
void					shell_update_status(t_shell *sh);
void					shell_notificate(t_shell *sh);
void					*shalloc(size_t size);
void					*shrealloc(void *old, size_t size);
char					*shell_prompt(t_shell *sh);
char					*stringtab_to_string(char **strings, int begin);
void					set_current_pgid(pid_t pgid);
void					shell_exec(t_shell *sh);
void					shell_parse_vars(t_shell *sh, char **line);
void					shell_signals(void);
void					update_jobs(t_job *job, pid_t pid, int status);
char					*str_get_var_key(char *str);

/*
** BUILTINS
*/

t_builtin				*get_builtins();
int						builtin_index(char *key);
int						bi_exit(t_shell *sh, char **args);
int						bi_alias(t_shell *sh, char **args);
int						bi_print_hash(t_shell *sh, char **args);
int						bi_setenv(t_shell *sh, char **args);
int						bi_set(t_shell *sh, char **args);
int						bi_unsetenv(t_shell *sh, char **args);
int						bi_env(t_shell *sh, char **args);
int						bi_echo(t_shell *sh, char **args);
int						bi_cd(t_shell *sh, char **args);
void					bi_cd_symlink(int *flags, char **path,
										char **to_clear);
int						bi_cd_change_dir(char *path, int print_path,
											char *input);
int						*bi_cd_get_flags(char **args);
int						bi_source(t_shell *sh, char **args);
int						bi_jobs(t_shell *sh, char **args);
void					bi_jobs_ret(char *id, t_job *cur);
int						bi_fg(t_shell *sh, char **args);
int						bi_bg(t_shell *sh, char **args);
int						bi_export(t_shell *sh, char **args);
int						bi_unset(t_shell *sh, char **args);

/*
** HISTORY
*/

int						histo_list_to_file_ap(char *path, t_histo *last);
int						histo_list_to_file_wo(char *path, t_histo *last);
int						bi_history_anrw(t_bi_histo **current);

int						bi_history(t_shell *sh, char **args);
int						bi_history_print_histo(t_shell *sh, t_histo *last,
												int n);
t_histo					*bi_history_get_pos(t_histo *last, int n);
t_bi_histo				*bi_history_display_invalid_flag(char arg,
															t_bi_histo *first);
int						bi_history_display_invalid_num(char *arg);
int						bi_history_display_too_many_arg(void);
int						bi_history_is_valid_flag(char flag);
t_bi_histo				*bi_history_parse_arg(char **args);
t_bi_histo				*bi_history_free_flags(t_bi_histo *first);
int						bi_history_exec(t_bi_histo *first, t_shell *sh);
void					bi_histo_del_one_entry(t_histo *entry, t_shell *sh);

int						bi_history_c(t_bi_histo *current, t_shell *sh);
int						bi_history_d(t_bi_histo *current, t_shell *sh);
int						bi_history_a(t_bi_histo *current, t_shell *sh);
int						bi_history_w(t_bi_histo *current, t_shell *sh);
int						bi_history_n(t_bi_histo *current, t_shell *sh);
int						bi_history_r(t_bi_histo *current, t_shell *sh);
int						bi_history_s(t_bi_histo *current, t_shell *sh);
int						bi_history_p(t_bi_histo *current, t_shell *sh);

/*
**	UTILS
*/
void					str_history(char **tmp, char *trig);
char					*get_histo(char *tmp, size_t *i);
void					get_dols(char **str, char *trigger, char *buf, int *i);
void					add_char(char **str, char *triggers, char *buf, int *i);
void					handle_bs(char *triggers);
void					handle_sq(char **str, char *triggers, \
			char *buf, int *i);
void					handle_dq(char **str, char *trigger, char *buf, int *i);
void					handle_c(char **str, char *triggers, char *buf, int *i);
void					extract_var(char **strp, char *buffer, int *i);
void					get_append_value(char *key, char *buffer, int *i);
int						extract_key(char *str, char **dest);
int						ft_abs(int n);
int						char_len(int n);
char					*get_cmd_histo(t_histo *last, int n, int len);
char					*histo_nvalue(t_histo *last, int n);
int						len_histo(t_histo *last);
int						char_special(char c);
char					*ft_strremplace(char *s1, size_t start, \
			size_t len, char *s2);
char					**str_doublesplit(char *str);
char					*clean_path(char *path);
int						str_is_digit(char *str);
int						str_is_alnum(char *str);
char					*strtab_to_string_delim(char **strings, int begin,
													char *delim);
void					pdebug(char *str);
int						copy_fd(int in, int out);
char					*str_expand_vars(char *str);
void					reset_signals();
void					print_hooks(char *str);

#endif
