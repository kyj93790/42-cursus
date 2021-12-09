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

static void	fill_from_front(unsigned long long target, char *temp, t_info op, int t_len)
{
	int 				max_size;
	int					i;
	unsigned long long	digit;

	max_size = get_max(op.width, op.precision, t_len);
	if (op.precision > t_len)
		t_len = op.precision;
	digit = 1;
	i = 1;
	while (i++ < t_len)
		digit *= 16;
	i = 0;
	if (op.hash == 1)
	{
		temp[i++] = '0';
		temp[i++] = 'X';
		t_len += 2;
	}
	while (i < t_len)
	{
		temp[i++] = "0123456789ABCDEF"[target / digit];
		target %= digit;
		digit /= 16;
	}
}

static void	fill_from_rear(unsigned long long target, char *temp, t_info op, int t_len)
{
	int	i;

	i = get_max(op.width, op.precision, t_len);
	if (op.precision > t_len)
		t_len = op.precision;
	while (i-- && t_len--)
	{
		temp[i] = "0123456789ABCDEF"[target % 16];
		target /= 16;
	}
	if (op.precision < 0 && op.zero == 1)
	{
		while (i >= 0)
			temp[i--] = '0';
		i += 2;	// # flag를 처리하기 위함
	}
	if (op.hash == 1)
	{
		temp[i--] = 'X';
		temp[i] = '0';
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
	max_size = get_max(op.width, op.precision, t_len);
	temp = (char *)malloc(sizeof(char) * (max_size + 1));
	if (temp == NULL)
		return (-1);
	i = 0;
	while (i < max_size)
		temp[i++] = ' ';
	temp[i] = '\0';
	if (op.minus == 1)	// 앞에서부터 채워 넣음.
		fill_from_front(target, temp, op, t_len);
	else
		fill_from_rear(target, temp, op, t_len);
	if (ft_stradd(res, temp, max_size) < 0)
		return (-1);
	return (1);
}