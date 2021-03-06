/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:20:30 by yejikim           #+#    #+#             */
/*   Updated: 2022/04/15 19:04:39 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	in_word(char *s, t_ull *i, char c)
{
	while (s[*i] && (s[*i] != c))
		(*i)++;
}

static t_ull	count_word(char *s, char c)
{
	t_ull	word_cnt;
	t_ull	i;

	word_cnt = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
		{
			in_word(s, &i, c);
			word_cnt++;
		}
		else
			i++;
	}
	return (word_cnt);
}

static void	free_mem(char **result, char *s)
{
	t_ull	i;

	free(s);
	i = 0;
	while (result[i])
		free(result[i++]);
	free(result);
}

static char	*curr_word(char **result, char *s, t_ull *i, char c)
{
	char	*pnew;
	t_ull	j;
	t_ull	k;

	j = *i;
	in_word(s, i, c);
	pnew = (char *)malloc(sizeof(char) * (*i - j + 1));
	if (pnew == 0)
	{
		free_mem(result, s);
		return (0);
	}
	k = 0;
	while (j < *i)
	{
		pnew[k++] = *(s + j);
		j++;
	}
	pnew[k] = '\0';
	return (pnew);
}

char	**ft_split(char *s, char c)
{
	char	**result;
	t_ull	i;
	t_ull	j;

	if (s == 0)
		return (0);
	result = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (result == 0)
		return (0);
	i = 0;
	j = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
		{
			result[j] = 0;
			result[j++] = curr_word(result, s, &i, c);
			if (result == 0)
				return (0);
		}
		else
			i++;
	}
	result[j] = 0;
	return (result);
}
