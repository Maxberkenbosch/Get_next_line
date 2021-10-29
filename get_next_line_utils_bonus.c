#include "get_next_line.h"
char	*ft_substr(char *s, unsigned int start, size_t len, int freedom)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	if (freedom)
		free(s);
	return (str);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*ft_memmove(void *dst, void *src, size_t len)
{
	char	*dst1;
	char	*src1;
	size_t	i;

	i = 0;
	dst1 = (void *)dst;
	src1 = (void *)src;
	if (!dst1 && !src1)
		return (0);
	if (dst1 > src1)
	{
		while (len > 0)
		{
			len--;
			dst1[len] = src1[len];
		}
	}
	while (i < len)
	{
		dst1[i] = src1[i];
		i++;
	}
	return ((void *)dst1);
}

char	*ft_strjoin(char *temp_str, char *buf)
{
	char	*str;
	int		l1;
	int		l2;

	if (!temp_str)
	{
		temp_str = malloc(1 * sizeof(char));
		temp_str[0] = '\0';
	}
	if (!temp_str || !buf)
		return (0);
	l1 = ft_strlen((char *)temp_str);
	l2 = ft_strlen((char *)buf);
	str = malloc((l1 + l2 + 1) * sizeof(char));
	if (!str)
		return (0);
	ft_memmove(str, (char *)temp_str, l1);
	ft_memmove(str + l1, (char *)buf, l2);
	str[l1 + l2] = '\0';
	free(temp_str);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char	*s1;

	s1 = (char *)s;
	if (!s)
		return (0);
	if (c == '\0')
	{
		while (*s1)
			s1++;
		return (s1);
	}
	while (*s1)
	{
		if (*s1 == (unsigned char)c)
			return (s1);
		s1++;
	}
	return (0);
}
