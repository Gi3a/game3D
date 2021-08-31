
int	_atoi(const char *str)
{
	int					sign;
	unsigned long int	number;

	sign = 1;
	number = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	if (number > 9223372036854775807 && sign == 1)
		return (-1);
	if (number - 1 > 9223372036854775807 && sign == -1)
		return (0);
	return (number * sign);
}
