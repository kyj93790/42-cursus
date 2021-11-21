/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:49:13 by yejin             #+#    #+#             */
/*   Updated: 2021/11/22 00:20:41 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>

typedef struct s_list
{
	char			*buffer;
	int				curr;
	int				last;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		ft_lstadd(t_list **lst);
int		check_line(t_list *lst);
char	*add_line(t_list *lst, char *pnew, int line_i);
void	ft_strcpy(char *result, char *pnew);
int		ft_strlen(char *s);
void	free_mem(t_list *lst);

#endif
