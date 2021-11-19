/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:20:30 by yejikim           #+#    #+#             */
/*   Updated: 2021/11/19 14:10:04 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	in_word(char const *s, int *i, char c)
{
	while (s[*i] && (s[*i] != c))
		(*i)++;
}

static int	count_word(char const *s, char c)
{
	int	word_cnt;
	int	i;

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

static void	free_mem(char **result)
{
	int	i;

	i = 0;
	while (result[i])
		free(result[i]);
	free(result);
}

static char	*curr_word(char **result, char const *s, int *i, char c)
{
	char	*pnew;
	int		j;
	int		k;

	j = *i;
	in_word(s, i, c);
	pnew = (char *)malloc(sizeof(char) * (*i - j + 1));
	if (pnew == 0)
	{
		free_mem(result);
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

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;

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
