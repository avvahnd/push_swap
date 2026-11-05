#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	i;

	i = 0;
	if (dsize == 0)
		return (ft_strlen(src));
	while (src[i] && --dsize)
		*dst++ = src[i++];
	*dst = '\0';
	return (ft_strlen(src));
}
