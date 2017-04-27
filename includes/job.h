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
	int		notified;
	t_job	*next;
};

void	job_push_foreground(t_job *job);
void	job_push_background(t_job *job);
void	job_free(t_job *job);
void	job_next_cmd(t_job *job);
void	job_notif(t_job *job, char *status);
void	job_terminate(t_job *job, int ret);
void	job_wait(t_job *job);
#endif