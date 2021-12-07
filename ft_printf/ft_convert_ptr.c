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

static void	fill_converted_ptr(unsigned long long target, char *temp, t_info op, int t_len)
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
	temp[0] = '0';
	temp[1] = 'x';
	j = 2;
	while (j < t_len)
	{
		temp[i + j] = "0123456789abcdef"[target / digit];
		target %= digit;
		digit /= 16;
		j++;
	}
}

int	convert_ptr(t_result *res, t_info op, va_list ap)
{
	char					*temp;
	unsigned long long		target;
	int						max_size;
	int						t_len;
	int						i;

	target = va_arg(ap, unsigned long long);
	//printf("%llx\n",target);
	t_len = ft_digit(target) + 2;
	max_size = get_max(op.width, 0, t_len);
	//printf("max_size : %d\n", max_size);
	temp = (char *)malloc(sizeof(char) * (max_size + 1));
	if (temp == NULL)
		return (-1);
	i = 0;
	while (i < max_size)
		temp[i++] = ' ';
	temp[i] = '\0';
	fill_converted_ptr(target, temp, op, t_len);
	if (ft_stradd(res, temp, max_size) < 0)
		return (-1);
	return (1);
}