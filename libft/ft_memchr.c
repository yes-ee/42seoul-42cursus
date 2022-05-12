void *ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t				i;

	p = (unsigned char *)s;
	while (i < n)
	{
		if (*p == (unsigned char)c)
			return (p);
		p++;
		i++;
	}
	return (0);
}
