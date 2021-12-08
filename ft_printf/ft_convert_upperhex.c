#include "ft_printf.h"

static int	ft_digit(unsigned long long target)
{
	unsigned long long	digit;
	int 				cnt;

	digit = 1;
	cnt = 1;

	while (target / 16 / digit > 0)
	{
		digit *= 16;
		cnt++;
	}
	return (cnt);
}

static void	fill_converted_upperhex(unsigned long long target, char *temp, t_info op, int t_len)
{
	int 				max_size;
	int					i;
	int					j;
	unsigned long long	digit;

	max_size = get_max(op.width, 0, t_len);
	if (op.minus == 1)
		i = 0;
	else
		i = max_size - t_len;
	digit = 1;
	while (target / 16 / digit > 0)
		digit *= 16;
	j = 0;
	while (j < t_len)
	{
		temp[i + j] = "0123456789ABCDEF"[target / digit];
		target %= digit;
		digit /= 16;
		j++;
	}
}

int	convert_upperhex(t_result *res, t_info op, va_list ap)
{
	char					*temp;
	unsigned long long		target;
	int						max_size;
	int						t_len;
	int						i;

	target = va_arg(ap, unsigned int);
	t_len = ft_digit(target);
	max_size = get_max(op.width, 0, t_len);
	temp = (char *)malloc(sizeof(char) * (max_size + 1));
	if (temp == NULL)
		return (-1);
	i = 0;
	while (i < max_size)
		temp[i++] = ' ';
	temp[i] = '\0';
	fill_converted_upperhex(target, temp, op, t_len);
	if (ft_stradd(res, temp, max_size) < 0)
		return (-1);
	return (1);
}