static int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *p1;
	unsigned char *p2;
	size_t				i;

	i = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

static size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

char *ft_strnstr(const char * big, const char *little, size_t len)
{
	size_t	blen;
	size_t	llen;
	size_t	n;

	if (*little == '\0')
		return ((char *)big);
	blen = ft_strlen(big);
	llen = ft_strlen(little);
	if (blen < llen || len < llen)
		return (0);
	if (blen > len)
		n = len;
	else
		n = blen;
	while (n >= llen)
	{
		if (ft_memcmp(big, little, llen) == 0)
			return ((char *)big);
		big++;
		n--;
	}
	return (0);
}