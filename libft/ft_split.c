/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:20:30 by yejikim           #+#    #+#             */
/*   Updated: 2021/11/16 21:56:40 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int static	count_word(char const *s, char c)
{
	int	word_cnt;
	int	i;

	word_cnt = 1;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == c)
			word_cnt++;
		i++;
	}
	return (word_cnt);
}

void static	free_mem(char **result)
{
	int	i;

	i = 0;
	while (result[i])
		free(result[i]);
	free(result);
}

char static	*curr_word(char **result, char const *s, int *i, char c)
{
	char	*pnew;
	int		j;
	int		k;

	j = *i;
	while (*(s + *i) != 0 && *(s + *i) != c)
		(*i)++;
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
	int		word_cnt;
	int		i;
	int		j;

	word_cnt = count_word(s, c);
	result = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (result == 0)
		return (0);
	i = 0;
	j = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
		{
			result[j] = curr_word(result, s, &i, c);
			result[j + 1] = 0;
			if (result[j++] == 0)
				return (0);
		}
		else
			i++;
	}
	result[j] = 0;
	return (result);
}
