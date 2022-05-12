void *ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char *s;

	if (dest == src || n == 0)
		return (0);
	if (dest < src)
	{
		d = (unsigned char *)dest;
		s = (unsigned char *)src;
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d = (unsigned char *)dest + n - 1;
		s = (unsigned char *)src + n - 1;
		while (n--)
			*d-- = *s--;
	}
	return (dest);
}
