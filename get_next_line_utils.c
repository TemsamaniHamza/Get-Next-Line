#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;
	char	ss;

	ss = (char)c;
	i = 0;
	str = (char *)s;
	while (str[i] != '\0')   
	{
		if (str[i] == ss)
			return (&str[i]);
		i++;
	}
	if (str[i] == '\0' && str[i] == ss)
		return (&str[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*str;
	size_t	j;

	i = 0;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s1)
		return (NULL);
	str = ((char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char)));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
