#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int ft_strchr(const char *s, int c)
{
    size_t i;

    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == (char)c)
            return 1;
        i++;
    }
    if (s[i] == '\0' && s[i] == (char)c)
        return 1;
    return 0;
}


char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*str;
	size_t	j;

	i = 0;
	if (!s1)
		s1 = "";
	if (!s2)
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
	// free(s2);
	str[i] = '\0';
	return (str);
}

/* char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*str;
	size_t	j;
	size_t	k;
	i = 0;
	if (!s1)
	{
		s1 = malloc(1 + ft_strlen(s2));
		if (!s1)
			return NULL;
		s1[ft_strlen(s1)] = '\0';
	}
	if (!s2)
		return (NULL);
	k  = ft_strlen(s1);
	while (s1[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	printf("%s", s1);
	// free(s2);
	return (s1);
} */

