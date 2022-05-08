void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*temp;

	i = 0;
	while (i < n)
	{
		if (*temp == '\0')
			return (s);
		temp[i] = c;
		i++;
	}
	return (s);
}