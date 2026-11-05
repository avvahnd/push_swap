#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*sc;

	if (!s)
		return (NULL);
	sc = s;
	while (*s)
		s++;
	while (s != sc)
	{
		if ((unsigned char) *s == (unsigned char)c)
			return ((char *)s);
		s--;
	}
	if ((unsigned char) *s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
