/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:37:28 by yejikim           #+#    #+#             */
/*   Updated: 2021/11/29 20:11:31 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_stradd(char *pnew, char *x)
{
	int		p_size;
	char	*temp;

	if (x == NULL)
	{
		if (pnew)
			free(pnew);
		return (-1);
	}
	p_size = ft_strlen(pnew);
	temp = pnew;
	pnew = (char *)malloc(sizeof(char) * (p_size + 2));
	if (pnew == NULL)
	{
		free(temp);
		return (-1);
	}
	ft_strlcpy(pnew, temp, p_size + 1);
	ft_strlcat(pnew, temp, p_size + 2);
	return (1);
}

int	ft_convert(char *pnew, const char *s, int *i, int *cnt)
{
	t_info	op;

	(*i)++;
	while (1)
	{
		// flag가 아닐 때까지 반복문을 돌면서 check
		// 함수로 구현해야 할 듯.
		// flag 처음에 init 해주고, 돌면서 확인
		// 이 때 *i를 자동으로 증가시켜야 함.
	}
	// width인식
	// . check
	// length 인식
	// 실제 넣으려고 하는 

}

int	ft_printf(const char *s, ...)
{
	char	*pnew;
	int		i;
	int		cnt;


	if (s == NULL)
		return (-1);
	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			if (ft_stradd(pnew, ft_substr(s, i, 1)) < 0)
				return (-1);
			cnt++;
		}
		else
		{
			if (ft_convert(pnew, s, &i, &cnt) < 0)
				return (-1);
		}
		i++;
	}
	print_result(pnew);
	return (cnt);
}