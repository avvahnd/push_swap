#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*sc;

	sc = s;
	while (n--)
	{
		if (*sc == (unsigned char)c)
			return ((void *)sc);
		sc++;
	}
	return (NULL);
}
