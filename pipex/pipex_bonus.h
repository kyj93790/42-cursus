/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:41:34 by yejin             #+#    #+#             */
/*   Updated: 2022/05/15 23:41:35 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include "libft/libft.h"
# include "get_next_line_bonus.h"

# define EACCESS 2
# define EXIT_FOPEN 1
# define EXIT_CNF 127
# define P_READ 0
# define P_WRITE 1

typedef struct	s_arg
{
	char	*infile;
	int		cmd_cnt;
	int		here_doc;
	char	***cmd;
	char	*outfile;
	char	**envp;
	char	**path;
}	t_arg;

/* pipex_bonus.c */
void	exit_with_error(int exit_num, char *message, char *filename);

/* initialize_bonus.c */
void	init_args(t_arg *arg, int argc, char *argv[], char *envp[]);
int		**init_pipe(int argc);
char	**init_path(char *envp[]);

/* execute_cmds_bonus.c */
void	execute_pipex(t_arg arg, int **p, int i);

/* calc_status_bonus.c */
int		wifexited(int status);
int 	wexitstatus(int status);

/* redirect_bonus.c */
void	redirect_from_infile(t_arg arg);
void	redirect_to_outfile(t_arg arg);

/* heredoc_bonus.c */
void	get_infile(char *limiter);

#endif
