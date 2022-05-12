/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:49:13 by yejin             #+#    #+#             */
/*   Updated: 2022/05/12 14:50:32 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	char			*buffer;
	int				curr;
	int				last;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		ft_lstadd(t_list **lst, int fd);
int		check_line(t_list *lst);
char	*add_line(t_list *lst, char *pnew, int line_i);
void	ft_strcpy(char *result, char *pnew);
int		ft_strlen(char *s);
void	free_mem(t_list **lst, char **pnew);
char	*get_line(int fd, t_list *lst);

#endif
