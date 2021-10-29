#include "get_next_line.h"
static char	*ft_reader(char *temp, int fd);

char		*ft_strdup(const char *s1);

char	*get_next_line(int fd)
{
	int			i;
	static char	*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	temp = ft_reader(temp, fd);
	if (!temp || temp[0] == 0)
	{
		free(temp);
		temp = NULL;
		return (NULL);
	}
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	line = ft_substr(temp, 0, (i + 1), 0);
	temp = ft_substr(temp, (i + 1), (ft_strlen(temp) - i), 1);
	return (line);
}

static char	*ft_reader(char *temp, int fd)
{
	char	*buf;
	int		read_return;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	read_return = 1;
	while (!ft_strchr(temp, '\n') && read_return != 0)
	{
		read_return = read(fd, buf, BUFFER_SIZE);
		if (read_return == -1)
		{
			free(buf);
			return (0);
		}
		buf[read_return] = '\0';
		if (!temp)
			temp = ft_strdup(buf);
		else
			temp = ft_strjoin(temp, buf);
	}
	free(buf);
	return (temp);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		l;

	l = ft_strlen((char *)s1) + 1;
	ptr = malloc(sizeof(char) * l);
	if (!ptr)
		return (0);
	ft_memmove(ptr, (char *)s1, l);
	return (ptr);
}
