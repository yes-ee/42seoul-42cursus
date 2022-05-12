static int	change_num_minus(int minus, int num)
{
	if (num != 0)
	{
		if (minus % 2 == 1)
		{
			if (num != -2147483648)
				num *= -1;
		}
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	num;

	i = 0;
	minus = 0;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	num = change_num_minus(minus, num);
	return (num);
}
