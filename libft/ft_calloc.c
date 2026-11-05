#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	check;

	if (count != 0 && size > (size_t)-1 / count)
		return (NULL);
	check = count * size;
	if (check == 0)
		check = 1;
	ptr = malloc(check);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, check);
	return (ptr);
}
