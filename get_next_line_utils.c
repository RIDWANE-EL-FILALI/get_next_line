#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}

char *ft_line(char *str)
{
    int i;
    char *tab;
    
    i = 0;
    if (!str[i])
        return (NULL);
    while (str[i] && str[i] != '\n')
        i++;
    tab = (char *)malloc(sizeof(char) * (i + 2));
    if(!tab)
        return (NULL);
    i = 0;
    while (str[i] && str[i] != '\n')
    {
        tab[i] = str[i];
        i++;
    }
    if (str[i] == '\n')
    {
        tab[i] = str[i];
        i++;
    }
    tab[i] = '\0';
    return (tab);
}

char *ft_next_str(char *str)
{
    int i;
    int j;
    char *tab;

    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    if (!str[i])
    {
        free(str);
        return (NULL);
    }
    tab = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
    if (!tab)
        return (NULL);
    i++;
    j = 0;
    while (str[i])
        tab[j++] = str[i++];
    tab[j] = '\0';
    free(str);
    return (tab);
}