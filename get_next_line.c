#include "get_next_line.h"

char *ft_read(int fd, char *str)
{
    char *buff;
    int bytes;
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

char *get_next_line(int fd)
{
    char *line;
    static char *str;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    str = ft_read(fd, str);
    if (!str)
        return (NULL);
    line = ft_line(str);
    str = ft_next_str(str);
    return (line);
}

/*int	main(void)
{
	int fd;
    char *tab;

    fd = open("test.txt", O_RDONLY);
    tab = get_next_line(fd);
    printf("%s", tab);
    free(tab);
    tab = get_next_line(fd);
    printf("%s", tab);
    tab = get_next_line(fd);
    printf("%s", tab);
    tab = get_next_line(fd);
    printf("%s", tab);
    close(fd);
	return (0);
}*/
