#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*sc1;
	const unsigned char	*sc2;

	sc1 = s1;
	sc2 = s2;
	while (n--)
	{
		if (*sc1 != *sc2)
			return (*sc1 - *sc2);
		sc1++;
		sc2++;
	}
	return (0);
}
