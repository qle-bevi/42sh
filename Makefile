NAME = 42sh 

SRC = 	main.c \
		get_shell.c \
		shell_init.c \
		env_init.c \
		env_check.c \
		shell_start.c \
		get_env.c \
		get_bins.c \
		get_line.c \
		exit_shell.c \
		get_value.c \
		restore_fds.c \
		check_access.c \
		print_error.c \
		shell_source_fd.c \
		shell_source_line.c \
		shell_add_a_job.c \
		shell_create_and_run_job.c \
		shell_remove_a_job.c \
		shell_update_status.c \
		shell_notificate.c \
		shell_update_bins.c \
		set_term_mode.c \
		set_current_pgid.c \
		sigsig.c \
		shell_prompt.c \
		shell_signals.c \
		do_exec.c \
		update_jobs.c \
		shalloc.c \
		builtins/get_builtins.c \
		builtins/builtin_index.c \
		builtins/bi_exit.c \
		builtins/bi_alias.c \
		builtins/bi_print_hash.c \
		builtins/bi_setenv.c \
		builtins/bi_set.c \
		builtins/bi_unsetenv.c \
		builtins/bi_env.c \
		builtins/bi_export.c \
		builtins/bi_echo.c \
		builtins/bi_cd.c \
		builtins/bi_cd_flags.c \
		builtins/bi_cd_opt.c \
		builtins/bi_source.c \
		builtins/bi_jobs.c \
		builtins/bi_jobs_ret.c \
		builtins/bi_fg.c \
		builtins/bi_bg.c \
		builtins/bi_unset.c \
		builtins/history/histo_list_to_file_ap.c \
		builtins/history/histo_list_to_file_wo.c \
		builtins/history/bi_history.c \
		builtins/history/bi_history_display.c \
		builtins/history/bi_history_errors.c \
		builtins/history/bi_history_get_position.c \
		builtins/history/bi_history_is_valid_flag.c \
		builtins/history/bi_history_free_flags.c \
		builtins/history/bi_history_parser.c \
		builtins/history/bi_history_exec.c \
		builtins/history/bi_history_c_d.c \
		builtins/history/bi_history_anrw.c \
		builtins/history/bi_history_s_p.c \
		get_command_line/get_command_line.c \
		get_command_line/cmd_line_histo_down.c \
		get_command_line/cmd_line_histo_up.c \
		get_command_line/cmd_line_action.c \
		get_command_line/cmd_line_clear.c \
		get_command_line/cmd_line_erase.c \
		get_command_line/cmd_line_interrupt.c \
		get_command_line/cmd_line_mv_down.c \
		get_command_line/cmd_line_mv_end.c \
		get_command_line/cmd_line_mv_home.c \
		get_command_line/cmd_line_mv_left.c \
		get_command_line/cmd_line_mv_right.c \
		get_command_line/cmd_line_mv_up.c \
		get_command_line/cmd_line_nword.c \
		get_command_line/cmd_line_pword.c \
		get_command_line/cmd_line_quotes.c \
		get_command_line/cmd_line_quotes_tools.c \
		get_command_line/cmd_line_render.c \
		get_command_line/cmd_line_rm_chars.c \
		get_command_line/cmd_line_set_text.c \
		get_command_line/cmd_line_to_str.c \
		get_command_line/cmd_line_write.c \
		get_command_line/unload_histo.c \
		get_command_line/load_histo.c \
		get_command_line/add_histo.c \
		get_command_line/cmd_line_extra.c \
		cmds/cmd_free.c \
		cmds/cmd_push_redir.c \
		cmds/cmd_get_by_pid.c \
		cmds/parse/cmd_build.c \
		cmds/parse/cmd_is.c \
		cmds/parse/cmd_add.c \
		cmds/parse/cmd_parse_redir.c \
		cmds/parse/cmd_extract_str.c \
		cmds/exec/cmd_exec.c \
		cmds/exec/cmd_get_redir_fd.c \
		cmds/exec/cmd_set_fds.c \
		cmds/exec/cmd_link_pipe.c \
		cmds/exec/cmd_update.c \
		cmds/exec/cmd_terminate.c \
		cmds/exec/cmd_check.c \
		cmds/exec/cmd_return.c \
		jobs/job_terminate.c \
		jobs/job_next_cmd.c \
		jobs/job_push_background.c \
		jobs/job_push_foreground.c \
		jobs/job_free.c \
		jobs/job_wait.c \
		jobs/job_notif.c \
		utils/pdebug.c \
		utils/print_hooks.c \
		utils/get_winsize.c \
		utils/read_key.c \
		utils/clean_path.c \
		utils/stringtab_to_string.c \
		utils/handle_utils.c \
		utils/str_is_digit.c \
		utils/get_next_line.c \
		utils/copy_fd.c \
    utils/str_expand_vars.c \
		utils/ft_strremplace.c \
		utils/h_utils.c \
		utils/extract_utils.c \
		utils/char_special.c \
		utils/reset_signals.c \
		utils/str_is_alnum.c

HEAD = includes/shell.h includes/cmd.h includes/get_command_line.h \
	   includes/job.h includes/colors.h includes/get_next_line.h \
	   includes/keys.h libft/includes/libft.h libhash/includes/libhash.h

CHECK_LIB = libft/libft.a libhash/libhash.a

INCLUDES = -Ilibft/includes -Ilibhash/includes -Iincludes
LIB_FLAGS = -Llibhash -Llibft -lhash -lft -lncurses
FLAGS = -Wall -Werror -Wextra

OBJ_DIR = obj
DIRS = 	$(OBJ_DIR) \
		$(OBJ_DIR)/utils \
		$(OBJ_DIR)/builtins \
		$(OBJ_DIR)/builtins/history \
		$(OBJ_DIR)/get_command_line \
		$(OBJ_DIR)/cmds \
		$(OBJ_DIR)/cmds/exec \
		$(OBJ_DIR)/cmds/parse \
		$(OBJ_DIR)/jobs

SRC_DIR = src

VPATH = $(SRC_DIR)

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: title $(NAME)

title:
	@make -C libft all
	@make -C libhash all
	@echo "Checking 42sh..."

$(NAME): $(DIRS) $(OBJS) $(CHECK_LIB)
	@clang $(FLAGS) $(OBJS) $(INCLUDES) $(LIB_FLAGS) -o $(NAME) -Ofast
	@echo "\n✅  42SH BUILT !"

$(DIRS):
	@mkdir $@

$(OBJ_DIR)/%.o: %.c $(HEAD)
	@clang $(FLAGS) $(INCLUDES) -c $< -o $@ -g3
	@echo "$(NAME) => \033[33;32m$@\033[33;0m"

clean:
	@rm -rf $(DIRS)
	@make -C libft clean
	@make -C libhash clean
	@echo "42sh cleaned"

fclean: clean
	@make -C libft fclean
	@make -C libhash fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all title re clean fclean
