size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[i] != '\0')
	{
		i++;
		len++;
	}
	i = 0;
	while (i + 1 < size && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (i + 1== size || src[i] == '\0')
		dest[i] = '\0';
	return (len);
}
