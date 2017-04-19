#ifndef JOB_H
# define JOB_H
# include "cmd.h"
# include <unistd.h>

typedef struct s_job t_job;

struct s_job {
	int		id;
	char	*title;
	t_cmd	*cmds;
	t_cmd	*current_cmd;
	int		stopped;
	int		started;
	int		done;
	int		ret;
	t_job	*next;
};

void	job_push_foreground(t_job *job);
void	job_push_background(t_job *job);
void	job_update(t_job *job, pid_t pid, int status);
void	job_format(char *str);
void	job_print(t_job *job);
void	job_notify(t_job *job, char *status, int endl);
void	job_terminate(t_job *job, int ret);
void	job_next_cmd(t_job *job);
t_job	*job_get_by_pid(t_job *jobs, pid_t pid);
void	job_wait(t_job *job);
void	job_free(t_job *job);
#endif