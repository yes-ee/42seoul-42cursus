#include "libft.h"

static void	ft_bzero(void *s, size_t n)
{
	size_t				i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)s;
	while (i < n)
	{
		temp[i] = 0;
		i++;
	}
}

void *calloc(size_t nmemb, size_t size)
{
	
}