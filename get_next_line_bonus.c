#include "get_next_line.h"

char    *ft_read(int fd, char *str)
{
    char    *buff;
    int     bytes;
    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buff)
        return (NULL);
    bytes = 1;
    while (!ft_strchr(str, '\n') && bytes != 0)
    {
        bytes = read(fd, buff, BUFFER_SIZE);
        if (bytes == -1)
        {
            free(buff);
            return (NULL);
        }
        buff[bytes] = '\0';
        str = ft_strjoin(str, buff);
    }
    free(buff);
    return (str);
}

char    *get_next_line(int fd)
{
    char        *line;
    static char *str[4096];

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    str[fd] = ft_read(fd, str[fd]);
    if (!str[fd])
        return (NULL);
    line = ft_line(str[fd]);
    str[fd] = ft_next_str(str[fd]);
    return (line);
}

/*int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/