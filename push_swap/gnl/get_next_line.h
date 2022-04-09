/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:49:13 by yejin             #+#    #+#             */
/*   Updated: 2022/04/10 01:42:20 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "../ft_printf/bonus/ft_printf_bonus.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_lst
{
	char			*buffer;
	int				curr;
	int				last;
	struct s_lst	*next;
}	t_lst;

char	*get_next_line(int fd);
int		ft_lstadd(t_lst **lst, int fd);
int		check_line(t_lst *lst);
char	*add_line(t_lst *lst, char *pnew, int line_i);
void	ft_strcpy(char *result, char *pnew);
void	free_mem_gnl(t_lst **lst, char **pnew);
char	*get_line(int fd, t_lst *lst);

#endif
