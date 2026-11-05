#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*needle;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	needle = malloc((len + 1) * sizeof(char));
	if (!needle)
		return (NULL);
	i = 0;
	while (i < len)
	{
		needle[i] = s[start + i];
		i++;
	}
	needle[i] = '\0';
	return (needle);
}
