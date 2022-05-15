/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:41:52 by yejin             #+#    #+#             */
/*   Updated: 2022/05/15 23:41:54 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_from_infile(t_arg arg)
{
	extern int	errno;
	int			fd;
	int			ret;

	fd = open(arg.infile, O_RDONLY);
	if (fd < 0)
		exit_with_error(EXIT_FOPEN, "no such file or directory", arg.infile);
	ret = dup2(fd, STDIN_FILENO);
	if (ret < 0)
		exit_with_error(EXIT_FAILURE, strerror(errno), NULL);
	close(fd);
}

void	redirect_to_outfile(t_arg arg)
{
	extern int	errno;
	int			fd;
	int			ret;

	fd = open(arg.outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
		exit_with_error(EXIT_FOPEN, "no such file or directory", arg.outfile);
	ret = dup2(fd, STDOUT_FILENO);
	if (ret < 0)
		exit_with_error(EXIT_FAILURE, strerror(errno), NULL);
	close(fd);
}
