char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	char	*l;
	int 	check;

	temp = s;
	check = 0;
	while (*temp != '\0')
	{
		if (*temp == c)
		{
			l = temp;
			check = 1;
		}
		temp++;
	}
	if (check == 1)
		return (l);
	return (0);
}
