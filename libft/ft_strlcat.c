#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dsize;
	size_t	ssize;
	size_t	i;

	dsize = 0;
	while (dsize < size && dst[dsize])
		dsize++;
	ssize = 0;
	while (src[ssize])
		ssize++;
	if (size == dsize)
		return (dsize + ssize);
	i = 0;
	while (src[i] && dsize + i < size - 1)
	{
		dst[dsize + i] = src[i];
		i++;
	}
	dst[dsize + i] = '\0';
	return (dsize + ssize);
}
