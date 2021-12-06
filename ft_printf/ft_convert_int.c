#include "ft_printf.h"

int	ft_digit(int target)
{
	int	digit;
	int	cnt;

	digit = 1;
	cnt = 1;
	while ((target / (digit * 10)) != 0)
	{
		digit *= 10;
		cnt++;
	}
	return (cnt);
}

static void	fill_converted_int(int target, char *temp, t_info op)
{
	//max_size 필요.
	// -, +, ' '
	// ., 0, width

}

// flag 를 고려해서 max_size 계산.
// 부호의 출력 여부(+, 출력 인자가 음수), 공백 출력 여부(' ' -> 부호가 없는 경우에만 영향 있음.), 출력 인자의 길이, width, precision

// 내부에 직접적으로 들어가는 친구의 길이를 계산
// precision, +, 실제 출력 인자의 길이, -    --> 이 flag들을 이용해서 start index를 계산, 출력하도록 함.
// precision이 들어오면 0 flag는 먹히지 않음.

int	get_max_size(t_info op, int target)
{

}

int	convert_int(t_result *res, t_info op, va_list ap)
{
	char	*temp;
	int		target;
	int		t_len;
	int		max_size;
	int		i;

	// target의 length 계산
	t_len = ft_digit(target);
	if (target < 0)
	{
		max_size = get_max(op.width, op.precision + 1, t_len + 1);
		op.minus = 1;	// 부호를 출력하도록 함.
	}
	else
		max_size = get_max(op.width, op.precision, t_len);
	temp = (char *)malloc(sizeof(char) * (max_size + 1));
	if (temp == NULL)
		return (-1);
	while (i < max_size)
		temp[i++] = ' ';
	temp[i] = '\0';
	fill_converted_int(target, temp, op);
	if (ft_stradd(res, temp, max_size) < 0)
		return (-1);
	return (1);
}