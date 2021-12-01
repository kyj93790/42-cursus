int	convert_string(t_result *res, t_info op, va_list ap)
{
	char	target;

	target = va_arg(ap, char *);
	if (target == NULL)
		target = "(null)";
	max_size = get_max(op.width, op.
}