char	*ft_strchr(const char *s, int c)
{
	char	*temp;

	temp = s;
	while (*temp != '\0')
	{
		if (*temp == c)
			return (temp);
		temp++;
	}
	return (0);
}