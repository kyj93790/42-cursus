/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:41:07 by yejin             #+#    #+#             */
/*   Updated: 2022/05/20 23:33:40 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	get_infile(char *limiter)
{
	int		fd;
	size_t	len;
	char	*temp;

	fd = open("temp_file", O_WRONLY | O_CREAT, 0644);
	if (fd < 0)
		exit_with_error(EXIT_FAILURE, "failure in generating temp file", NULL);
	len = ft_strlen(limiter);
	while (1)
	{
		ft_putstr_fd("> ", 1);
		temp = get_next_line(0);
		if (temp == 0)
			exit_with_error(EXIT_FAILURE, "failure in gnl", NULL);
		if (ft_strlen(temp) == len + 1 && strncmp(temp, limiter, len) == 0)
		{
			free(temp);
			break ;
		}
		ft_putstr_fd(temp, fd);
		free(temp);
	}
	close(fd);
}
