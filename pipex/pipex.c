/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:41:37 by yejin             #+#    #+#             */
/*   Updated: 2022/05/15 23:41:38 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_with_error(int exit_num, char *message, char *filename)
{
	ft_putstr_fd("zsh: ", 2);
	if (message)
		ft_putstr_fd(message, 2);
	if (filename)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(filename, 2);
	}
	ft_putstr_fd("\n", 2);
	exit(exit_num);
}

int	main(int argc, char *argv[], char *envp[])
{
	int			**p;
	t_arg		arg;
	extern int	errno;

	errno = 0;
	init_args(&arg, argc, argv, envp);
	p = init_pipe(argc);
	execute_pipex(arg, p, arg.cmd_cnt);
	return (0);
}
